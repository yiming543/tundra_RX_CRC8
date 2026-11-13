# 1 "object_BOARD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/t00904/.mchp_packs/Microchip/PIC12-16F1xxx_DFP/1.2.63/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "object_BOARD.c" 2
# 1 "./object_BOARD.h" 1



# 1 "./object_LED.h" 1



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3
# 26 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 133 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef short intptr_t;
# 164 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3
# 5 "./object_LED.h" 2






typedef struct {
  void (*on)(void);
  void (*off)(void);
  uint8_t (*is_on)(void);
  uint8_t state;
} LED_t;

typedef struct {
  LED_t pos;
  LED_t drl;
  LED_t loBeam;
  LED_t hiBeam;
  LED_t turnLeft;
  LED_t turnRight;
} LED_GROUP_t;



extern LED_GROUP_t obj_led;
extern void LED_init(LED_GROUP_t *obj);
# 5 "./object_BOARD.h" 2
# 1 "./tundra_PWM_receiver.h" 1
# 13 "./tundra_PWM_receiver.h"
typedef struct {
  uint8_t ID;
  uint8_t LENGHT;
  uint8_t DATA[8];
  uint8_t CRC;
} FRAME_t;



extern uint8_t fCRC_OK;
extern uint8_t D2;
extern uint8_t D3;


extern void Receiver_FrameData(void);
# 6 "./object_BOARD.h" 2








typedef struct {
  LED_GROUP_t *led;


} BOARD_t;
# 66 "./object_BOARD.h"
extern void board_init(BOARD_t *obj);
extern void obj_init(void);

extern void LED_output(void);
extern void CheckSignalFail(void);
void dataSetLED(void);

extern BOARD_t board;
# 2 "object_BOARD.c" 2


# 1 "./Warning_ignored.h" 1
# 15 "./Warning_ignored.h"
extern void Clear_No_Call_Warning(void) ;
# 5 "object_BOARD.c" 2
# 1 "./mcc_generated_files/tmr0.h" 1
# 55 "./mcc_generated_files/tmr0.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\c99\\stdbool.h" 1 3
# 55 "./mcc_generated_files/tmr0.h" 2
# 104 "./mcc_generated_files/tmr0.h"
void TMR0_Initialize(void);
# 135 "./mcc_generated_files/tmr0.h"
uint8_t TMR0_ReadTimer(void);
# 174 "./mcc_generated_files/tmr0.h"
void TMR0_WriteTimer(uint8_t timerVal);
# 210 "./mcc_generated_files/tmr0.h"
void TMR0_Reload(void);
# 225 "./mcc_generated_files/tmr0.h"
void TMR0_ISR(void);
# 243 "./mcc_generated_files/tmr0.h"
void TMR0_CallBack(void);
# 261 "./mcc_generated_files/tmr0.h"
 void TMR0_SetInterruptHandler(void (* InterruptHandler)(void));
# 279 "./mcc_generated_files/tmr0.h"
extern void (*TMR0_InterruptHandler)(void);
# 297 "./mcc_generated_files/tmr0.h"
void TMR0_DefaultInterruptHandler(void);
# 6 "object_BOARD.c" 2
# 1 "./timer.h" 1
# 13 "./timer.h"
extern volatile uint8_t fSignalFail;
extern volatile uint16_t T10MS_CNT;

extern void TMR0_EvenHandler(void);
# 7 "object_BOARD.c" 2
# 1 "./tundra_crc8.h" 1
# 16 "./tundra_crc8.h"
extern uint8_t calculate_crc8(const uint8_t *data, uint8_t length);
# 8 "object_BOARD.c" 2
# 27 "object_BOARD.c"
BOARD_t board;

void board_init(BOARD_t *obj) {
  obj->led = &obj_led;
}

void obj_init(void) {
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  LED_init(&obj_led);
  board_init(&board);
  Clear_No_Call_Warning();
}

void dataSetLED(void) {


  if (fCRC_OK != 0U) {
    fCRC_OK = 0U;

    if (((uint8_t)(!!((D2) & (1U << (2))))) == 1U) {
      board.led->pos.on();
    } else {
      board.led->pos.off();
    }

    if (((uint8_t)(!!((D2) & (1U << (3))))) == 1U) {
      board.led->drl.on();
    } else {
      board.led->drl.off();
    }

    if (((uint8_t)(!!((D2) & (1U << (4))))) == 1U) {
      board.led->loBeam.on();
    } else {
      board.led->loBeam.off();
    }

    if (((uint8_t)(!!((D2) & (1U << (5))))) == 1U) {
      board.led->hiBeam.on();
    } else {
      board.led->hiBeam.off();
    }

    if (((uint8_t)(!!((D3) & (1U << (5))))) == 1U) {
      board.led->turnLeft.on();
    } else {
      board.led->turnLeft.off();
    }


    if (((uint8_t)(!!((D3) & (1U << (6))))) == 1U) {
      board.led->turnRight.on();
    } else {
      board.led->turnRight.off();
    }
  }
}

void CheckSignalFail(void) {
  if (fSignalFail == 1U) {
    fSignalFail = 0U;

    board.led->pos.on();
    board.led->drl.off();
    board.led->loBeam.on();
    board.led->hiBeam.off();
    board.led->turnLeft.off();
    board.led->turnRight.off();
  }
}
