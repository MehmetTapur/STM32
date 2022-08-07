
#include "SPI.h"

static void SPI_CloseISR_Tx(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->CR2 &= ~(0x1U<<SPI_CR2_TXEIE);
	SPI_Handle->TxDataSize = 0;
	SPI_Handle->pTxDataAddr = NULL;
	SPI_Handle->busStateTx = SPI_FREE;


}
static void SPI_TransmitHelper_16Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->DR = *((uint16_t *)(SPI_Handle->pTxDataAddr));
	SPI_Handle->pTxDataAddr +=sizeof(uint16_t);
	SPI_Handle->TxDataSize -=2;

	if(SPI_Handle->TxDataSize == 0)
	{
		SPI_CloseISR_Tx(SPI_Handle);
	}


}
static void SPI_TransmitHelper_8Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->DR = *((uint8_t *)(SPI_Handle->pTxDataAddr));
	SPI_Handle->pTxDataAddr +=sizeof(uint8_t);
	SPI_Handle->TxDataSize --;

	if(SPI_Handle->TxDataSize == 0)
	{
		SPI_CloseISR_Tx(SPI_Handle);
	}
}
static void SPI_CloseISR_Rx(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->CR2 &= ~(0x1U<<SPI_CR2_RXNEIE);
	SPI_Handle->RxDataSize = 0;
	SPI_Handle->pRxDataAddr = NULL;
	SPI_Handle->busStateRx = SPI_FREE;

}
static void SPI_ReceiveHelper_8Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	*((uint8_t*)(SPI_Handle->pRxDataAddr)) = *((__IO uint8_t*)(&SPI_Handle->Instance->DR));
	SPI_Handle->RxDataSize--;
	SPI_Handle->pRxDataAddr += sizeof(uint8_t);
	if(SPI_Handle->RxDataSize == 0)
	{
		SPI_CloseISR_Rx(SPI_Handle);
	}


}
static void SPI_ReceiveHelper_16Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	*((uint16_t*)(SPI_Handle->pRxDataAddr)) = (uint16_t)SPI_Handle->Instance->DR;
	SPI_Handle->RxDataSize-=2;
	SPI_Handle->pRxDataAddr += sizeof(uint16_t);
	if(SPI_Handle->RxDataSize == 0)
	{
		SPI_CloseISR_Rx(SPI_Handle);
	}

}
void SPI_Init(SPI_HandleTypedef_t *SPI_Handle){

	uint32_t tempValue = 0;

	tempValue= SPI_Handle->Instance->CR1;

	tempValue = SPI_Handle->Init.BIDMode | SPI_Handle->Init.Baudrate | SPI_Handle->Init.CPHA | \
				SPI_Handle->Init.CPOL | SPI_Handle->Init.DFF | SPI_Handle->Init.FrameFormat | \
				SPI_Handle->Init.MasterSelection | SPI_Handle->Init.SSM;

	SPI_Handle->Instance->CR1 = tempValue;

}



void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle, FunctionalState_t stateOfSPI)
{
	if(stateOfSPI == ENABLE)
	{

		SPI_Handle->Instance->CR1 |= (0x1<<SPI_CRC1_SPE);
	}
	else
	{
		SPI_Handle->Instance->CR1 &= ~(0x1<<SPI_CRC1_SPE);
	}


}

void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pdata, uint16_t sizeOfData)
{
	if(SPI_Handle->Init.DFF == SPI_FF_16bit)
	{
		while(sizeOfData > 0)
		{
			if(SPI_GetFlagStatus(SPI_Handle,SPI_SR_TXE))
			{
				SPI_Handle->Instance->DR = *((uint16_t *)pdata);
				pdata+= sizeof(uint16_t);
				sizeOfData -= sizeof(uint16_t);

			}
		}

	}
	else
	{
		while(sizeOfData >0)
		{
			if(SPI_GetFlagStatus(SPI_Handle,SPI_SR_TXE))
			{
				SPI_Handle->Instance->DR = *pdata;
				pdata+= sizeof(uint8_t);
				sizeOfData -= sizeof(uint8_t);
			}
		}
	}
	while(SPI_GetFlagStatus(SPI_Handle,SPI_SR_BSY));
}
void SPI_ReceiveData(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pbuff, uint16_t sizeOfData)
{
	if(SPI_Handle->Init.FrameFormat ==SPI_FF_16bit)
	{
		while(sizeOfData > 0)
		{
			if(SPI_GetFlagStatus(SPI_Handle, SPI_SR_RXNE))
			{
				*((uint16_t *)(pbuff)) = (uint16_t)SPI_Handle->Instance->DR;
				pbuff+= sizeof(uint16_t);
				sizeOfData -= sizeof(uint16_t);
			}
		}

	}
	else
	{
		while(sizeOfData > 0)
		{
			if(SPI_GetFlagStatus(SPI_Handle, SPI_SR_RXNE))
			{
				*pbuff = *((__IO uint8_t *)(&SPI_Handle->Instance->DR));
				pbuff+= sizeof(uint8_t);
				sizeOfData -= sizeof(uint8_t);
			}
		}
	}

}

SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypedef_t *SPI_Handle, uint16_t flag)
{
	return ( SPI_Handle->Instance->SR & flag ) ? SPI_FLAG_SET : SPI_FLAG_RESET;
}


void SPI_TransmitData_IT(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pdata, uint16_t sizeOfData)
{

	SPI_BusStatus_t busStatus = SPI_Handle->busStateTx;

	if(busStatus != SPI_BUSY_TX)
	{
		SPI_Handle->pTxDataAddr = (uint8_t *)pdata;
		SPI_Handle->TxDataSize = (uint16_t) sizeOfData;
		SPI_Handle->busStateTx = SPI_BUSY_TX;

		if(SPI_Handle->Instance->CR2 & (0x1<<SPI_CRC1_DFF))
		{

			SPI_Handle->TxISRFunction = SPI_TransmitHelper_16Bits;
		}
		else
		{
			SPI_Handle->TxISRFunction = SPI_TransmitHelper_8Bits;
		}

		SPI_Handle->Instance->CR2 |= (0x1U<<SPI_CR2_TXEIE);

	}

}
void SPI_ReceivetData_IT(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pbuff, uint16_t sizeOfData)
{
	SPI_BusStatus_t busState = SPI_Handle->busStateRx;

	if(busState != SPI_BUSY_RX)
	{
		SPI_Handle->pRxDataAddr = (uint8_t *)pbuff;
		SPI_Handle->TxDataSize = (uint16_t) sizeOfData;
		SPI_Handle->busStateTx = SPI_BUSY_RX;

		if(SPI_Handle->Instance->CR2 & (0x1<<SPI_CRC1_DFF))
		{

			SPI_Handle->RxISRFunction = SPI_ReceiveHelper_16Bits;
		}
		else
		{
			SPI_Handle->RxISRFunction = SPI_ReceiveHelper_8Bits;
		}

		SPI_Handle->Instance->CR2 |= (0x1U<<SPI_CR2_RXNEIE);

	}


}


void SPI_InterruptHandler(SPI_HandleTypedef_t *SPI_Handle)
{
	uint8_t interruptSource = 0;
	uint8_t interruptFlag = 0;

	interruptSource = (SPI_Handle->Instance->SR  & (0x1<<SPI_SR_TXE));
	interruptFlag = (SPI_Handle->Instance->CR2 & (0x1<<SPI_CR2_TXEIE));

	if((interruptSource != 0) && (interruptFlag != 0))
	{
		SPI_Handle->TxISRFunction(SPI_Handle);

	}

	interruptSource = (SPI_Handle->Instance->SR  & (0x1<<SPI_SR_RXNE));
	interruptFlag = (SPI_Handle->Instance->CR2 & (0x1<<SPI_CR2_RXNEIE));

	if((interruptSource != 0) && (interruptFlag != 0))
	{
		SPI_Handle->RxISRFunction(SPI_Handle);

	}

}
