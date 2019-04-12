#include "../MyProject/Key/Key.h"


void Key_Initialize(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin    =GPIO_Pin_0;  	
	GPIO_InitStruct.GPIO_Mode	=GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd   =GPIO_PuPd_UP; 
	GPIO_Init(GPIOA,&GPIO_InitStruct);	

	
	
}
