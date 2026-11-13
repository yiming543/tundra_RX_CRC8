/* 
 * File:   timer.h
 * Author: yiming
 * Comments: 
 * Revision history: V1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TIMER_H
#define	TIMER_H

extern volatile uint8_t fSignalFail;
extern volatile uint16_t T10MS_CNT; // 單位:10ms

extern void TMR0_EvenHandler(void);
#endif	/* TIMER_H */

