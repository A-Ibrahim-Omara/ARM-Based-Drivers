/*
 * RCC_Cfg.h
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_
/*CLK source*/
#define RCC_SYS_CLK_SOURCE  RCC_SYS_CLK_PLL
/*CLK source ready pin*/
#define RCC_CLK_READY_PIN   RCC_PLLRDY_PIN25
/*Buses prescaler*/
#define AHB_PRESCALER      RCC_AHB_U16_PRESCALER_2
#define APB1_PRESCALER     RCC_APB1_U8_PRESCALER_2
#define APB2_PRESCALER	   RCC_APB2_U8_PRESCALER_2
/*PLL source*/
#define RCC_PLL_SOURCE     	   RCC_PLL_SRC_HSE
/*PLL Mul Factor*/
#define RCC_PLL_MUL_FACTOR     RCC_PLLMUL_2


#endif /* RCC_CFG_H_ */
