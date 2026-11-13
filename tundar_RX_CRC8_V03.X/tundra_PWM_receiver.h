/*
 * File:   Receiver_PWM.h
 * Author: T00904
 * Comments:
 * Revision history: V1.0
 */

#include <stdint.h>

#ifndef RECEIVER_PWM_H
#define RECEIVER_PWM_H

typedef struct {
  uint8_t ID;
  uint8_t LENGHT;
  uint8_t DATA[8];
  uint8_t CRC;
} FRAME_t;

// 宣告變數
// extern FRAME_t tundra_data;
extern uint8_t fCRC_OK;
extern uint8_t D2;
extern uint8_t D3;

//宣告函數
extern void Receiver_FrameData(void);

#endif /* RECEIVER_PWM_H */
