/*
 * SPI.h
 *
 *  Created on: 28 Şub 2022
 *      Author: ps
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_


#include "stm32f407xx.h"

typedef enum{
	SPI_FREE = 0x0U,
	SPI_BUSY_TX = 0x1U,
	SPI_BUSY_RX = 0x2U
}SPI_BusStatus_t;


/*
 *  @def_group CPHA
 */

#define CPHA_FIRST			((uint32_t) (0x00000000))
#define CPHA_SECOND			((uint32_t) (0x00000001))

/*
 * @def_group CPOL
 */
#define CPOL_LOW			((uint32_t) (0x00000000))
#define CPOL_HIGH			((uint32_t) (0x00000002))

/*
 *  @def_group MSTR
 */
#define MSTR_SLAVE			((uint32_t) (0x00000000))
#define MSTR_MASTER			((uint32_t) (0x00000004))

/*
 * @def_group BaudRate
 */
#define SPI_BR_DIV2				((uint32_t) (0x00000000))		//00 0000
#define SPI_BR_DIV4				((uint32_t) (0x00000008)) 		//00 1000
#define SPI_BR_DIV8				((uint32_t) (0x00000010))		//01 0000
#define SPI_BR_DIV16			((uint32_t) (0x00000018))		//01 1000
#define SPI_BR_DIV32			((uint32_t) (0x00000020))		//10 0000
#define SPI_BR_DIV64			((uint32_t) (0x00000028))		//10 1000
#define SPI_BR_DIV128			((uint32_t) (0x00000030))		//11 0000
#define SPI_BR_DIV256			((uint32_t) (0x00000038))		//11 1000

/*
 *  @def_group FrameFormat
 */
#define SPI_FF_MSB				((uint32_t) (0x00000000))
#define SPI_FF_LSB				((uint32_t) (0x00000080))


/*
 * @def_group DataFrameFormat
 */

#define SPI_FF_8bit				((uint32_t) (0x00000000))
#define SPI_FF_16bit			((uint32_t) (0x00000800))

/*
 * @def_group SSMCMD
 */
#define SPI_SSM_DISABLE			((uint32_t) (0x00000000))
#define SPI_SSM_ENABLE			((uint32_t) (0x00000200))

/*
 * @def_group BusConfig
 */
#define SPI_FULLDUPLEX		 	((uint32_t) (0x00000000))
#define SPI_FULLDUPLEX_R		((uint32_t) (0x00000400))
#define SPI_HALFDUPLEX_R		((uint32_t) (0x00008000))
#define SPI_HALFDUPLEX_T		((uint32_t) (0x0000C000))

typedef struct{

	uint32_t CPHA;					/*!< @def_group CPHA */
	uint32_t CPOL;					/*!< @def_group CPOL */
	uint32_t MasterSelection;		/*!< @def_group MSTR */
	uint32_t Baudrate;				/*!< @def_group BaudRate */
	uint32_t FrameFormat;			/*!< @def_group FrameFormat */
	uint32_t SSM;					/*!< @def_group SSMCMD		*/
	uint32_t DFF;					/*!< @def_group DataFrameFormat */
	uint32_t BIDMode;				/*!< @def_group BusConfig */

}SPI_InitTypeDef_t;

typedef struct __SPI_HandleTypedef_t
{

	SPI_InitTypeDef_t Init;
	SPI_Typedef_t *Instance;
	uint8_t *pTxDataAddr;
	uint16_t TxDataSize;
	uint8_t busStateTx;
	void(*TxISRFunction)(struct __SPI_HandleTypedef_t *SPI_Handle);
	uint8_t *pRxDataAddr;
	uint16_t RxDataSize;
	uint8_t busStateRx;
	void(*RxISRFunction)(struct __SPI_HandleTypedef_t *SPI_Handle);


}SPI_HandleTypedef_t;

typedef enum{
	SPI_FLAG_RESET = 0x0U,
	SPI_FLAG_SET = !(SPI_FLAG_RESET)

}SPI_FlagStatus_t;


void SPI_Init(SPI_HandleTypedef_t *SPI_Handle);
void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle, FunctionalState_t stateOfSPI);
void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pdata, uint16_t sizeOfData);
void SPI_ReceiveData(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pbuff, uint16_t sizeOfData);
SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypedef_t *SPI_Handle, uint16_t flag);
void SPI_TransmitData_IT(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pdata, uint16_t sizeOfData);
void SPI_ReceivetData_IT(SPI_HandleTypedef_t *SPI_Handle, uint8_t*pbuff, uint16_t sizeOfData);
void SPI_InterruptHandler(SPI_HandleTypedef_t *SPI_Handle);

#endif /* INC_SPI_H_ */
