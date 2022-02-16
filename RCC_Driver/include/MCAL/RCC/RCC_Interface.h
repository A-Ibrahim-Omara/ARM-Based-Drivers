/*
 * RCC_Interface.h
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define CLK_READY_TIME_OUT   50000

/*-------CLK READY PINS-------*/
#define RCC_HSIRDY_PIN1      1
#define RCC_HSERDY_PIN17     17
#define RCC_PLLRDY_PIN25     25
/*-------CLK TYPE SELECTION-------*/
#define RCC_SYS_CLK_HSI				0
#define RCC_SYS_CLK_HSE				1
#define RCC_SYS_CLK_PLL				2
/*-------PLL SOURCE SELECTION-------*/
#define RCC_PLL_SRC_BIT				16
#define RCC_PLL_HSE_DIV_BIT			17

#define RCC_PLL_SRC_HSI     		0
#define RCC_PLL_SRC_HSE   			1
#define RCC_PLL_SRC_HSE_DIV2   		2

/*-------PLL MULFACTOR SELECION-------*/
#define RCC_PLL_MUL_BIT				18
#define RCC_PLLMUL_2				2
#define RCC_PLLMUL_3				3
#define RCC_PLLMUL_4				4
#define RCC_PLLMUL_5				5
#define RCC_PLLMUL_6				6
#define RCC_PLLMUL_7				7
#define RCC_PLLMUL_8				8
#define RCC_PLLMUL_9				9
#define RCC_PLLMUL_10				10
#define RCC_PLLMUL_11				11
#define RCC_PLLMUL_12				12
#define RCC_PLLMUL_13				13
#define RCC_PLLMUL_14				14
#define RCC_PLLMUL_15				15
#define RCC_PLLMUL_16				16
/*------AHB PRESCALER------------*/
#define RCC_AHB_U16_PRESCALER_1     1
#define RCC_AHB_U16_PRESCALER_2     2
#define RCC_AHB_U16_PRESCALER_4		4
#define RCC_AHB_U16_PRESCALER_8		8
#define RCC_AHB_U16_PRESCALER_16	16
#define RCC_AHB_U16_PRESCALER_64	64
#define RCC_AHB_U16_PRESCALER_128	128
#define RCC_AHB_U16_PRESCALER_256	256
#define RCC_AHB_U16_PRESCALER_512	512
/*------APB1 PRESCALER------------*/
#define RCC_APB1_U8_PRESCALER_1     1
#define RCC_APB1_U8_PRESCALER_2     2
#define RCC_APB1_U8_PRESCALER_4	    4
#define RCC_APB1_U8_PRESCALER_8	    8
#define RCC_APB1_U8_PRESCALER_16    16
/*------APB2 PRESCALER------------*/
#define RCC_APB2_U8_PRESCALER_1     1
#define RCC_APB2_U8_PRESCALER_2     2
#define RCC_APB2_U8_PRESCALER_4 	4
#define RCC_APB2_U8_PRESCALER_8		8
#define RCC_APB2_U8_PRESCALER_16    16
/*-------PERIPHERALS BUSES-----------*/
#define RCC_AHB			1
#define RCC_APB1		2
#define RCC_APB2		3
/*-------AHB PERIPHERALS-----------*/
#define RCC_PERIPHERAL_DMA1         0
#define RCC_PERIPHERAL_DMA2         1
#define RCC_PERIPHERAL_SRAM         2
#define RCC_PERIPHERAL_FLITF        4
#define RCC_PERIPHERAL_CRCE         6
#define RCC_PERIPHERAL_FSMC         8
#define RCC_PERIPHERAL_SDIO         10
/*-------APB1 PERIPHERALS-----------*/
#define RCC_PERIPHERAL_TIM2         0
#define RCC_PERIPHERAL_TIM3         1
#define RCC_PERIPHERAL_TIM4         2
#define RCC_PERIPHERAL_TIM5         3
#define RCC_PERIPHERAL_TIM6         4
#define RCC_PERIPHERAL_TIM7         5
#define RCC_PERIPHERAL_TIM12        6
#define RCC_PERIPHERAL_TIM13        7
#define RCC_PERIPHERAL_TIM14        8
#define RCC_PERIPHERAL_WWDGEN       11
#define RCC_PERIPHERAL_SPI2         14
#define RCC_PERIPHERAL_SPI3         15
#define RCC_PERIPHERAL_USART2       17
#define RCC_PERIPHERAL_USART3       18
#define RCC_PERIPHERAL_USART4       19
#define RCC_PERIPHERAL_USART5       20
#define RCC_PERIPHERAL_I2C1         21
#define RCC_PERIPHERAL_I2C2         22
#define RCC_PERIPHERAL_USB          23
#define RCC_PERIPHERAL_CAN          25
#define RCC_PERIPHERAL_BKP          27
#define RCC_PERIPHERAL_PWR          28
#define RCC_PERIPHERAL_DAC          29
/*-------APB2 PERIPHERALS-----------*/
#define RCC_PERIPHERAL_AFIO         0
#define RCC_PERIPHERAL_IOPA         2
#define RCC_PERIPHERAL_IOPB         3
#define RCC_PERIPHERAL_IOPC         4
#define RCC_PERIPHERAL_IOPD         5
#define RCC_PERIPHERAL_IOPE         6
#define RCC_PERIPHERAL_IOPF         7
#define RCC_PERIPHERAL_IOPG         8
#define RCC_PERIPHERAL_ADC1         9
#define RCC_PERIPHERAL_ADC2         10
#define RCC_PERIPHERAL_TIM1         11
#define RCC_PERIPHERAL_SPI1         12
#define RCC_PERIPHERAL_TIM8         13
#define RCC_PERIPHERAL_USART        14
#define RCC_PERIPHERAL_ADC3         15
#define RCC_PERIPHERAL_TIM9         19
#define RCC_PERIPHERAL_TIM10        20
#define RCC_PERIPHERAL_TIM11        21

/*--------CLK STATUS-------------------*/
#define RCC_CLK_ON        1
#define RCC_CLK_OFF       0
/*---------PERIPHERAL STATUS-----------*/
#define RCC_PERIPHERAL_ENABLE       1
#define RCC_PERIPHERAL_DISABLE      0

/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_CheckReady.
*Input Arg: Clk ready bit of the source type in CR Reg.
*Return   : check_type enum data type ,check_OK when source ready and check_NOK when source Not ready.
*Desc     : This function is Async.function that checks if the clk is ready to be used or not
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
check_type MRCC_CheckReady(u8 copy_u8ClkType);

/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_SetClkSource
*Input Arg: clk source , 3 options--> RCC_SYS_CLK_HSE,RCC_SYS_CLK_HSI,RCC_SYS_CLK_PLL
*Return   : it returns a varible of check_type enum data type.
*Desc     : choose the Clk Source
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
check_type MRCC_SetClkSource(u8 copy_u8Clk);

/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_voidSetClkStatus
*Input Arg: 1- ClkSource 3options RCC_SYS_CLK_HSE,RCC_SYS_CLK_HSI,RCC_SYS_CLK_PLL
*           2- it's status RCC_CLK_ON/RCC_CLK_OFF,
*Return   : variable of type enum check_type
*Desc     : func to turn on/off the clk of the source
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
void MRCC_voidSetClkStatus (u8 copy_u8CLkSource,u8 copy_u8Status);

/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_voidSetClkBusesPrescaler
*Input Arg: prescaler of Buses , AHP,APB2 and APB1.
*Return   : void
*Desc     : Func to set the prescaler of the buses.
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
void MRCC_voidSetClkBusesPrescaler (u16 AHP_u16_prescaler, u8 APB1_u8_prescaler, u8 APB2_u8_prescaler);
/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_SetPeripheralConfiguration
*Input Arg: 1-The peripheral name
*           2- Peripheral_Bus
*           3- Peripheral_Status
*Return   : void
*Desc     : Fun to turn on/off the clk of the peripheral.
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
void MRCC_SetPeripheralConfiguration(u8 Peripheral_Name, u8 Peripheral_Bus,u8 Peripheral_Status);
/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MRCC_Init
*Input Arg: void
*Return   : void
*Desc     : Fun to initiate th RCC peripheral
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
void MRCC_Init(void);
#endif /* RCC_INTERFACE_H_ */
