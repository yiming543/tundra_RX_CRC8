#ifndef LED_H
#define LED_H

#include <stdint.h>

// 範例
// led[POS].on();
// led[POS].off();
// led[POS].is_on();

// 1. 定義單一 LED 公開介面（全部使用 const 指標，不佔用 RAM，也無 state 暴露風險）
typedef struct {
  void (*const on)(void);
  void (*const off)(void);
  uint8_t (*const is_on)(void);
} LED_t;

typedef enum {
  POS = 0,
  DRL,
  LO_BEAM,
  HI_BEAM,
  TURN_LEFT,
  TURN_RIGHT,
  LED_COUNT,
} Led_t;

// 初始化函數
// 3. 宣告唯讀的全域物件（存放於 Flash 中）
extern const LED_t led[LED_COUNT];

// 4. 初始化函式（僅用於確保開機時硬體腳位處於已知的關閉狀態）
void LED_Init(void);

#endif // LED_H
