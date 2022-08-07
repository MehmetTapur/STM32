/*
 * EXTI.h
 *
 *  Created on: 23 Şub 2022
 *      Author: ps
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f407xx.h"

#define EXTI_LineSource_0	((uint8_t)(0x0U))
#define EXTI_LineSource_1	((uint8_t)(0x1U))
#define EXTI_LineSource_2	((uint8_t)(0x2U))
#define EXTI_LineSource_3	((uint8_t)(0x3U))
#define EXTI_LineSource_4	((uint8_t)(0x4U))
#define EXTI_LineSource_5	((uint8_t)(0x5U))
#define EXTI_LineSource_6	((uint8_t)(0x6U))
#define EXTI_LineSource_7	((uint8_t)(0x7U))
#define EXTI_LineSource_8	((uint8_t)(0x8U))
#define EXTI_LineSource_9	((uint8_t)(0x9U))
#define EXTI_LineSource_10	((uint8_t)(0xAU))
#define EXTI_LineSource_11	((uint8_t)(0xBU))
#define EXTI_LineSource_12	((uint8_t)(0xCU))
#define EXTI_LineSource_13	((uint8_t)(0xDU))
#define EXTI_LineSource_14	((uint8_t)(0xEU))
#define EXTI_LineSource_15	((uint8_t)(0xFU))

#define EXTI_PortSource_A	((uint8_t)(0x0U))
#define EXTI_PortSource_B	((uint8_t)(0x1U))
#define EXTI_PortSource_C	((uint8_t)(0x2U))
#define EXTI_PortSource_D	((uint8_t)(0x3U))
#define EXTI_PortSource_E	((uint8_t)(0x4U))
#define EXTI_PortSource_F	((uint8_t)(0x5U))
#define EXTI_PortSource_G	((uint8_t)(0x6U))
#define EXTI_PortSource_H	((uint8_t)(0x7U))


typedef enum{

	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10

}IRQNumber_TypeDef_t;


typedef struct{

	FunctionalState_t LineCmd;
	uint8_t LineNumber;
	uint8_t TriggerSelection;
	uint8_t Mode;

}EXTI_InitTypeDef_t;


#define EXTI_MODE_IMR	0x00U
#define EXTI_MODE_EMR	0x04U

#define EXTI_Trigger_Rising 	0x08U
#define EXTI_Trigger_Falling 	0x08U
#define EXTI_Trigger_RF 		0x08U



void EXTI_Init(EXTI_InitTypeDef_t * EXTI_InitStruct);
void EXTI_LineConfig(uint8_t PortSource, uint8_t LineSource);
void NVIC_InterruptEnable(IRQNumber_TypeDef_t IRQNumber);


#endif /* INC_EXTI_H_ */
