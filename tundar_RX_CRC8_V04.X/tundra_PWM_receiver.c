/*
 * File:   Receiver_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 5:30 PM
 */
#include "tundra_PWM_receiver.h"
#include "mcc_generated_files/pin_manager.h"
#include "timer.h"
#include "tundra_crc8.h"

#define ON (1U)
#define OFF (0U)

#define UART_LEVEL (21U)
#define data_length (8U)

#define D2_POS_MASK (2U)
#define D2_DRL_MASK (3U)
#define D2_LO_BEAM_MASK (4U)
#define D2_HI_BEAM_MASK (5U)

#define D3_TURN_LEFT_MASK (5U)
#define D3_TURN_RIGHT_MASK (6U)
#define BIT_SET(number, n) ((number) |= (1U << (n)))
#define BIT_CLR(number, n) ((number) &= ~(1U << (n)))
#define READ_BIT(number, n) ((uint8_t)(!!((number) & (1U << (n)))))
#define READ_SIGNAL_STATE READ_BIT(flag, fSIGNAL_STATE)
#define READ_UART_PIN READ_BIT(flag, fUART_PIN)

#define FALLING_EDGE_SET (0x04)
#define RISEING_EDGE_SET (0x05)
// static flag define
#define fSIGNAL_STATE (0U)
#define fUART_PIN (1U)

typedef enum {
  STEP_ID = 0U,
  STEP_LENGHT,
  STEP_DATA,
  STEP_CRC,
} STEP_t;

typedef enum {
  UART_START = 0U,
  UART_DATA,
  UART_STOP,
} UART_t;

typedef struct {
  uint8_t ID;
  uint8_t LENGHT;
  uint8_t DATA[8];
  uint8_t CRC;
} Frame_t;

//物件屬性
static uint8_t fCRC_OK = 0U;
static uint8_t D2 = 0U;
static uint8_t D3 = 0U;
static Frame_t tundra_data = {
    .ID = 0U,
    .LENGHT = 0U,
    .DATA = {0U},
    .CRC = 0U};

//物件方法
static uint8_t BIT_POS(void) {
  return READ_BIT(D2, D2_POS_MASK);
}

static uint8_t BIT_DRL(void) {
  return READ_BIT(D2, D2_DRL_MASK);
}

static uint8_t BIT_LO_BEAM(void) {
  return READ_BIT(D2, D2_LO_BEAM_MASK);
}

static uint8_t BIT_HI_BEAM(void) {
  return READ_BIT(D2, D2_HI_BEAM_MASK);
}

static uint8_t BIT_TURN_LEFT(void) {
  return READ_BIT(D3, D3_TURN_LEFT_MASK);
}

static uint8_t BIT_TURN_RIGHT(void) {
  return READ_BIT(D3, D3_TURN_RIGHT_MASK);
}

//物件
Get_t const Receiver[LED_COUNT] = {
    [POS] = {.get = BIT_POS},
    [DRL] = {.get = BIT_DRL},
    [LO_BEAM] = {.get = BIT_LO_BEAM},
    [HI_BEAM] = {.get = BIT_HI_BEAM},
    [TURN_LEFT] = {.get = BIT_TURN_LEFT},
    [TURN_RIGHT] = {.get = BIT_TURN_RIGHT},
};

//物件方法
static uint8_t fCRC_GET(void) {
  return fCRC_OK;
}

static void fCRC_SET(uint8_t data) {
  fCRC_OK = data;
}

//物件
Data_t const fCRC = {
    .get = fCRC_GET,
    .set = fCRC_SET,
};

static uint8_t byte_ready = 0U;
static uint8_t rx_data = 0U;

void ECCP3_CallBack(uint16_t capturedValue) {
  uint16_t pluse_width_LO = 0U;
  static UART_t uart_state = UART_START;
  static uint8_t bitCnt = 0U;

  static uint16_t last_capture = 0U;
  static uint8_t flag = 0U;
  static uint8_t uart_data = 0U;
  uint16_t width = 0U;
  uint16_t now = 0U;

  now = capturedValue;
  if (READ_SIGNAL_STATE == LOW) {
    // 有下降緣進來
    last_capture = now;
    CCP3CON = RISEING_EDGE_SET; // 設成捕捉上升緣
    BIT_SET(flag, fSIGNAL_STATE);
  } else {
    // 有上升進來 → 計算低電平寬度 (含溢位補償)
    if (now >= last_capture) {
      width = now - last_capture;
    } else {
      width = (uint16_t)now - last_capture; // 溢位補償
    }

    pluse_width_LO = width >> 3U; // Timer1 tick=0.125µs to 1us
    CCP3CON = FALLING_EDGE_SET;   // 設成捕捉下降緣
    BIT_CLR(flag, fSIGNAL_STATE);

    // PWM 變成 UART 19200 baud
    if (pluse_width_LO < UART_LEVEL) {
      UART_TX_LAT = ON;
      BIT_SET(flag, fUART_PIN);
    } else {
      UART_TX_LAT = OFF;
      BIT_CLR(flag, fUART_PIN);
    }

    switch (uart_state) {
    case UART_START:
      // 等待 Start bit (必須是長低電平)
      if (READ_UART_PIN == LOW) {
        uart_state = UART_DATA;
        bitCnt = 0U;
        uart_data = 0U;
      }
      break;

    case UART_DATA:
      if (READ_UART_PIN == HIGH) {
        //LSB(Least Significant Bit) First
        BIT_SET(uart_data, bitCnt);
      }

      bitCnt++;
      if (bitCnt > 7U) {
        uart_state = UART_STOP;
        bitCnt = 0U;
      }
      break;

    case UART_STOP:
      // 等待 Stop bit (必須是短低電平)
      if (READ_UART_PIN == HIGH) {
        byte_ready = 1U; // 1:收到完整 byte
        rx_data = uart_data;
      }
      uart_data = 0U;
      uart_state = UART_START; // 回到等待 Start bit
      break;

    default:
      uart_state = UART_START;
      byte_ready = 0U; // 1:收到完整 byte 0:資料未完成
      uart_data = 0U;
      break;
    }
  }
}

void Receiver_FrameData(void) {
  static uint8_t dataCnt = 0U;
  static STEP_t step = STEP_ID;

  if (byte_ready != 0U) {
    byte_ready = 0U;

    switch (step) {
    case STEP_ID:
      if (rx_data == 0xC8U) {
        tundra_data.ID = rx_data;
        step = STEP_LENGHT;
      } else {
        step = STEP_ID;
      }
      break;
    case STEP_LENGHT:
      if (rx_data == 0x8BU) {
        tundra_data.LENGHT = rx_data;
        dataCnt = 0U;
        step = STEP_DATA;
      } else {
        step = STEP_ID;
      }
      break;
    case STEP_DATA:
      tundra_data.DATA[dataCnt] = rx_data;
      if (++dataCnt > 7U) {
        dataCnt = 0;
        step = STEP_CRC;
      }
      break;
    case STEP_CRC:
      if (rx_data == calculate_crc8(&tundra_data.DATA[0], data_length)) {
        fCRC_OK = 1U; // CRC檢查成功
        tundra_data.CRC = rx_data;
        D2 = tundra_data.DATA[0];
        D3 = tundra_data.DATA[1];
        // 重置信號失效計數器
        tmr0.t10MS_CNT.set(0U);
        tmr0.fSIGNAL_FAIL.set(0U);
      }
      step = STEP_ID;
      break;

    default:
      step = STEP_ID;
      break;
    }
  }
}
