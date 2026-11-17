# 1 "BOARD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/t00904/.mchp_packs/Microchip/PIC12-16F1xxx_DFP/1.2.63/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "BOARD.c" 2
# 1 "./BOARD.h" 1
# 14 "./BOARD.h"
extern void board_init(void);
extern void CheckSignalFail(void);
void dataSetLED(void);
# 2 "BOARD.c" 2

# 1 "./Warning_ignored.h" 1
# 15 "./Warning_ignored.h"
extern void Clear_No_Call_Warning(void) ;
# 4 "BOARD.c" 2
# 1 "./mcc_generated_files/tmr0.h" 1
# 54 "./mcc_generated_files/tmr0.h"
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
# 54 "./mcc_generated_files/tmr0.h" 2

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
# 5 "BOARD.c" 2
# 1 "./timer.h" 1
# 15 "./timer.h"
typedef struct {
  void (*const set)(uint8_t);
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
extern void CheckSignalFail(void);
# 6 "BOARD.c" 2
# 1 "./LED.h" 1
# 12 "./LED.h"
typedef struct {
  void (*const on)(void);
  void (*const off)(void);
  uint8_t (*const is_on)(void);
} LED_t;

typedef enum {
  POS = 0,
  DRL,
  LO_BEAM,
  HI_BEAM,
  TURN_LEFT,
  TURN_RIGHT,
  LED_COUNT,
} Led_t;



extern const LED_t led[LED_COUNT];


void LED_Init(void);
# 7 "BOARD.c" 2
# 1 "./tundra_PWM_receiver.h" 1
# 14 "./tundra_PWM_receiver.h"
typedef struct {
  uint8_t (*const get)(void);
} Get_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} Data_t;


extern Data_t const fCRC;
extern Get_t const Receiver[LED_COUNT];


extern void Receiver_FrameData(void);
# 8 "BOARD.c" 2




void board_init(void) {
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  LED_Init();
  Clear_No_Call_Warning();
}

void dataSetLed(void) {


  if (fCRC.get() != 0U) {
    fCRC.set(0U);

    if (Receiver[POS].get() == (1U)) {
      led[POS].on();
    } else {
      led[POS].off();
    }

    if (Receiver[DRL].get() == (1U)) {
      led[DRL].on();
    } else {
      led[DRL].off();
    }

    if (Receiver[LO_BEAM].get() == (1U)) {
      led[LO_BEAM].on();
    } else {
      led[LO_BEAM].off();
    }

    if (Receiver[HI_BEAM].get() == (1U)) {
      led[HI_BEAM].on();
    } else {
      led[HI_BEAM].off();
    }

    if (Receiver[TURN_LEFT].get() == (1U)) {
      led[TURN_LEFT].on();
    } else {
      led[TURN_LEFT].off();
    }

    if (Receiver[TURN_RIGHT].get() == (1U)) {
      led[TURN_RIGHT].on();
    } else {
      led[TURN_RIGHT].off();
    }
  }
}
