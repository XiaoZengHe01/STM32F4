#include "../MyProject/Sleep/Sleep.h"

void Sleep_Initialize()
{
	
	//systick��ʱ�� ʱ��Ƶ��  168MHZ/8 = 21MHZ
	//Systickʱ��Դѡ��  misc.c�ļ���
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); 
}

void Sleep(u32 TimeLong,TIME_UNIT TileUnit)
{
	
	u32 Temp = 0;
	
	switch(TileUnit)
	{
		case S:
			break;
		case MS:
			if(TimeLong<=798)
			{
				SysTick->LOAD = STEP_MS*TimeLong - 1;	
			}
			else
			{
				SysTick->LOAD = STEP_MS*790 - 1;	
			}
			break;
		case US:
			if(TimeLong<=798915)
			{
				SysTick->LOAD = STEP_US*TimeLong - 1;	
			}
			else
			{
				SysTick->LOAD = STEP_US*790000 - 1;	
			}
			SysTick->LOAD = STEP_US*TimeLong - 1;
			break;
		case NS:	
			break;
		default:
			break;
	}
	
	SysTick->VAL  = 0;  //����Ϊ0,�Ա�load�Ĵ�����ֵ���õ�VAL��
		
	//����systick��ʱ��
	SysTick->CTRL |= (1<<0);  //������ʱ�� 
				
	do
	{
		//��������ֵ��ֵtemp
		Temp = SysTick->CTRL;  
		//����ʮ��λ�Ƿ�Ϊ1
	}while( !(Temp &(1<<16)) ); 

	//�ر�systick��ʱ��
	SysTick->CTRL &= ~(1<<0); 		
							
}


void Sleep_Task(u32 StepSize,TIME_UNIT TileUnit,int LoopCount,void (*P_Task)())
{
	
	if(LoopCount<0)
	{
		while(1)
		{
			(*P_Task)();
			Sleep(StepSize,TileUnit);
		
		}
	}
	else
	{
		while(LoopCount--)
		{
			(*P_Task)();
			Sleep(StepSize,TileUnit);
		
		}
	}
}
