#include "object_BOARD.h"
#include <stdint.h>

#include "Warning_ignored.h"
#include "mcc_generated_files/tmr0.h"
#include "timer.h"
#include "tundra_crc8.h"

#define ON 1U
#define OFF 0U

// #define data_length 8U

#define D2_POS_MASK 2
#define D2_DRL_MASK 3
#define D2_LOBEAM_MASK 4
#define D2_HIBEAM_MASK 5

#define D3_TURN_LEFT_MASK 5
#define D3_TURN_RIGHT_MASK 6

#define BIT_SET(number, n) ((number) |= (1U << (n)))
#define BIT_CLR(number, n) ((number) &= ~(1U << (n)))
#define READ_BIT(number, n) ((uint8_t)(!!((number) & (1U << (n)))))

// 全域變數
BOARD_t board;

void board_init(BOARD_t *obj) {
  obj->led = &obj_led;
}

void obj_init(void) {
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  LED_init(&obj_led);
  board_init(&board);
  Clear_No_Call_Warning();
}

void dataSetLED(void) {

  // CRC檢查
  if (fCRC_OK != 0U) {
    fCRC_OK = 0U;
    //  POS
    if (READ_BIT(D2, D2_POS_MASK) == 1U) {
      board.led->pos.on();
    } else {
      board.led->pos.off();
    }
    // DRL
    if (READ_BIT(D2, D2_DRL_MASK) == 1U) {
      board.led->drl.on();
    } else {
      board.led->drl.off();
    }
    // HIBEAM
    if (READ_BIT(D2, D2_LOBEAM_MASK) == 1U) {
      board.led->loBeam.on();
    } else {
      board.led->loBeam.off();
    }
    // LOBEAM
    if (READ_BIT(D2, D2_HIBEAM_MASK) == 1U) {
      board.led->hiBeam.on();
    } else {
      board.led->hiBeam.off();
    }
    // 左方向
    if (READ_BIT(D3, D3_TURN_LEFT_MASK) == 1U) {
      board.led->turnLeft.on();
    } else {
      board.led->turnLeft.off();
    }

    // 右方向
    if (READ_BIT(D3, D3_TURN_RIGHT_MASK) == 1U) {
      board.led->turnRight.on();
    } else {
      board.led->turnRight.off();
    }
  }
}

void CheckSignalFail(void) {
  if (fSignalFail == 1U) {
    fSignalFail = 0U;
    // 信號失效處理 亮近燈和POS
    board.led->pos.on();
    board.led->drl.off();
    board.led->loBeam.on();
    board.led->hiBeam.off();
    board.led->turnLeft.off();
    board.led->turnRight.off();
  }
}