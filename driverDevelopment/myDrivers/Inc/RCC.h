


#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"



#define RCC_GPIOA_CLOCK_ENABLE()		do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->AHB1ENR ,RCC_AHB1_GPIOAEN);			\
											tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOAEN);	\
											UNUSED(tempValue);									\
											}while(0)
#define RCC_GPIOB_CLOCK_ENABLE()		do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOBEN);				\
											tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOBEN);	\
											UNUSED(tempValue);									\
											}while(0)
#define RCC_GPIOC_CLOCK_ENABLE()		do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOCEN);				\
											tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOCEN);	\
											UNUSED(tempValue);									\
											}while(0)
#define RCC_GPIOD_CLOCK_ENABLE()		do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIODEN);				\
											tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIODEN);	\
											UNUSED(tempValue);									\
											}while(0)



#define RCC_SYSCFG_CLOCK_ENABLE()		do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->APB2ENR,RCC_APB2_SYSCFG);				\
											tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2_SYSCFG);	\
											UNUSED(tempValue);									\
											}while(0)


#define RCC_SPI1_CLOCK_ENABLE()		 	do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->APB2ENR,RCC_APB2_SPI1);				\
											tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2_SPI1);	\
											UNUSED(tempValue);									\
											}while(0)

#define RCC_SPI2_CLOCK_ENABLE()		 	do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->APB1ENR,RCC_APB2_SPI2);				\
											tempValue=READ_BIT(RCC->APB1ENR,RCC_APB2_SPI2);	\
											UNUSED(tempValue);									\
											}while(0)

#define RCC_SPI3_CLOCK_ENABLE()		 	do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->APB1ENR,RCC_APB2_SPI3);				\
											tempValue=READ_BIT(RCC->APB1ENR,RCC_APB2_SPI3);	\
											UNUSED(tempValue);									\
											}while(0)

#define RCC_SPI4_CLOCK_ENABLE()		 	do{	uint32_t tempValue=0;								\
											SET_BIT(RCC->APB2ENR,RCC_APB2_SPI4);				\
											tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2_SPI4);	\
											UNUSED(tempValue);									\
											}while(0)


#define RCC_GPIOA_CLOCK_DISABLE()		RESET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOAEN)
#define RCC_GPIOB_CLOCK_DISABLE()		RESET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOBEN)
#define RCC_GPIOC_CLOCK_DISABLE()		RESET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOCEN)
#define RCC_GPIOD_CLOCK_DISABLE()		RESET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIODEN)


#define RCC_SYSCFG_CLOCK_DISABLE()		RESET_BIT(RCC->APB2ENR,RCC_APB2_SYSCFG)

#define RCC_SPI1_CLOCK_DISABLE()		RESET_BIT(RCC->APB2ENR,RCC_APB2_SPI1)
#define RCC_SPI2_CLOCK_DISABLE()		RESET_BIT(RCC->APB1ENR,RCC_APB2_SPI2)
#define RCC_SPI3_CLOCK_DISABLE()		RESET_BIT(RCC->APB1ENR,RCC_APB2_SPI3)
#define RCC_SPI4_CLOCK_DISABLE()		RESET_BIT(RCC->APB2ENR,RCC_APB2_SPI4)





#endif /* INC_RCC_H_ */
