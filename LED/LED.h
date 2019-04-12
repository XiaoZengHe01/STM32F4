#ifndef __LED_H
#define __LED_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_gpio.h"

  typedef enum LED_STATUS
  {
    LED1_ON,
    LED1_OFF,
    LED2_ON,
    LED2_OFF,
    LED3_ON,
    LED3_OFF,
    LED4_ON,
    LED4_OFF
  }LED_STATUS;

  void LED_Initialize(u16 On);
  void LED1_Initialize(u16 On);
  void LED2_Initialize(u16 On);
  void LED3_Initialize(u16 On);
  void LED4_Initialize(u16 On);
  void LED_Controller(LED_STATUS LedStatus);

#ifdef __cplusplus
}
#endif

#endif
