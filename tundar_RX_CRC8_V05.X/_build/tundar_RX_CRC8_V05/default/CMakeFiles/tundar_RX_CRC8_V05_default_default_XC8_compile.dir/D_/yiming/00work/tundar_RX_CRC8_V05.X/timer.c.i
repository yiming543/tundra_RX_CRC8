# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\timer.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/t00904/.mchp_packs/Microchip/PIC12-16F1xxx_DFP/1.2.63/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\timer.c" 2






# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../timer.h" 1
# 12 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../timer.h"
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
# 12 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../timer.h" 2



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
# 7 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\timer.c" 2

# 1 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../LED.h" 1
# 12 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\cmake\\tundar_RX_CRC8_V05\\default\\..\\..\\../LED.h"
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
# 8 "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\timer.c" 2



static uint8_t fSignalFail = 0U;
static uint16_t T10MS_CNT = 0;


static void fSIGNAL_FAIL_SET(uint8_t data) {
  fSignalFail = data;
}

static uint8_t fSIGNAL_FAIL_GET(void) {
  return fSignalFail;
}

static void T10MS_CNT_SET(uint16_t data) {
  T10MS_CNT = data;
}


TMR0_t const tmr0 = {
    .fSIGNAL_FAIL = {.set = fSIGNAL_FAIL_SET,.get =fSIGNAL_FAIL_GET},
    .t10MS_CNT = {.set = T10MS_CNT_SET},
};

void TMR0_EvenHandler(void) {
  T10MS_CNT++;
  if (T10MS_CNT >= 200U) {
    T10MS_CNT = 0U;
    fSignalFail = 1U;
  }
}
