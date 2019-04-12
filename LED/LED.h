#ifndef __LED_H
#define __LED_H


#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_gpio.h"

  typedef enum LED_STATUS
  {
    D1_ON,
    D1_OFF,
    D2_ON,
    D2_OFF,
    D3_ON,
    D3_OFF,
    D4_ON,
    D4_OFF
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
