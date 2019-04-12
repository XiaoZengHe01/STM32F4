#include "../MyProject/LED/LED.h"


void LED_Controller(LED_STATUS LedStatus)
{

  /****************** Some varable ******************/
  GPIO_InitTypeDef GPIOF_Config={0};

  /****************** The enable periph clock ******************/	
  //GPIOA the enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
  //The enable periph clock
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

  /****************** D1 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_9;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOF,&GPIOF_Config);

  /****************** D2 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_10;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOF,&GPIOF_Config);

  /****************** D3 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_13;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOE,&GPIOF_Config);

  /****************** D4 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_14;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOE,&GPIOF_Config);

  if(!On)
  {

    LED_Controller(D1_OFF);
    LED_Controller(D2_OFF);
    LED_Controller(D3_OFF);
    LED_Controller(D4_OFF);
  }
}

void LED1_Initialize(u16 On)
{


  /****************** Some varable ******************/
  GPIO_InitTypeDef GPIOF_Config={0};

  /****************** The enable periph clock ******************/	
  //GPIOA the enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

  /****************** D1 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_9;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOF,&GPIOF_Config);

  On?1:LED_Controller(D1_OFF);

}

void LED2_Initialize(u16 On)
{

  /****************** Some varable ******************/
  GPIO_InitTypeDef GPIOF_Config={0};

  /****************** The enable periph clock ******************/	
  //GPIOA the enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

  /****************** D2 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_10;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOF,&GPIOF_Config);

  On?1:LED_Controller(D2_OFF);

}

void LED3_Initialize(u16 On)
{

  /****************** Some varable ******************/
  GPIO_InitTypeDef GPIOF_Config={0};

  /****************** The enable periph clock ******************/	
  //GPIOA the enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

  /****************** D3 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_13;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOE,&GPIOF_Config);

  On?1:LED_Controller(D3_OFF);


}

void LED4_Initialize(u16 On)
{

  /****************** Some varable ******************/
  GPIO_InitTypeDef GPIOF_Config={0};

  /****************** The enable periph clock ******************/	
  //GPIOA the enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

  /****************** D4 configure ******************/
  GPIOF_Config.GPIO_Pin=GPIO_Pin_14;
  GPIOF_Config.GPIO_Mode=GPIO_Mode_OUT;
  GPIOF_Config.GPIO_PuPd=GPIO_PuPd_UP;
  GPIOF_Config.GPIO_Speed=GPIO_Speed_50MHz;
  GPIOF_Config.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOE,&GPIOF_Config);

  On?1:LED_Controller(D4_OFF);

}

void LED_Controller(LED_STATUS LedStatus)
{

  switch(LedStatus)
  {
    case D1_ON:
      GPIO_ResetBits(GPIOF,GPIO_Pin_9);
      break;
    case D1_OFF:
      GPIO_SetBits(GPIOF,GPIO_Pin_9);
      break;
    case D2_ON:
      GPIO_ResetBits(GPIOF,GPIO_Pin_10);
      break;
    case D2_OFF:
      GPIO_SetBits(GPIOF,GPIO_Pin_10);
      break;
    case D3_ON:
      GPIO_ResetBits(GPIOE,GPIO_Pin_13);
      break;
    case D3_OFF:
      GPIO_SetBits(GPIOE,GPIO_Pin_13);
      break;
    case D4_ON:
      GPIO_ResetBits(GPIOE,GPIO_Pin_14);
      break;
    case D4_OFF:
      GPIO_SetBits(GPIOE,GPIO_Pin_14);
      break;
    default:
      break;
  }
}
