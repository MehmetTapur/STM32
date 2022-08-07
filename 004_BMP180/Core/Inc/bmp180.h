/*
 * bmp180.h
 *
 *  Created on: Mar 27, 2022
 *      Author: ps
 */

#ifndef INC_BMP180_H_
#define INC_BMP180_H_

#include "main.h"
#include <math.h>

#define BMP180_SLAVE_ADDR	0xEE
#define CALIBRATION_SIZE	22


// Defines according to the datsheet
short AC1 = 0;
short AC2 = 0;
short AC3 = 0;
unsigned short AC4 = 0;
unsigned short AC5 = 0;
unsigned short AC6 = 0;
short B1 = 0;
short B2 = 0;
short MB = 0;
short MC = 0;
short MD = 0;

/********************/
long UT = 0;
short oss = 0;
long UP = 0;
long X1 = 0;
long X2 = 0;
long X3 = 0;
long B3 = 0;
long B5 = 0;
long T = 0;
unsigned long B4 = 0;
long B6 = 0;
unsigned long B7 = 0;

/*******************/
long Press = 0;
long Temp = 0;

#define atmPress 101325 //Pa


void BMP180_init(void);
void BMP180_Get_Calibration(void);
void BMP180_Read_UncompensatedTempValue(void);
float BMP180_TemperatureValue(void);




#endif /* INC_BMP180_H_ */
