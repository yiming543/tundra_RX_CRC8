/*
 * File:   Receiver_PWM.h
 * Author: T00904
 * Comments:
 * Revision history: V1.0
 */

#include <stdint.h>
#include "LED.h"

#ifndef RECEIVER_PWM_H
#define RECEIVER_PWM_H
// 1. 定義單一 公開介面（全部使用 const 指標，不佔用 RAM，也無 state 暴露風險）
typedef struct {
  uint8_t (*const get)(void);
} Get_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} Data_t;

// 宣告變數
extern Data_t const fCRC;
extern Get_t const Receiver[LED_COUNT];

//宣告函數
extern void Receiver_FrameData(void);

#endif /* RECEIVER_PWM_H */
