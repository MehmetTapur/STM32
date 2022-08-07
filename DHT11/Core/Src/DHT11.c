/*
 * DHT11.c
 *
 *  Created on: May 24, 2022
 *      Author: ps
 */
#include "DHT11.h"


extern TIM_HandleTypeDef htim6;


/**************SOME STATIC FUNCTION***********************/

static void ControlTruth(uint8_t* temp);
static void setInput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
static void setOutput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**************USER API'S***********************/

void StartSignal(GPIO_TypeDef* gpiox,uint8_t PinNo)
{
    setOutput(gpiox,PinNo);
	HAL_GPIO_WritePin(gpiox, PinNo, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(gpiox, PinNo, GPIO_PIN_SET);
	__HAL_TIM_SET_COUNTER(&htim6,0);
	while((__HAL_TIM_GET_COUNTER(&htim6))<ResponseTime);

}




uint8_t GetResponse(GPIO_TypeDef* gpiox,uint16_t PinNo)
{

	setInput(gpiox,PinNo);
	while(!(HAL_GPIO_ReadPin(gpiox, PinNo)));
	__HAL_TIM_SET_COUNTER(&htim6,0);
	while(__HAL_TIM_GET_COUNTER(&htim6)<highTime);
	if(!(HAL_GPIO_ReadPin(gpiox, PinNo)))
	    return 0;
	return 1;

}




void GetResults(GPIO_TypeDef* gpiox,uint8_t* temperature,uint8_t* humidity,uint16_t PinNo)
{

	uint8_t temp[5]={0};
	uint8_t i=0,j=0;
	uint8_t LogicBit=40;
	uint32_t tempo=0;
	while(LogicBit--)
	{
		if(j==8)
			j=0;
		__HAL_TIM_SET_COUNTER(&htim6,0);
		while(!HAL_GPIO_ReadPin(gpiox, PinNo));
		tempo=__HAL_TIM_GET_COUNTER(&htim6);
		__HAL_TIM_SET_COUNTER(&htim6,0);
		while(__HAL_TIM_GET_COUNTER(&htim6)<MaxTimeForZero);
		if(HAL_GPIO_ReadPin(gpiox, PinNo))
		{
			*(temp+4-(i/8))= 1<<(7-j);
		}
		else
		{
			*(temp+4-(i/8))= ~(1<<(7-j));
		}

	    i++;
	    j++;

	}

	ControlTruth(temp);

	temperature=(uint8_t*)temp;
	humidity=(uint8_t*)(temp+1);

}





static void ControlTruth(uint8_t* temp)
{

	uint32_t Temp1=0;
	uint8_t Temp2=0;

	Temp1=temp[4]+temp[3]+temp[2]+temp[1];
	Temp2=temp[0];

	if(Temp1 != Temp2)
	{
		while(1)
		{
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
			HAL_Delay(2000);
		}
	}
}

static void setInput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

static void setOutput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}
