#include "../MyProjects/Exti/Exti.h"



void Exti_Initialize(void)
{

  GPIO_InitTypeDef  GPIO_InitStruct;
  EXTI_InitTypeDef  EXTI_InitStruct;
  NVIC_InitTypeDef  NVIC_InitStruct;
  //使能SYSCFG时钟： 中断时钟		 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  /****************** Initialize periph clock ******************/
  //初始化GPIO A组时钟
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  GPIO_InitStruct.GPIO_Pin    =GPIO_Pin_0;  	//引脚0
  GPIO_InitStruct.GPIO_Mode   =GPIO_Mode_IN;	//输出模式
  GPIO_InitStruct.GPIO_PuPd   =GPIO_PuPd_UP;    //上拉
  GPIO_Init(GPIOA,&GPIO_InitStruct);	

  //设置IO口与中断线的映射关系。
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);	
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource0);	

  EXTI_InitStruct.EXTI_Line	=EXTI_Line0;		//中断线0
  EXTI_InitStruct.EXTI_Mode	=EXTI_Mode_Interrupt;  	//中断模式
  EXTI_InitStruct.EXTI_Trigger 	=EXTI_Trigger_Falling;  //下降沿
  EXTI_InitStruct.EXTI_LineCmd  =ENABLE; //中断线使能
  //初始化线上中断，设置触发条件等。	   
  EXTI_Init(&EXTI_InitStruct);

  NVIC_InitStruct.NVIC_IRQChannel        	    =EXTI0_IRQn;  //中断请求通道
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =2;  //抢占优先级
  NVIC_InitStruct.NVIC_IRQChannelSubPriority	    =2;  //响应优先级
  NVIC_InitStruct.NVIC_IRQChannelCmd		    =ENABLE;
  //配置中断分组（NVIC），并使能中断。    
  NVIC_Init(&NVIC_InitStruct);





}
