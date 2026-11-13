/*
 * File:   timer.c
 * Author: T00904
 *
 * Created on November 13, 2026, 10:22 AM
 */
#include <stdint.h>

volatile uint8_t fSignalFail = 0U;
volatile uint16_t T10MS_CNT = 0; // 單位:10ms

void TMR0_EvenHandler(void) {
  T10MS_CNT++;
  if (T10MS_CNT >= 200U) { // 2000ms
    T10MS_CNT = 0U;
    fSignalFail = 1U; // 信號失效
  }
}