#include "stm32f10x.h"

#define PIN_LIGHT_SENSOR GPIO_Pin_13
#define PINSOURCE_LIGHT_SENSOR GPIO_PinSource13

uint32_t Light_Sensor_count = 0;

void Light_Sensor_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = PIN_LIGHT_SENSOR;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}


uint8_t Light_Sensor_get_status(void){
	return GPIO_ReadInputDataBit(GPIOB, PIN_LIGHT_SENSOR);
}

void EXTI15_10_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line13) == SET){
		Light_Sensor_count++;
		EXTI_ClearITPendingBit(EXTI_Line13);
	}	
}

uint32_t Light_Sensor_get_count(void){
	return Light_Sensor_count;
}

void Light_Sensor_counter_init(void){
	// Enable clock for AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);


	// configure EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, PINSOURCE_LIGHT_SENSOR);

	EXTI_InitTypeDef EXTI_InitStructure;

	EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);

	// configure NVIC
#ifndef __NVIC_PriorityGroup
#define __NVIC_PriorityGroup
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
#endif


	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);

}
