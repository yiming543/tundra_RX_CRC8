/*
 * File:   Warning_ignored.c
 * Author: T00904
 *
 * Created on November 13, 2026, 10:30 AM
 */

#include <stdint.h>
//for Clear_No_Call_Warning
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "mcc_generated_files/tmr1.h"

// 消除未呼叫警告 假裝有使用這些函數

void Clear_No_Call_Warning(void) {
    uint8_t i = 0U;
    if (i == 1U) {
        PIN_MANAGER_IOC();
    } else if (i == 2U) {
        uint8_t tmp = TMR0_ReadTimer();
        TMR0_WriteTimer(0U);
        TMR0_Reload();
    } else if (i == 3U) {
        TMR1_StartTimer();
        TMR1_StopTimer();
        uint16_t tmp1 = TMR1_ReadTimer();
        TMR1_WriteTimer(0U);
        TMR1_Reload();
        TMR1_StartSinglePulseAcquisition();
        bool tmp_bit = TMR1_CheckGateValueStatus();
        bool tmp_bit1 = TMR1_HasOverflowOccured();
    } else {
    }
}