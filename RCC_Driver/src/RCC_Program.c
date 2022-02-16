/*
 * RCC_Program.c
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Ibrahim
 */

#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_type.h"

#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Cfg.h"


check_type MRCC_CheckReady(u8 copy_u8ClkType)
{
	/*check CLK ready or not*/
	check_type check_return=check_OK;
	u32 local_u32TimeOut=0;
	switch(copy_u8ClkType)
	{
	case RCC_HSIRDY_PIN1:
						while(GET_BIT(RCC_U32_CR_REG,RCC_HSIRDY_PIN1)==check_NOK)
						{
							if(local_u32TimeOut==CLK_READY_TIME_OUT)
							{
								check_return=check_NOK;
								break;
							}
						}
						break;
	case RCC_HSERDY_PIN17:
						while(GET_BIT(RCC_U32_CR_REG,RCC_HSERDY_PIN17)==check_NOK)
						{
							if(local_u32TimeOut==CLK_READY_TIME_OUT)
							{
								check_return=check_NOK;
								break;
							}
						}
						break;
	case RCC_PLLRDY_PIN25:
						while(GET_BIT(RCC_U32_CR_REG,RCC_PLLRDY_PIN25)==check_NOK)
						{
							if(local_u32TimeOut==CLK_READY_TIME_OUT)
							{
								check_return=check_NOK;
								break;
							}
						}
						break;
	default:
			check_return=check_NOK;
						break;

	}
	return check_return;
}

check_type MRCC_SetClkSource(u8 copy_u8Clk)
{
	check_type  check_return=check_NOK;
	if( copy_u8Clk<=RCC_SYS_CLK_PLL)
	{
		RCC_U32_CFGR_REG&=0xFFFFFFFC;
		RCC_U32_CFGR_REG|=(u32)(copy_u8Clk);
		check_return =check_OK;
	}
	return check_return;
}

void MRCC_voidSetClkStatus (u8 copy_u8CLkSource,u8 copy_u8Status)
{
	if(copy_u8CLkSource<=RCC_SYS_CLK_PLL && copy_u8Status<2)
	{
		switch(copy_u8CLkSource)
		{
			case RCC_SYS_CLK_HSI:
							if(copy_u8Status==RCC_CLK_ON)
							{
							SET_BIT(RCC_U32_CR_REG,(RCC_HSIRDY_PIN1-1));
							}
							else if(copy_u8Status==RCC_CLK_OFF)
							{
							CLR_BIT(RCC_U32_CR_REG,(RCC_HSIRDY_PIN1-1));
							}
								break;
			case RCC_SYS_CLK_HSE:
			                if(copy_u8Status==RCC_CLK_ON)
			                {
			                SET_BIT(RCC_U32_CR_REG,(RCC_HSERDY_PIN17-1));
			                }
			                else if(copy_u8Status==RCC_CLK_OFF)
			                {
			                CLR_BIT(RCC_U32_CR_REG,(RCC_HSERDY_PIN17-1));
			                }
								break;
			case RCC_SYS_CLK_PLL:
                            if(copy_u8Status==RCC_CLK_ON)
                            {
                            SET_BIT(RCC_U32_CR_REG,(RCC_PLLRDY_PIN25-1));
                            }
                            else if(copy_u8Status==RCC_CLK_OFF)
                            {
                            CLR_BIT(RCC_U32_CR_REG,(RCC_PLLRDY_PIN25-1));
                            }
								break;
		}
	}

}
void MRCC_voidSetClkBusesPrescaler (u16 AHB_u16_prescaler, u8 APB1_u8_prescaler, u8 APB2_u8_prescaler)
{
	/*set the prescalers of the buses*/
	RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFFFF8FF) | (APB1_u8_prescaler<<8);
	RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFFFC7FF) | (APB2_u8_prescaler<<11);
	RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFFFFF0F) | (AHB_u16_prescaler<<4);
}
void MRCC_SetPLLConfiguration(u8 PLL_u8_Source, u8 PLL_u8_MulFactor)
{
	switch(PLL_u8_Source)
	{
	case RCC_PLL_SRC_HSI:
		/*use HSI*/
		CLR_BIT(RCC_U32_CFGR_REG,RCC_PLL_SRC_BIT);
		/*mul factor*/
		RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFC3FFFF)| (PLL_u8_MulFactor<<RCC_PLL_MUL_BIT);
		break;

	case RCC_PLL_SRC_HSE:
		/*use HSE*/
		SET_BIT(RCC_U32_CFGR_REG,RCC_PLL_SRC_BIT);
		/*HSE NO divisor*/
		CLR_BIT(RCC_U32_CFGR_REG,RCC_PLL_HSE_DIV_BIT);
		/*mul factor*/
		RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFC3FFFF)| (PLL_u8_MulFactor<<RCC_PLL_MUL_BIT);
		break;
	case RCC_PLL_SRC_HSE_DIV2:
			/*use HSE*/
			SET_BIT(RCC_U32_CFGR_REG,RCC_PLL_SRC_BIT);
			/*HSE divisor / 2 */
			SET_BIT(RCC_U32_CFGR_REG,RCC_PLL_HSE_DIV_BIT);
			/*mul factor*/
			RCC_U32_CFGR_REG = (RCC_U32_CFGR_REG&0xFFC3FFFF)| (PLL_u8_MulFactor<<RCC_PLL_MUL_BIT);
			break;
	}
}

void MRCC_SetPeripheralConfiguration(u8 Peripheral_Name, u8 Peripheral_Bus,u8 Peripheral_Status)
{
	switch(Peripheral_Bus)
	{
	case RCC_AHB :
			CLR_BIT(RCC_U32_AHBENR_REG,Peripheral_Name);
			RCC_U32_AHBENR_REG|= RCC_U32_AHBENR_REG & (Peripheral_Status<<Peripheral_Name);
		break;
	case RCC_APB2 :
			CLR_BIT(RCC_U32_APB2ENR_REG,Peripheral_Name);
			RCC_U32_APB2ENR_REG|= (Peripheral_Status<<Peripheral_Name);
		break;
	case RCC_APB1 :
			CLR_BIT(RCC_U32_APB1ENR_REG,Peripheral_Name);
			RCC_U32_APB1ENR_REG|= RCC_U32_APB1ENR_REG & (Peripheral_Status<<Peripheral_Name);
		break;
	}
}

void MRCC_Init(void)
{
#if (RCC_SYS_CLK_SOURCE==RCC_SYS_CLK_HSE)
	/*Turn HSE ON*/
	MRCC_voidSetClkStatus(RCC_SYS_CLK_SOURCE,RCC_CLK_ON);
	/*Check HSE Ready*/
	if(MRCC_CheckReady(RCC_CLK_READY_PIN))
	{	/*SET HSE AS a Source CLK*/
		if(MRCC_SetClkSource(RCC_SYS_CLK_HSE))
		{
			/*Turn PLL & HSI OFF*/
			MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_OFF);
			MRCC_voidSetClkStatus(RCC_SYS_CLK_HSI,RCC_CLK_OFF);
			/*Buses Prescaler*/
			MRCC_voidSetClkBusesPrescaler(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
		}
	}
#elif(RCC_SYS_CLK_SOURCE==RCC_SYS_CLK_HSI)
	/*Turn HSI ON*/
	MRCC_voidSetClkStatus(RCC_SYS_CLK_SOURCE,RCC_CLK_ON);
	/*Check HSI Ready*/
	if(MRCC_CheckReady(RCC_CLK_READY_PIN))
	{	/*SET HSI AS a Source CLK*/
		if(MRCC_SetClkSource(RCC_SYS_CLK_HSI))
		{
			/*Turn PLL & HSE OFF*/
			MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_OFF);
			MRCC_voidSetClkStatus(RCC_SYS_CLK_HSE,RCC_CLK_OFF);
			/*Buses Prescaler*/
			MRCC_voidSetClkBusesPrescaler(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
		}
	}
#elif(RCC_SYS_CLK_SOURCE==RCC_SYS_CLK_PLL)
#if(RCC_PLL_SOURCE == RCC_PLL_SRC_HSI)
	/*Turn HSI ON*/
	MRCC_voidSetClkStatus(RCC_SYS_CLK_HSI,RCC_CLK_ON);
	/*Check HSI Ready*/
	if(MRCC_CheckReady(RCC_HSIRDY_PIN1))
	{	/*SET HSI AS a Source CLK*/
		if(MRCC_SetClkSource(RCC_SYS_CLK_HSI))
		{
			/*Turn PLL*/
			MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_OFF);
			/*PLL CFG*/
			MRCC_SetPLLConfiguration(RCC_PLL_SOURCE, RCC_PLL_MUL_FACTOR);
			/*Buses Prescaler*/
			MRCC_voidSetClkBusesPrescaler(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
			/*Turn PLL ON*/
			MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_ON);
			/*Check PLL Ready*/
			if(MRCC_CheckReady(RCC_PLLRDY_PIN25))
			{
				if(MRCC_SetClkSource(RCC_SYS_CLK_PLL))
				{	/*Turn HSE ON*/
					MRCC_voidSetClkStatus(RCC_SYS_CLK_HSE,RCC_CLK_OFF);
				}
			}
		}

		}
#elif (RCC_PLL_SOURCE == RCC_PLL_SRC_HSE)
	/*Turn HSE ON*/
		MRCC_voidSetClkStatus(RCC_SYS_CLK_HSE,RCC_CLK_ON);
		/*Check HSE Ready*/
		if(MRCC_CheckReady(RCC_HSERDY_PIN17))
		{	/*SET HSE AS a Source CLK*/
			if(MRCC_SetClkSource(RCC_SYS_CLK_HSE))
			{
				/*Turn PLL */
				MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_OFF);
				/*PLL CFG*/
				MRCC_SetPLLConfiguration(RCC_PLL_SOURCE, RCC_PLL_MUL_FACTOR);
				/*Buses Prescaler*/
				MRCC_voidSetClkBusesPrescaler(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
				/*Turn PLL ON*/
				MRCC_voidSetClkStatus(RCC_SYS_CLK_PLL,RCC_CLK_ON);
				/*Check PLL Ready*/
				if(MRCC_CheckReady(RCC_PLLRDY_PIN25))
				{
					if(MRCC_SetClkSource(RCC_SYS_CLK_PLL))
					{	/*Turn HSI ON*/
						MRCC_voidSetClkStatus(RCC_SYS_CLK_HSI,RCC_CLK_OFF);
					}
				}
			}

			}
#endif
#endif
}




