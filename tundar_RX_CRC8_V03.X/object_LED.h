#ifndef OBJECT_LED_H
#define OBJECT_LED_H

#include <stdint.h>
// #include "mcc_generated_files/pin_manager.h"

// LED物件型態定義
// typedef void (*output_func)(void);
// typedef uint8_t (*input_func)(void);

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


// 初始化函數
extern LED_GROUP_t obj_led;
extern void LED_init(LED_GROUP_t *obj);



#endif // OBJECT_LED_H
