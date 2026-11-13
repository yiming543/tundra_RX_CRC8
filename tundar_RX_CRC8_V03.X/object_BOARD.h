#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H

#include "object_LED.h"
#include "tundra_PWM_receiver.h"

#define ON 1U
#define OFF 0U

// LED物件型態定義
// typedef void (*output_func)(void);
// typedef uint8_t (*input_func)(void);

typedef struct {
  LED_GROUP_t *led;
  // SWITCH_GROUP_t *sw;
  // FRAME_t *tundraData;
} BOARD_t;

// typedef union {
//   struct {
//     unsigned : 2;
//     unsigned RunLight : 1;
//     unsigned DRL : 1;
//     unsigned LoBeam : 1;
//     unsigned HiBeam : 1;
//     unsigned : 2;
//   };
//   struct {
//     unsigned Byte : 8;
//   };
// } flag_D2;

// typedef union {

//   struct {
//     unsigned : 5;
//     unsigned turnLight_L : 1;
//     unsigned turnLight_R : 1;
//     unsigned : 1;
//   };
//   struct {
//     unsigned Byte : 8;
//   };
// } flag_D3;

// typedef union {
//   struct {
//     uint8_t id;
//     uint8_t length;
//     uint8_t data[8];
//     uint8_t crc;
//   };
//   struct {
//     uint8_t buf[11];
//   };
// } DATA_FRAME;

#define data_length 8U
#define buf_length 11U

#define LOGIC_LEVEL (16)
#define UART_LEVEL (21)

// 初始化函數
extern void board_init(BOARD_t *obj);
extern void obj_init(void);

extern void LED_output(void);
extern void CheckSignalFail(void);
void dataSetLED(void);

extern BOARD_t board;

#endif // OBJECT_BOARD_H

