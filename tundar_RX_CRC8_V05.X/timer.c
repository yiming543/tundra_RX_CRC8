/*
 * File:   timer.c
 * Author: T00904
 *
 * Created on November 13, 2026, 10:22 AM
 */
#include "timer.h"
#include "LED.h"

//物件屬性
static  uint8_t fSignalFail = 0U;
static  uint16_t T10MS_CNT = 0; // 單位:10ms

//物件方法
static void fSIGNAL_FAIL_SET(uint8_t data) {
  fSignalFail = data;
}

static uint8_t fSIGNAL_FAIL_GET(void) {
  return fSignalFail;
}

static void T10MS_CNT_SET(uint16_t data) {
  T10MS_CNT = data;
}

//物件
TMR0_t const tmr0 = {
    .fSIGNAL_FAIL = {.set = fSIGNAL_FAIL_SET,.get =fSIGNAL_FAIL_GET},
    .t10MS_CNT = {.set = T10MS_CNT_SET},
};

void TMR0_EvenHandler(void) {
  T10MS_CNT++;
  if (T10MS_CNT >= 200U) { // 2000ms
    T10MS_CNT = 0U;
    fSignalFail = 1U; // 信號失效
  }
}


