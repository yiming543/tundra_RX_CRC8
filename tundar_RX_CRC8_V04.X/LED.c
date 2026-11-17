#include "LED.h"
#include "mcc_generated_files/pin_manager.h"

#define LED_ON (1U)
#define LED_OFF (0U)

// 2. 【真正的 Private 狀態變數】僅佔用 6 Bytes RAM，外部完全無法直接修改
static uint8_t led_states[LED_COUNT] = {
    LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF};

// 3. 內部硬體操作函式（加上 static 隱藏於此檔案內部）
static void POS_ON(void) {
  if (led_states[POS] == LED_OFF) {
    LED1_SetHigh();
    led_states[POS] = LED_ON;
  }
}

static void POS_OFF(void) {
  if (led_states[POS] != LED_OFF) {
    LED1_SetLow();
    led_states[POS] = LED_OFF;
  }
}

static uint8_t LED_POS_IS_ON(void) {
  return led_states[POS];
}

static void DRL_ON(void) {
  if (led_states[DRL] == LED_OFF) {
    LED2_SetHigh();
    led_states[DRL] = LED_ON;
  }
}

static void DRL_OFF(void) {
  if (led_states[DRL] != LED_OFF) {
    LED2_SetLow();
    led_states[DRL] = LED_OFF;
  }
}

static uint8_t LED_DRL_IS_ON(void) {
  return led_states[DRL];
}

static void LO_BEAM_ON(void) {
  if (led_states[LO_BEAM] == LED_OFF) {
    LED3_SetHigh();
    led_states[LO_BEAM] = LED_ON;
  }
}

static void LO_BEAM_OFF(void) {
  if (led_states[LO_BEAM] != LED_OFF) {
    LED3_SetLow();
    led_states[LO_BEAM] = LED_OFF;
  }
}

static uint8_t LED_LO_BEAM_IS_ON(void) {
  return led_states[LO_BEAM];
}

static void HI_BEAM_ON(void) {
  if (led_states[HI_BEAM] == LED_OFF) {
    LED4_SetHigh();
    led_states[HI_BEAM] = LED_ON;
  }
}

static void HI_BEAM_OFF(void) {
  if (led_states[HI_BEAM] != LED_OFF) {
    LED4_SetLow();
    led_states[HI_BEAM] = LED_OFF;
  }
}

static uint8_t LED_HI_BEAM_IS_ON(void) {
  return led_states[HI_BEAM];
}

static void TURN_LEFT_ON(void) {
  if (led_states[TURN_LEFT] == LED_OFF) {
    LED5_SetHigh();
    led_states[TURN_LEFT] = LED_ON;
  }
}

static void TURN_LEFT_OFF(void) {
  if (led_states[TURN_LEFT] != LED_OFF) {
    LED5_SetLow();
    led_states[TURN_LEFT] = LED_OFF;
  }
}

static uint8_t LED_TURN_LEFT_IS_ON(void) {
  return led_states[TURN_LEFT];
}

static void TURN_RIGHT_ON(void) {
  if (led_states[TURN_RIGHT] == LED_OFF) {
    LED6_SetHigh();
    led_states[TURN_RIGHT] = LED_ON;
  }
}

static void TURN_RIGHT_OFF(void) {
  if (led_states[TURN_RIGHT] != LED_OFF) {
    LED6_SetLow();
    led_states[TURN_RIGHT] = LED_OFF;
  }
}

static uint8_t LED_TURN_RIGHT_IS_ON(void) {
  return led_states[TURN_RIGHT];
}

// 4. 編譯期靜態初始化物件（存放於 Flash 唯讀區）
LED_t const led[LED_COUNT] = {
    [POS] = {.on = POS_ON, .off = POS_OFF, .is_on = LED_POS_IS_ON},
    [DRL] = {.on = DRL_ON, .off = DRL_OFF, .is_on = LED_DRL_IS_ON},
    [LO_BEAM] = {.on = LO_BEAM_ON, .off = LO_BEAM_OFF, .is_on = LED_LO_BEAM_IS_ON},
    [HI_BEAM] = {.on = HI_BEAM_ON, .off = HI_BEAM_OFF, .is_on = LED_HI_BEAM_IS_ON},
    [TURN_LEFT] = {.on = TURN_LEFT_ON, .off = TURN_LEFT_OFF, .is_on = LED_TURN_LEFT_IS_ON},
    [TURN_RIGHT] = {.on = TURN_RIGHT_ON, .off = TURN_RIGHT_OFF, .is_on = LED_TURN_RIGHT_IS_ON}};

// 5. 開機硬體狀態同步函式
void LED_Init(void) {
   led[POS].off();
   led[DRL].off();
   led[LO_BEAM].off();
   led[HI_BEAM].off();
   led[TURN_LEFT].off();
   led[TURN_RIGHT].off();
}