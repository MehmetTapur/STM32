#include "EXTI.h"

void EXTI_Init(EXTI_InitTypeDef_t * EXTI_InitStruct)
{
	uint32_t tempValue = 0;

	EXTI->IMR &= ~(0x1U<<EXTI_InitStruct->LineNumber);
	EXTI->EMR &= ~(0x1U<<EXTI_InitStruct->LineNumber);
	if(EXTI_InitStruct->LineCmd != DISABLE)
	{
		 tempValue = EXTI_BASE_ADDR;

		 tempValue+=EXTI_InitStruct->Mode;

		*((__IO uint32_t *)tempValue) |= (0x1U<<EXTI_InitStruct->LineNumber);

		EXTI->FTSR &= ~(0x1U<<EXTI_InitStruct->LineNumber);
		EXTI->RTSR &= ~(0x1U<<EXTI_InitStruct->LineNumber);

		if(EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF)
		{
			EXTI->FTSR |= (0x1U<<EXTI_InitStruct->LineNumber);
			EXTI->RTSR |= (0x1U<<EXTI_InitStruct->LineNumber);
		}
		else
		{
			tempValue = EXTI_BASE_ADDR;

			tempValue += EXTI_InitStruct->TriggerSelection;

			*((__IO uint32_t *)tempValue) |= (0x1U<<EXTI_InitStruct->LineNumber);
		}

	}
	else
	{
		 tempValue = EXTI_BASE_ADDR;

		 tempValue+=EXTI_InitStruct->Mode;

		*((__IO uint32_t *)tempValue) &= ~(0x1U<<EXTI_InitStruct->LineNumber);

	}

}


void EXTI_LineConfig(uint8_t PortSource, uint8_t LineSource)
{
	uint32_t tempValue=SYSCFG->CR[LineSource>>2U];
	tempValue &= ~(0xFU<<((LineSource & 0x3U)*4U));
	tempValue |= (PortSource<<((LineSource & 0x3U)*4U));
	SYSCFG->CR[LineSource>>2U] = tempValue;

}

void NVIC_InterruptEnable(IRQNumber_TypeDef_t IRQNumber)
{
	uint32_t tempValue = 0;

	tempValue = *((IRQNumber>>5)+ NVIC_ISER0);
	tempValue &= ~(0x1U<<(IRQNumber  &  0x1FU));	/*!< bu kodum herhangi bir etkisi olmaz çünkü iser registerina  0 yazildigi zaman bir etki gostermez*/
	tempValue |=  (0x1U<<(IRQNumber  &  0x1FU));
	*((IRQNumber>>5)+ NVIC_ISER0) = tempValue;
}
