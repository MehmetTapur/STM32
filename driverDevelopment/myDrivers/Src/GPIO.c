#include "GPIO.h"

void GPIO_Init(GPIO_Typedef_t* GPIOx,GPIO_InitTypeDef_t* GPIO_InitStruct)
{
	uint32_t position;
	uint32_t testpos=0;
	uint32_t lastpos=0;

	for(position=0; position<16;position++){

		testpos = 0x1<<position;
		lastpos = (uint32_t)(GPIO_InitStruct->pinNumber & testpos);

		if(lastpos == testpos)
		{
			uint32_t tempValue = GPIOx->MODER;
			tempValue &= ~(0x3<<(position*2));
			tempValue |= GPIO_InitStruct->Mode << (position*2);
			GPIOx->MODER = tempValue;

			if(GPIO_InitStruct->Mode == GPIO_MODE_OUTPUT || GPIO_InitStruct->Mode == GPIO_MODE_ALTERNATE)
			{

				tempValue = GPIOx->OTYPER;
				tempValue &= ~(0x1<<position);
				tempValue |= GPIO_InitStruct->Otype<<position;
				GPIOx->OTYPER = tempValue;

				tempValue = GPIOx->OSPEEDR;
				tempValue &= ~(0x3<<(position*2));
				tempValue |= GPIO_InitStruct->Speed<<(position*2);
				GPIOx->OSPEEDR = tempValue;

			}
			tempValue = GPIOx->PUPDR;
			tempValue &= ~(0x3<<(position*2));
			tempValue |= GPIO_InitStruct->PuPd << (position*2);
			GPIOx->PUPDR = tempValue;


			if( GPIO_InitStruct->Mode == GPIO_MODE_ALTERNATE)
			{
				tempValue = GPIOx->AFR[position>>3];
				tempValue &= ~(0xF<<((position & 0x7)*4));
				tempValue |= (GPIO_InitStruct->Alternate<<((position & 0x7)*4));
				GPIOx->AFR[position>>3] = tempValue;
			}

		}



	}



}


void GPIO_WritePin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber,GPIO_PinState_t pinState)
{


	if(pinState == GPIO_PIN_SET)
	{
		GPIOx->BSRR =  pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber<<16U);
	}

}

GPIO_PinState_t GPIO_ReadPin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitstatus= GPIO_PIN_RESET;
	if((GPIOx->IDR & pinNumber) != GPIO_PIN_RESET ){
		bitstatus = GPIO_PIN_SET;
	}

	return bitstatus;
}

void GPIO_LockPin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber)
{
	uint32_t tempreg = (0x1<<16) | pinNumber;

	GPIOx->LCKR = tempreg;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = tempreg;
	tempreg = GPIOx->LCKR;

}

void GPIO_TogglePin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber)
{
	uint32_t tempODRreg = GPIOx->ODR;

	GPIOx->BSRR = ((tempODRreg & pinNumber) <<16U) | (~tempODRreg & pinNumber);
}
