/*
 * GPIO_Interface.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MGPIO_voidSetPinDirection.
*Input Arg: 1-Port Number
*           2-Pin Number
*           3-Pin Mode
*           4-Pin Configuration.
*Return   : check_type enum data type ,check that the process was done successfully.
*Desc     : This function to Set pin Direction.
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
check_type MGPIO_voidSetPinDirection(u8 copy_u8PortNumber,u8 copy_u8PinNumber,u8 copy_u8Mode,u8 copy_u8CNF);
/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MGPIO_voidSetPinValue.
*Input Arg: 1-Port Number
*           2-Pin Number
*           3-Pin Value
*Return   : check_type enum data type ,check that the process was done successfully.
*Desc     : This function to Set pin Value.
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
check_type MGPIO_voidSetPinValue(u8 copy_u8PortNumber,u8 copy_u8PinNumber,u8 copy_u8PinValue);
/*------------------------------------------------------------------------------------------*/
/******************************************************************************************
*Function : MGPIO_voidSetPinValue.
*Input Arg: 1-Port Number
*           2-Pin Number
*           3-Pointer to u8 , carry the value of the pin.
*Return   : check_type enum data type ,check that the process was done successfully.
*Desc     : This function to Get pin Value.
********************************************************************************************/
/*------------------------------------------------------------------------------------------*/
check_type MGPIO_u8GetPinValue (u8 copy_u8PortNumber,u8 copy_u8PinNumber, u8 *copy_u8PtrValue);
/*-----------------------------------------------------------------------------------------------------*/

/*------GPIO PORTS for STM32F103----------------------------------------------------------------*/
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
/*------GPIO PINS------------------------------------------------------------*/
#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7
#define GPIO_PIN8    8
#define GPIO_PIN9    9
#define GPIO_PIN10   10
#define GPIO_PIN11   11
#define GPIO_PIN12   12
#define GPIO_PIN13   13
#define GPIO_PIN14   14
#define GPIO_PIN15   15
/*--------------------------------------------------------------------------------*/

/*                        PORT BIT  CFG  CFG1  CFG0 */
/*OUTPUT*/
#define GPIO_OUTPUT_PUSH_PULL        0  // 0     0
#define GPIO_OUTPUT_OPEN_DRAIN       1  // 0     1
#define GPIO_OUTPUT_AF_PUSH_PULL     2  // 1     0
#define GPIO_OUTPUT_AF_OPEN_DRAIN    3  // 1     1
/*INPUT*/
#define GPIO_INPUT_ANALOG     	     0  // 0     0
#define GPIO_INPUT_FLOATING    	     1  // 0     1
#define GPIO_INPUT_PULL_DOWN   	     2  // 1     0
#define GPIO_INPUT_PULL_UP           3  // 1     1
/*--------------------------------------------------------------------------------*/

/*MODE BITS*/
#define GPIO_INPUT_MODE    			 0
#define GPIO_OUTPUT_MODE_10MHz    	 1
#define GPIO_OUTPUT_MODE_02MHz    	 2
#define GPIO_OUTPUT_MODE_50MHz    	 3
/*--------------------------------------------------------------------------------*/
#define GPIO_HIGH                    1
#define GPIO_LOW                     0
/*--------------------------------------------------------------------------------*/

#endif /* GPIO_INTERFACE_H_ */
