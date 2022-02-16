/*
 * RCC_Private.h
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*--------------Mapping Registers-------------*/
#define RCC_U32_BASE_ADDRESS          0x40021000
/*----Control Register----*/
#define RCC_U32_CR_REG       		  *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x00))
/*----Clock configuration register----*/
#define RCC_U32_CFGR_REG      	      *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x04))
/*----Clock interrupt register----*/
#define RCC_U32_CIR_REG               *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x08))
/*----APB2 peripheral reset register----*/
#define RCC_U32_APB2RSTR_REG          *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x0C))
/*----APB1 peripheral reset register----*/
#define RCC_U32_APB1RSTR_REG          *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x10))
/*----AHB peripheral clock enable register----*/
#define RCC_U32_AHBENR_REG            *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x14))
/*----APB2 peripheral clock enable register----*/
#define RCC_U32_APB2ENR_REG           *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x18))
/*----APB1 peripheral clock enable register----*/
#define RCC_U32_APB1ENR_REG           *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x1C))
/*----Control Register----*/
#define RCC_U32_BDCR_REG    	      *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x20))
/*----Control Register----*/
#define RCC_U32_CSR_REG          	  *((volatile u32 *)(RCC_U32_BASE_ADDRESS+0x24))

#endif /* RCC_PRIVATE_H_ */

