# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/t00904/.mchp_packs/Microchip/PIC12-16F1xxx_DFP/1.2.63/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../BOARD.h" 1
# 11 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../BOARD.h"
extern void board_init(void);
extern void board_updata(void);
# 2 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2

# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../LED.h" 1



# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 1 3



# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3
# 26 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 133 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef short intptr_t;
# 164 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3

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
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdint.h" 2 3
# 5 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../LED.h" 2







typedef struct {
  void (*const on)(void);
  void (*const off)(void);
  uint8_t (*const is_on)(void);
} LED_t;

typedef struct {
  LED_t pos;
  LED_t drl;
  LED_t loBeam;
  LED_t hiBeam;
  LED_t turnLeft;
  LED_t turnRight;
} LEDs_t;

typedef enum {
  POS = 0,
  DRL,
  LO_BEAM,
  HI_BEAM,
  TURN_LEFT,
  TURN_RIGHT,
  LED_COUNT,
} Led_t;



extern const LEDs_t led;


void LED_Init(void);
# 4 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../Warning_ignored.h" 1
# 15 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../Warning_ignored.h"
extern void Clear_No_Call_Warning(void) ;
# 5 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h" 1
# 55 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v2.46\\pic\\include\\c99\\stdbool.h" 1 3
# 55 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h" 2
# 104 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_Initialize(void);
# 135 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
uint8_t TMR0_ReadTimer(void);
# 174 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_WriteTimer(uint8_t timerVal);
# 210 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_Reload(void);
# 225 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_ISR(void);
# 243 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_CallBack(void);
# 261 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
 void TMR0_SetInterruptHandler(void (* InterruptHandler)(void));
# 279 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
extern void (*TMR0_InterruptHandler)(void);
# 297 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../mcc_generated_files/tmr0.h"
void TMR0_DefaultInterruptHandler(void);
# 6 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../timer.h" 1
# 15 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../timer.h"
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
# 7 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../tundra_PWM_receiver.h" 1
# 14 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../tundra_PWM_receiver.h"
typedef struct {
  uint8_t (*const get)(void);
} Get_t;

typedef struct {
  Get_t pos;
  Get_t drl;
  Get_t loBeam;
  Get_t hiBeam;
  Get_t turnLeft;
  Get_t turnRight;
} Gets_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} Data_t;


extern const Data_t fCRC;
extern const Gets_t Receiver;


extern void Receiver_FrameData(void);
# 8 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\BOARD.c" 2




void board_init(void) {
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  LED_Init();
  Clear_No_Call_Warning();
}

void dataSetLed(void) {


  if (fCRC.get() != 0U) {
    fCRC.set(0U);

    if (Receiver.pos.get() == (1U)) {
      led.pos.on();
    } else {
      led.pos.off();
    }

    if (Receiver.drl.get() == (1U)) {
      led.drl.on();
    } else {
      led.drl.off();
    }

    if (Receiver.loBeam.get() == (1U)) {
      led.loBeam.on();
    } else {
      led.loBeam.off();
    }

    if (Receiver.hiBeam.get() == (1U)) {
      led.hiBeam.on();
    } else {
      led.hiBeam.off();
    }

    if (Receiver.turnLeft.get() == (1U)) {
      led.turnLeft.on();
    } else {
      led.turnLeft.off();
    }

    if (Receiver.turnRight.get() == (1U)) {
      led.turnRight.on();
    } else {
      led.turnRight.off();
    }
  }
}

void CheckSignalFail(void) {
  if (tmr0.fSIGNAL_FAIL.get() == 1U) {
    tmr0.fSIGNAL_FAIL.set(0U);

    led.pos.on();
    led.drl.off();
    led.loBeam.on();
    led.hiBeam.off();
    led.turnLeft.off();
    led.turnRight.off();
  }
}

void board_updata(void) {
  Receiver_FrameData();
  dataSetLed();
  CheckSignalFail();
}
