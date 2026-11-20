/*
 * File:   Receiver_PWM.h
 * Author: T00904
 * Comments:
 * Revision history: V1.0
 */

#include "LED.h"
#include <stdint.h>

#ifndef RECEIVER_PWM_H
#define RECEIVER_PWM_H
// 1. 定義單一 公開介面（全部使用 const 指標，不佔用 RAM，也無 state 暴露風險）
typedef struct {
  uint8_t (*const get)(void);
} Get_t;

typedef struct {
  Get_t pos;
  Get_t drl;
  Get_t loBeam;
  Get_t hiBeam;
  Get_t turnLeft;
  Get_t turnRight;
} Gets_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} Data_t;

// 宣告變數
extern const Data_t fCRC;
extern const Gets_t Receiver;

// 宣告函數
extern void Receiver_FrameData(void);

#endif /* RECEIVER_PWM_H */
