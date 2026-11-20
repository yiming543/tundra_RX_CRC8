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
#include <stdint.h>


typedef struct {
  void (*const set)(uint8_t);
  uint8_t (*const get)(void);
} U8_t;

typedef struct {
  void (*const set)(uint16_t);
} U16_t;

typedef struct{
  U8_t fSIGNAL_FAIL;
  U16_t t10MS_CNT;
}TMR0_t;

extern TMR0_t const tmr0;
extern void TMR0_EvenHandler(void);
#endif	/* TIMER_H */

