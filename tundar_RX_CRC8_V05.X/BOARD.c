#include "BOARD.h"

#include "LED.h"
#include "Warning_ignored.h"
#include "mcc_generated_files/tmr0.h"
#include "timer.h"
#include "tundra_PWM_receiver.h"

#define ON (1U)
#define OFF (0U)

void board_init(void) {
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  LED_Init();
  Clear_No_Call_Warning();
}

void dataSetLed(void) {

  // CRC檢查
  if (fCRC.get() != 0U) {
    fCRC.set(0U); // fCRC_OK = 0U;
    //  POS
    if (Receiver.pos.get() == ON) {
      led.pos.on();
    } else {
      led.pos.off();
    }
    // DRL
    if (Receiver.drl.get() == ON) {
      led.drl.on();
    } else {
      led.drl.off();
    }
    // HIBEAM
    if (Receiver.loBeam.get() == ON) {
      led.loBeam.on();
    } else {
      led.loBeam.off();
    }
    // LOBEAM
    if (Receiver.hiBeam.get() == ON) {
      led.hiBeam.on();
    } else {
      led.hiBeam.off();
    }
    // 左方向
    if (Receiver.turnLeft.get() == ON) {
      led.turnLeft.on();
    } else {
      led.turnLeft.off();
    }
    // 右方向
    if (Receiver.turnRight.get() == ON) {
      led.turnRight.on();
    } else {
      led.turnRight.off();
    }
  }
}

void CheckSignalFail(void) {
  if (tmr0.fSIGNAL_FAIL.get() == 1U) {
    tmr0.fSIGNAL_FAIL.set(0U);
    // 信號失效處理 亮近燈和POS
    led.pos.on();
    led.drl.off();
    led.loBeam.on();
    led.hiBeam.off();
    led.turnLeft.off();
    led.turnRight.off();
  }
}

void board_updata(void) {
  Receiver_FrameData(); // 接收tundra pwm 信號
  dataSetLed();         // 執行動作
  CheckSignalFail();    // 信號失效處理 亮近燈和POS
}
