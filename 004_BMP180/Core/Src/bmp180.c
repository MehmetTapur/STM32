/*
 * bmp180.c
 *
 *  Created on: Mar 27, 2022
 *      Author: ps
 */

#ifndef SRC_BMP180_C_
#define SRC_BMP180_C_

#include "bmp180.h"
extern I2C_HandleTypeDef hi2c1;


void BMP180_init(void)
{
	if(HAL_I2C_IsDeviceReady(&hi2c1, BMP180_SLAVE_ADDR, 1, 10000) != HAL_OK)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	}
	 BMP180_Get_Calibration();



}
void BMP180_Get_Calibration()
{
	uint8_t bmp180_calibArray[CALIBRATION_SIZE];
	HAL_I2C_Mem_Read(&hi2c1, BMP180_SLAVE_ADDR, 0xAA, 1, &bmp180_calibArray[0], CALIBRATION_SIZE, 100000);
	int i=0;
	AC1 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	AC2 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	AC3 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	AC4 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	AC5 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	AC6 = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	B1 	= (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	B2  = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	MB	= (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	MC 	= (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;
	MD  = (bmp180_calibArray[i]<<8)|(bmp180_calibArray[i+1]); i+=2;


}

float BMP180_TemperatureValue(void)
{
	BMP180_Read_UncompensatedTempValue();

	X1 = ((UT-AC6)*AC5)/32768;
	X2 = ((MC*2048)/(X1+MD));
	B5 = (X1+X2);
	T =	 ((B5+8)/16);
	float Temperature = 0;

	Temperature =(float) T/10.0;
	return Temperature;

}
void BMP180_Read_UncompensatedTempValue(void)
{
	uint8_t rxBuff[2] = {0};
	uint8_t txBuff[1] = {0};
	txBuff[0] = 0x2E;
	HAL_I2C_Mem_Write(&hi2c1, BMP180_SLAVE_ADDR, 0xF4, 1, txBuff, 1, 100000);
	HAL_Delay(5);

	HAL_I2C_Mem_Read(&hi2c1, BMP180_SLAVE_ADDR, 0xF6, 1, &rxBuff[0], 2, 100000);

	UT = (int16_t) ((rxBuff[0] << 8) | (rxBuff[1]));

}

#endif /* SRC_BMP180_C_ */
