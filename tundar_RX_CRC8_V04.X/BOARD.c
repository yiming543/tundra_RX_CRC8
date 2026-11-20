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
    if (Receiver[POS].get() == ON) {
      led[POS].on();
    } else {
      led[POS].off();
    }
    // DRL
    if (Receiver[DRL].get() == ON) {
      led[DRL].on();
    } else {
      led[DRL].off();
    }
    // HIBEAM
    if (Receiver[LO_BEAM].get() == ON) {
      led[LO_BEAM].on();
    } else {
      led[LO_BEAM].off();
    }
    // LOBEAM
    if (Receiver[HI_BEAM].get() == ON) {
      led[HI_BEAM].on();
    } else {
      led[HI_BEAM].off();
    }
    // 左方向
    if (Receiver[TURN_LEFT].get() == ON) {
      led[TURN_LEFT].on();
    } else {
      led[TURN_LEFT].off();
    }
    // 右方向
    if (Receiver[TURN_RIGHT].get() == ON) {
      led[TURN_RIGHT].on();
    } else {
      led[TURN_RIGHT].off();
    }
  }
}

void board_updata(void) {
  Receiver_FrameData(); // 接收tundra pwm 信號
  dataSetLed();         // 執行動作
  CheckSignalFail();    // 信號失效處理 亮近燈和POS
}
