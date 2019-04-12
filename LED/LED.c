#include "../MyProjects/LED/LED.h"


void LED_Initialize(u16 On)
{

	/****************** Some varable ******************/
	GPIO_InitTypeDef GPIO_Config={0};

	/****************** The enable periph clock ******************/	
	//GPIOA the enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	//The enable periph clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

	/****************** D1 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_9;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_Config);

	/****************** D2 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_10;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_Config);

	/****************** D3 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_13;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOE,&GPIO_Config);

	/****************** D4 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_14;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOE,&GPIO_Config);


	if(!On)
	{
		LED_Controller(LED1_OFF);
		LED_Controller(LED2_OFF);
		LED_Controller(LED3_OFF);
		LED_Controller(LED4_OFF);
	}
}

void LED1_Initialize(u16 On)
{


	/****************** Some varable ******************/
	GPIO_InitTypeDef GPIO_Config={0};

	/****************** The enable periph clock ******************/	
	//GPIOA the enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

	/****************** D1 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_9;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_Config);

	if(!On)
	{
		LED_Controller(LED1_OFF);
	}



}

void LED2_Initialize(u16 On)
{

	/****************** Some varable ******************/
	GPIO_InitTypeDef GPIO_Config={0};

	/****************** The enable periph clock ******************/	
	//GPIOA the enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

	/****************** D2 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_10;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_Config);

	if(!On)
	{
		LED_Controller(LED2_OFF);
	}

}

void LED3_Initialize(u16 On)
{

	/****************** Some varable ******************/
	GPIO_InitTypeDef GPIO_Config={0};

	/****************** The enable periph clock ******************/	
	//GPIOA the enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

	/****************** D3 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_13;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOE,&GPIO_Config);

	if(!On)
	{
		LED_Controller(LED3_OFF);
	}	

}

void LED4_Initialize(u16 On)
{

	/****************** Some varable ******************/
	GPIO_InitTypeDef GPIO_Config={0};

	/****************** The enable periph clock ******************/	
	//GPIOA the enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

	/****************** D4 configure ******************/
	GPIO_Config.GPIO_Pin=GPIO_Pin_14;
	GPIO_Config.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Config.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Config.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Config.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOE,&GPIO_Config);

	if(!On)
	{
		LED_Controller(LED4_OFF);
	}


}

void LED_Controller(LED_STATUS LedStatus)
{

	switch(LedStatus)
	{
		case LED1_ON:
			GPIO_ResetBits(GPIOF,GPIO_Pin_9);
			break;
		case LED1_OFF:
			GPIO_SetBits(GPIOF,GPIO_Pin_9);
			break;
		case LED2_ON:
			GPIO_ResetBits(GPIOF,GPIO_Pin_10);
			break;
		case LED2_OFF:
			GPIO_SetBits(GPIOF,GPIO_Pin_10);
			break;
		case LED3_ON:
			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
			break;
		case LED3_OFF:
			GPIO_SetBits(GPIOE,GPIO_Pin_13);
			break;
		case LED4_ON:
			GPIO_ResetBits(GPIOE,GPIO_Pin_14);
			break;
		case LED4_OFF:
			GPIO_SetBits(GPIOE,GPIO_Pin_14);
			break;
		default:
			break;
	}
}
