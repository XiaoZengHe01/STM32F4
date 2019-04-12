#ifndef __SLEEP_H
#define __SLEEP_H

#ifdef __cplusplus
extern "C"
{
#endif
	
#include "stm32f4xx.h"
	
		
	
#define  STEP_US 21
#define  STEP_MS 21000
#define EVER -1
	
	
	typedef enum TIME_UNIT
	{
		S,
		MS,
		US,
		NS	
	}TIME_UNIT;
	
	
	
	void Sleep_Initialize(void);
	void Sleep(u32 TimeLong,TIME_UNIT TileUnit);
	void Sleep_Task(u32 StepSize,TIME_UNIT TileUnit,int LoopCount,void (*P_Task)());
#ifdef __cplusplus
}
#endif

#endif