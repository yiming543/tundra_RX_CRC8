#include "LED.h"
#include "mcc_generated_files/pin_manager.h"

#define LED_ON (1U)
#define LED_OFF (0U)

typedef struct {
  uint8_t pos;
  uint8_t drl;
  uint8_t loBeam;
  uint8_t hiBeam;
  uint8_t turnLeft;
  uint8_t turnRight;
} ledStates_t;

// 2. 【真正的 Private 狀態變數】僅佔用 6 Bytes RAM，外部完全無法直接修改
static ledStates_t led_states = {
    .pos = LED_OFF,
    .drl = LED_OFF,
    .loBeam = LED_OFF,
    .hiBeam = LED_OFF,
    .turnLeft = LED_OFF,
    .turnRight = LED_OFF,
};

// 3. 內部硬體操作函式（加上 static 隱藏於此檔案內部）
static void POS_ON(void) {
  if (led_states.pos == LED_OFF) {
    LED1_SetHigh();
    led_states.pos = LED_ON;
  }
}

static void POS_OFF(void) {
  if (led_states.pos != LED_OFF) {
    LED1_SetLow();
    led_states.pos = LED_OFF;
  }
}

static uint8_t LED_POS_IS_ON(void) {
  return led_states.pos;
}

static void DRL_ON(void) {
  if (led_states.drl == LED_OFF) {
    LED2_SetHigh();
    led_states.drl = LED_ON;
  }
}

static void DRL_OFF(void) {
  if (led_states.drl != LED_OFF) {
    LED2_SetLow();
    led_states.drl = LED_OFF;
  }
}

static uint8_t LED_DRL_IS_ON(void) {
  return led_states.drl;
}

static void LO_BEAM_ON(void) {
  if (led_states.loBeam == LED_OFF) {
    LED3_SetHigh();
    led_states.loBeam = LED_ON;
  }
}

static void LO_BEAM_OFF(void) {
  if (led_states.loBeam != LED_OFF) {
    LED3_SetLow();
    led_states.loBeam = LED_OFF;
  }
}

static uint8_t LED_LO_BEAM_IS_ON(void) {
  return led_states.loBeam;
}

static void HI_BEAM_ON(void) {
  if (led_states.hiBeam == LED_OFF) {
    LED4_SetHigh();
    led_states.hiBeam = LED_ON;
  }
}

static void HI_BEAM_OFF(void) {
  if (led_states.hiBeam != LED_OFF) {
    LED4_SetLow();
    led_states.hiBeam = LED_OFF;
  }
}

static uint8_t LED_HI_BEAM_IS_ON(void) {
  return led_states.hiBeam;
}

static void TURN_LEFT_ON(void) {
  if (led_states.turnLeft == LED_OFF) {
    LED5_SetHigh();
    led_states.turnLeft = LED_ON;
  }
}

static void TURN_LEFT_OFF(void) {
  if (led_states.turnLeft != LED_OFF) {
    LED5_SetLow();
    led_states.turnLeft = LED_OFF;
  }
}

static uint8_t LED_TURN_LEFT_IS_ON(void) {
  return led_states.turnLeft;
}

static void TURN_RIGHT_ON(void) {
  if (led_states.turnRight == LED_OFF) {
    LED6_SetHigh();
    led_states.turnRight = LED_ON;
  }
}

static void TURN_RIGHT_OFF(void) {
  if (led_states.turnRight != LED_OFF) {
    LED6_SetLow();
    led_states.turnRight = LED_OFF;
  }
}

static uint8_t LED_TURN_RIGHT_IS_ON(void) {
  return led_states.turnRight;
}

// 4. 編譯期靜態初始化物件（存放於 Flash 唯讀區）
const LEDs_t led = {
    .pos = {.on = POS_ON, .off = POS_OFF, .is_on = LED_POS_IS_ON},
    .drl = {.on = DRL_ON, .off = DRL_OFF, .is_on = LED_DRL_IS_ON},
    .loBeam = {.on = LO_BEAM_ON, .off = LO_BEAM_OFF, .is_on = LED_LO_BEAM_IS_ON},
    .hiBeam = {.on = HI_BEAM_ON, .off = HI_BEAM_OFF, .is_on = LED_HI_BEAM_IS_ON},
    .turnLeft = {.on = TURN_LEFT_ON, .off = TURN_LEFT_OFF, .is_on = LED_TURN_LEFT_IS_ON},
    .turnRight = {.on = TURN_RIGHT_ON, .off = TURN_RIGHT_OFF, .is_on = LED_TURN_RIGHT_IS_ON}};

// 5. 開機硬體狀態同步函式
void LED_Init(void) {
  led.pos.off();
  led.drl.off();
  led.loBeam.off();
  led.hiBeam.off();
  led.turnLeft.off();
  led.turnRight.off();
  led.pos.is_on();
  led.drl.is_on();
  led.loBeam.is_on();
  led.hiBeam.is_on();
  led.turnLeft.is_on();
  led.turnRight.is_on();
}