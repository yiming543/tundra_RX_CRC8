#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H

// #include "LED.h"
// #include "tundra_PWM_receiver.h"

#define data_length (8U)
#define buf_length (11U)

#define LOGIC_LEVEL (16)
#define UART_LEVEL (21)

// 初始化函數
extern void board_init(void);
extern void CheckSignalFail(void);
void dataSetLED(void);


#endif // OBJECT_BOARD_H

