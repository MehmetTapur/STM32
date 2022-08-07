/*
 * DHT11.h
 *
 *  Created on: May 24, 2022
 *      Author: ps
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include "main.h"
#include <math.h>


/**************SOME REQUIRED MACROS***********************/

#define ResponseTime      20
#define MaxTimeForZero    40
#define TimeOutt          0
#define MaxPinNo          16
#define highTime          80

/**************PIN MACROS***********************/

#define PIN_NO0      0
#define PIN_NO1      1
#define PIN_NO2      2
#define PIN_NO3      3
#define PIN_NO4      4

/****************************************DHT11 API'S**********************************************/


void StartSignal(GPIO_TypeDef* gpiox,uint8_t PinNo);
uint8_t GetResponse(GPIO_TypeDef* gpiox,uint16_t PinNo);
void GetResults(GPIO_TypeDef* gpiox,uint8_t* temperature,uint8_t* humidity,uint16_t PinNo);







#endif /* INC_DHT11_H_ */
