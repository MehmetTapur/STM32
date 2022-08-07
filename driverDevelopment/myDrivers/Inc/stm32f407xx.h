/*
 * stm32f407xx.h
 *
 *  Created on: Feb 18, 2022
 *      Author: TAPUR
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define NVIC_ISER0      		((uint32_t *)(0xE000E100))

#define __IO volatile

#define SET_BIT(REG,BIT)		( (REG) |= (BIT)  )
#define RESET_BIT(REG,BIT)	    ( (REG) &= ~(BIT) )
#define READ_BIT(REG,BIT)		( (REG) &  (BIT)  )

#define UNUSED(x)				(void)x

typedef enum{
	DISABLE = 0,
	ENABLE = !(DISABLE)

}FunctionalState_t;

/*
 *		Memory Bases Address
 */

#define FLASH_BASE_ADDR		(0x08000000UL)
#define SRAM1_BASE_ADDR		(0x20000000UL)
#define SRAM2_BASE_ADDR		(0x2001C000UL)


/*
 * 		Peripheral Base Address
 */

#define PERIPH_BASE_ADDR	(0x40000000UL)

#define APB1_BASE_ADDR		PERIPH_BASE_ADDR
#define APB2_BASE_ADDR		(PERIPH_BASE_ADDR+0x00010000UL)
#define AHB1_BASE_ADDR		(PERIPH_BASE_ADDR+0x00020000UL)
#define AHB2_BASE_ADDR		(PERIPH_BASE_ADDR+0x10000000UL)


/*
 * APB1 PERIPHERAL BASE ADDRESSES
 */

#define TIM2_BASE_ADDR		(APB1_BASE_ADDR+0x0000UL)
#define TIM3_BASE_ADDR		(APB1_BASE_ADDR+0x0400UL)
#define TIM4_BASE_ADDR		(APB1_BASE_ADDR+0x0800UL)

#define SPI2_BASE_ADDR		(APB1_BASE_ADDR+0x3800UL)
#define SPI3_BASE_ADDR		(APB1_BASE_ADDR+0x3C00UL)

#define USART2_BASE_ADDR	(APB1_BASE_ADDR+0x4400UL)
#define USART3_BASE_ADDR	(APB1_BASE_ADDR+0x4800UL)
#define UART4_BASE_ADDR		(APB1_BASE_ADDR+0x4C00UL)

#define I2C1_BASE_ADDR		(APB1_BASE_ADDR+0x5400UL)
#define I2C2_BASE_ADDR		(APB1_BASE_ADDR+0x5800UL)
#define I2C3_BASE_ADDR		(APB1_BASE_ADDR+0x5C00UL)

/*
 * APB2 PERIPHERAL BASE ADDRESSES
 */

#define TIM1_BASE_ADDR		(APB2_BASE_ADDR+0x0000UL)
#define TIM8_BASE_ADDR		(APB2_BASE_ADDR+0x0400UL)

#define USART1_BASE_ADDR	(APB2_BASE_ADDR+0x1000UL)
#define USART6_BASE_ADDR	(APB2_BASE_ADDR+0x1400UL)

#define SPI1_BASE_ADDR		(APB2_BASE_ADDR+0x3000UL)
#define SPI4_BASE_ADDR		(APB2_BASE_ADDR+0x3400UL)

#define SYSCFG_BASE_ADDR	(APB2_BASE_ADDR+0x3800UL)

#define EXTI_BASE_ADDR		(APB2_BASE_ADDR+0x3C00UL)

/*
 * AHB1 PERIPHERAL BASE ADDRESSES
 */

#define GPIOA_BASE_ADDR		(AHB1_BASE_ADDR+0x0000UL)
#define GPIOB_BASE_ADDR		(AHB1_BASE_ADDR+0x0400UL)
#define GPIOC_BASE_ADDR		(AHB1_BASE_ADDR+0x0800UL)
#define GPIOD_BASE_ADDR		(AHB1_BASE_ADDR+0x0C00UL)
#define GPIOE_BASE_ADDR		(AHB1_BASE_ADDR+0x1000UL)

#define RCC_BASE_ADDR		(AHB1_BASE_ADDR+0x3800UL)


/*
 * PERIPHERAL STRUCTURE DEFINITIONS
 */

typedef struct{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];

}GPIO_Typedef_t;

typedef struct{

	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t REVERSED1;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t REVERSED2[2];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	__IO uint32_t REVERSED3;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t REVERSED4[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
	__IO uint32_t REVERSED5;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
	__IO uint32_t REVERSED6[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t REVERSED7[2];
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR;

}RCC_Typedef_t;


typedef struct{

	__IO uint32_t IMR;
	__IO uint32_t EMR;
	__IO uint32_t RTSR;
	__IO uint32_t FTSR;
	__IO uint32_t SWIER;
	__IO uint32_t PR;

}EXTI_Typedef_t;

typedef struct{

	__IO uint32_t MEMRMP;
	__IO uint32_t PMC;
	__IO uint32_t CR[4];
	__IO uint32_t FTSR;
	__IO uint32_t REVERSED[2];
	__IO uint32_t CMPCR;

}SYSCFG_Typedef_t;

typedef struct{
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t SR;
	__IO uint32_t DR;
	__IO uint32_t CRCPR;
	__IO uint32_t RXCRCR;
	__IO uint32_t TXCRCR;
	__IO uint32_t I2SCFGR;
	__IO uint32_t I2SPR;

}SPI_Typedef_t;





#define GPIOA 			( (GPIO_Typedef_t * )(GPIOA_BASE_ADDR)  )
#define GPIOB 			( (GPIO_Typedef_t * )(GPIOB_BASE_ADDR)  )
#define GPIOC 			( (GPIO_Typedef_t * )(GPIOC_BASE_ADDR)  )
#define GPIOD 			( (GPIO_Typedef_t * )(GPIOD_BASE_ADDR)  )
#define GPIOE 			( (GPIO_Typedef_t * )(GPIOE_BASE_ADDR)  )


#define RCC				( (RCC_Typedef_t * )(RCC_BASE_ADDR)	    )

#define EXTI			( (EXTI_Typedef_t * )(EXTI_BASE_ADDR)   )

#define SYSCFG			( (SYSCFG_Typedef_t *)(SYSCFG_BASE_ADDR))

#define SPI1			( (SPI_Typedef_t *)(SPI1_BASE_ADDR)		)
#define SPI2			( (SPI_Typedef_t *)(SPI2_BASE_ADDR)		)
#define SPI3			( (SPI_Typedef_t *)(SPI3_BASE_ADDR)		)
#define SPI4			( (SPI_Typedef_t *)(SPI4_BASE_ADDR)		)

/*
 *	 Bit Definitions
 */

#define RCC_AHB1_GPIOAEN_Pos			(0U)
#define RCC_AHB1_GPIOAEN_Msk			(0x1<<RCC_AHB1_GPIOAEN_Pos)
#define RCC_AHB1_GPIOAEN		   	     RCC_AHB1_GPIOAEN_Msk

#define RCC_AHB1_GPIOBEN_Pos			(1U)
#define RCC_AHB1_GPIOBEN_Msk			(0x1<<RCC_AHB1_GPIOBEN_Pos)
#define RCC_AHB1_GPIOBEN				RCC_AHB1_GPIOBEN_Msk

#define RCC_AHB1_GPIOCEN_Pos			(2U)
#define RCC_AHB1_GPIOCEN_Msk			(0x1<<RCC_AHB1_GPIOCEN_Pos)
#define RCC_AHB1_GPIOCEN				RCC_AHB1_GPIOCEN_Msk

#define RCC_AHB1_GPIODEN_Pos			(3U)
#define RCC_AHB1_GPIODEN_Msk			(0x1<<RCC_AHB1_GPIODEN_Pos)
#define RCC_AHB1_GPIODEN				RCC_AHB1_GPIODEN_Msk


#define RCC_APB2_SYSCFG_Pos				(14U)
#define RCC_APB2_SYSCFG_Msk				(0x1<<RCC_APB2_SYSCFG_Pos)
#define RCC_APB2_SYSCFG					RCC_APB2_SYSCFG_Msk



#define RCC_APB2_SPI1_Pos				(12U)
#define RCC_APB2_SPI1_Msk				(0x1<<RCC_APB2_SPI1_Pos)
#define RCC_APB2_SPI1				    RCC_APB2_SPI1_Msk

#define RCC_APB2_SPI4_Pos				(13U)
#define RCC_APB2_SPI4_Msk				(0x1<<RCC_APB2_SPI4_Pos)
#define RCC_APB2_SPI4				    RCC_APB2_SPI4_Msk

#define RCC_APB1_SPI2_Pos				(14U)
#define RCC_APB1_SPI2_Msk				(0x1<<RCC_APB1_SPI2_Pos)
#define RCC_APB1_SPI2				    RCC_APB1_SPI2_Msk

#define RCC_APB1_SPI3_Pos				(15U)
#define RCC_APB1_SPI3_Msk				(0x1<<RCC_APB1_SPI3_Pos)
#define RCC_APB1_SPI3				    RCC_APB1_SPI3_Msk


#define SPI_CRC1_SPE					(6U)
#define SPI_CRC1_DFF					(11U)

#define SPI_CR2_TXEIE					(7U)
#define SPI_CR2_RXNEIE					(6U)

#define SPI_SR_RXNE						(0U)
#define SPI_SR_TXE						(1U)
#define SPI_SR_BSY						(7U)



#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"















#endif /* INC_STM32F407XX_H_ */
