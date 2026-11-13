#include "object_LED.h"
#include "mcc_generated_files/pin_manager.h"

//全域變數
LED_GROUP_t obj_led;

#define ON 1U
#define OFF 0U

static void POS_ON(void) {
  if (obj_led.pos.is_on() == OFF) {
    LED1_SetHigh();
    obj_led.pos.state = 1;
  }
}
static void POS_OFF(void) {
  if (obj_led.pos.is_on() != OFF) {
    LED1_SetLow();
    obj_led.pos.state = 0;
  }
}
static void DRL_ON(void) {
  if (obj_led.drl.is_on() == OFF) {
    LED2_SetHigh();
    obj_led.drl.state = 1;
  }
}
static void DRL_OFF(void) {
  if (obj_led.drl.is_on() != OFF) {
    LED2_SetLow();
    obj_led.drl.state = 0;
  }
}

static void LOBEAM_ON(void) {
  if (obj_led.loBeam.is_on() == OFF) {
    LED3_SetHigh();
    obj_led.loBeam.state = 1;
  }
}

static void LOBEAM_OFF(void) {
  if (obj_led.loBeam.is_on() != OFF) {
    LED3_SetLow();
    obj_led.loBeam.state = 0;
  }
}

static void HIBEAM_ON(void) {
  if (obj_led.hiBeam.is_on() == OFF) {
    LED4_SetHigh();
    obj_led.hiBeam.state = 1;
  }
}

static void HIBEAM_OFF(void) {
  if (obj_led.hiBeam.is_on() != OFF) {
    LED4_SetLow();
    obj_led.hiBeam.state = 0;
  }
}

static void TURN_LEFT_ON(void) {
  if (obj_led.turnLeft.is_on() == OFF) {
    LED5_SetHigh();
    obj_led.turnLeft.state = 1;
  }
}

static void TURN_LEFT_OFF(void) {
  if (obj_led.turnLeft.is_on() != OFF) {
    LED5_SetLow();
    obj_led.turnLeft.state = 0;
  }
}

static void TURN_RIGHT_ON(void) {
  if (obj_led.turnRight.is_on() == OFF) {
    LED6_SetHigh();
    obj_led.turnRight.state = 1;
  }
}

static void TURN_RIGHT_OFF(void) {
  if (obj_led.turnRight.is_on() != OFF) {
    LED6_SetLow();
    obj_led.turnRight.state = 0;
  }
}


static uint8_t LED_POS_IS_ON(void) { return obj_led.pos.state; }
static uint8_t LED_DRL_IS_ON(void) { return obj_led.drl.state; }
static uint8_t LED_LOBEAM_IS_ON(void) { return obj_led.loBeam.state; }
static uint8_t LED_HIBEAM_IS_ON(void) { return obj_led.hiBeam.state; }
static uint8_t LED_TURN_LEFT_IS_ON(void) { return obj_led.turnLeft.state; }
static uint8_t LED_TURN_RIGHT_IS_ON(void) { return obj_led.turnRight.state; }

void LED_init(LED_GROUP_t *obj) {
  //led.state
  obj->pos.is_on = LED_POS_IS_ON;
  obj->drl.is_on = LED_DRL_IS_ON;
  obj->loBeam.is_on = LED_LOBEAM_IS_ON;
  obj->hiBeam.is_on = LED_HIBEAM_IS_ON;
  obj->turnLeft.is_on = LED_TURN_LEFT_IS_ON;
  obj->turnRight.is_on = LED_TURN_RIGHT_IS_ON;
  //led.set
  obj->pos.on = POS_ON;
  obj->pos.off = POS_OFF;
  obj->drl.on = DRL_ON;
  obj->drl.off = DRL_OFF;
  obj->loBeam.on = LOBEAM_ON;
  obj->loBeam.off = LOBEAM_OFF;
  obj->hiBeam.on =  HIBEAM_ON;
  obj->hiBeam.off = HIBEAM_OFF;
  obj->turnLeft.on =  TURN_LEFT_ON;
  obj->turnLeft.off = TURN_LEFT_OFF;
  obj->turnRight.on =  TURN_RIGHT_ON;
  obj->turnRight.off = TURN_RIGHT_OFF;
}