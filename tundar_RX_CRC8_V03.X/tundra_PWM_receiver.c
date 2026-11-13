/*
 * File:   Receiver_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 5:30 PM
 */
#include "tundra_PWM_receiver.h"
#include "mcc_generated_files/pin_manager.h"
#include "tundra_crc8.h"

extern uint8_t fSignalFail;
extern uint16_t T10MS_CNT; // 單位:10ms

#define UART_LEVEL (21U)
#define data_length (8U)

#define BIT_SET(number, n) ((number) |= (1U << (n)))
#define BIT_CLR(number, n) ((number) &= ~(1U << (n)))
#define READ_BIT(number, n) ((uint8_t)(!!((number) & (1U << (n)))))

// static flag define
#define fEDGE_FALL_GET (0U)
#define DATA_BIT (1U)

typedef enum {
  step_ID = 0,
  step_LENGHT,
  step_DATA,
  step_CRC,
} STEP_t;

typedef enum {
  uart_START = 0,
  uart_DATA,
  uart_STOP,
} UART_t;

// 全域變數
FRAME_t tundra_data;
uint8_t fCRC_OK = 0;
uint8_t D2 = 0;
uint8_t D3 = 0;

uint8_t byte_ready = 0;
uint8_t rx_data = 0;

void ECCP3_CallBack(uint16_t capturedValue) {
  uint16_t pluse_width_LO = 0;
  static UART_t uart_state = uart_START;
  static uint8_t bitCnt = 0;

  static uint16_t last_capture = 0;
  static uint8_t flag = 0;
  static uint8_t uart_data = 0;
  uint16_t width = 0;
  uint16_t now = 0;

  now = capturedValue;
  if (READ_BIT(flag, fEDGE_FALL_GET) == 0U) {
    last_capture = now;
    CCP3CON = 0x05; // 改成上升沿捕捉
    BIT_SET(flag, fEDGE_FALL_GET);
  } else {
    // 上升沿 → 計算低電平寬度 (含溢位補償)
    if (now >= last_capture) {
      width = now - last_capture;
    } else {
      width = (uint16_t)now - last_capture; // 溢位補償
    }

    pluse_width_LO = width >> 3U; // Timer1 tick=0.125µs to 1us
    CCP3CON = 0x04;               // 改成下降沿捕捉
    BIT_CLR(flag, fEDGE_FALL_GET);

    // PWM 變成 UART 19200 baud
    if (pluse_width_LO < UART_LEVEL) {
      UART_TX_LAT = 1;
      BIT_SET(flag, DATA_BIT);
    } else {
      UART_TX_LAT = 0;
      BIT_CLR(flag, DATA_BIT);
    }

    switch (uart_state) {
    case uart_START:
      // 等待 Start bit (必須是長低電平)
      if (READ_BIT(flag, DATA_BIT) == 0U) {
        uart_state = uart_DATA;
        bitCnt = 0;
        uart_data = 0;
      }
      break;

    case uart_DATA:
      if (READ_BIT(flag, DATA_BIT) == 1U) {
        BIT_SET(uart_data, bitCnt);
      }

      bitCnt++;
      if (bitCnt > 7U) {
        uart_state = uart_STOP;
        bitCnt = 0;
      }
      break;

    case uart_STOP:
      // 等待 Stop bit (必須是短低電平)
      if (READ_BIT(flag, DATA_BIT) == 1U) {
        byte_ready = 1U; // 1:收到完整 byte
        rx_data = uart_data;
      }
      uart_data = 0;
      uart_state = uart_START; // 回到等待 Start bit
      break;

    default:
      uart_state = uart_START;
      byte_ready = 0U; // 1:收到完整 byte
      uart_data = 0;
      break;
    }
  }
}

void Receiver_FrameData(void) {
  static uint8_t dataCnt = 0;
  static STEP_t step = step_ID;

  if (byte_ready != 0U) {
    byte_ready = 0;

    switch (step) {
    case step_ID:
      if (rx_data == 0xC8U) {
        tundra_data.ID = rx_data;
        step = step_LENGHT;
      } else {
        step = step_ID;
      }
      break;
    case step_LENGHT:
      if (rx_data == 0x8BU) {
        tundra_data.LENGHT = rx_data;
        dataCnt = 0;
        step = step_DATA;
      } else {
        step = step_ID;
      }
      break;
    case step_DATA:
      tundra_data.DATA[dataCnt] = rx_data;
      if (++dataCnt > 7) {
        dataCnt = 0;
        step = step_CRC;
      }
      break;
    case step_CRC:
      if (rx_data == calculate_crc8(&tundra_data.DATA[0], data_length)) {
        fCRC_OK = 1U; // CRC檢查成功
        tundra_data.CRC = rx_data;
        D2 = tundra_data.DATA[0];
        D3 = tundra_data.DATA[1];
        T10MS_CNT = 0; // 重置信號失效計數器
        fSignalFail = 0U;
      }
      step = step_ID;
      // 清除資料緩衝區
      // tundra_data.ID = 0U;
      // tundra_data.LENGHT = 0U;
      // tundra_data.CRC = 0U;
      // for (uint8_t i = 0U; i < data_length; i++) {
      //   tundra_data.DATA[i] = 0U;
      // }
      break;

    default:
      step = step_ID;
      break;
    }
  }
  
  
}
