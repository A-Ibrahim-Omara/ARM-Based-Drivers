/*
 * GPIO_Program.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Ibrahim
 */

#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_type.h"

#include "../include/MCAL/GPIO/GPIO_Private.h"
#include "../include/MCAL/GPIO/GPIO_Cfg.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"

check_type MGPIO_voidSetPinDirection(u8 copy_u8PortNumber,u8 copy_u8PinNumber,u8 copy_u8Mode,u8 copy_u8CNF)
{
	check_type check_return= check_NOK;
	if(copy_u8PortNumber<=GPIO_PORTC)
	{
		switch(copy_u8PortNumber)
		{
		case GPIO_PORTA:
			if(copy_u8PinNumber<=GPIO_PIN7)
			{
				GPIOA->CRL &=~(15<<(4*copy_u8PinNumber));
				GPIOA->CRL |= (copy_u8Mode<<(4*copy_u8PinNumber));
				GPIOA->CRL |= (copy_u8CNF<<((4*copy_u8PinNumber)+2));
				check_return=check_OK;
			}
			else if(copy_u8PinNumber>=GPIO_PIN8 && copy_u8PinNumber<=GPIO_PIN15)
			{
				copy_u8PinNumber-=8;
				GPIOA->CRH &=~(15<<(4*copy_u8PinNumber));
				GPIOA->CRH |= copy_u8Mode<<(4*copy_u8PinNumber);
				GPIOA->CRH |= copy_u8CNF<<((4*copy_u8PinNumber)+2);
				check_return=check_OK;
			}
			break;
		case GPIO_PORTB:
			if(copy_u8PinNumber<=GPIO_PIN7)
			{
				GPIOB->CRL &=~(15<<(4*copy_u8PinNumber));
				GPIOB->CRL |= copy_u8Mode<<(4*copy_u8PinNumber);
				GPIOB->CRL |= copy_u8CNF<<((4*copy_u8PinNumber)+2);
				check_return=check_OK;
			}
			else if(copy_u8PinNumber>=GPIO_PIN8 && copy_u8PinNumber<=GPIO_PIN15)
			{
				copy_u8PinNumber-=8;
				GPIOB->CRH &=~(15<<(4*copy_u8PinNumber));
				GPIOB->CRH |= copy_u8Mode<<(4*copy_u8PinNumber);
				GPIOB->CRH |= copy_u8CNF<<((4*copy_u8PinNumber)+2);
				check_return=check_OK;
			}
			break;
		case GPIO_PORTC:
			if(copy_u8PinNumber>=GPIO_PIN13 && copy_u8PinNumber<=GPIO_PIN15)
			{
				copy_u8PinNumber-=8;
				GPIOC->CRH &=~(15<<(4*copy_u8PinNumber));
				GPIOC->CRH |= (copy_u8Mode<<(4*copy_u8PinNumber));
				GPIOC->CRH |= (copy_u8CNF<<((4*copy_u8PinNumber)+2));
				check_return=check_OK;
			}
			break;
		}

	}
	return check_return;
}

check_type MGPIO_voidSetPinValue(u8 copy_u8PortNumber,u8 copy_u8PinNumber,u8 copy_u8PinValue)
{
	check_type check_return= check_NOK;
	if(copy_u8PortNumber<=GPIO_PORTC)
	{
		switch(copy_u8PortNumber)
		{
		case GPIO_PORTA:
			if(copy_u8PinNumber<=GPIO_PIN15)
			{

				GPIOA->ODR &=~(1<<copy_u8PinNumber);
				GPIOA->ODR |= (copy_u8PinValue<<copy_u8PinNumber);
				check_return=check_OK;
			}
			break;
		case GPIO_PORTB:
			if(copy_u8PinNumber<=GPIO_PIN15)
			{
				GPIOB->ODR &=~(1<<copy_u8PinNumber);
				GPIOB->ODR |= (copy_u8PinValue<<copy_u8PinNumber);
				check_return=check_OK;
			}
			break;
		case GPIO_PORTC:
			if(copy_u8PinNumber>=GPIO_PIN13 && copy_u8PinNumber<=GPIO_PIN15)
			{
				GPIOC->ODR &=~(1<<copy_u8PinNumber);
				GPIOC->ODR |= (copy_u8PinValue<<copy_u8PinNumber);
				check_return=check_OK;
			}
			break;
		}

	}
	return check_return;
}
check_type MGPIO_u8GetPinValue (u8 copy_u8PortNumber,u8 copy_u8PinNumber, u8 *copy_u8PtrValue)
{
	check_type check_return=check_NOK;

	switch (copy_u8PortNumber)
	{
	case GPIO_PORTA:
					*copy_u8PtrValue=GET_BIT(GPIOA->IDR,copy_u8PinNumber);
					check_return=check_OK;
					break;
	case GPIO_PORTB:
					*copy_u8PtrValue=GET_BIT(GPIOB->IDR,copy_u8PinNumber);
					check_return=check_OK;
					break;
	case GPIO_PORTC:
					if (copy_u8PinNumber>=GPIO_PIN13 && copy_u8PinNumber<=GPIO_PIN15)
					{
					   *copy_u8PtrValue=GET_BIT(GPIOC->IDR,copy_u8PinNumber);
					   check_return=check_OK;
					}
					break;
	default	:
						check_return=check_NOK;
					break;
	}
	return check_return;
}
