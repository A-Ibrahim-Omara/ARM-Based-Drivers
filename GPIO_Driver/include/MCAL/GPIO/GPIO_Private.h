/*
 * GPIO_Private.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*-----------------Pointers to The Structure of PORTx Mapping Registers-----------------*/
#define GPIOA ((volatile GPIOx_Reg *) 0x40010800)
#define GPIOB ((volatile GPIOx_Reg *) 0x40010C00)
#define GPIOC ((volatile GPIOx_Reg *) 0x40011000)
/*-----------------The Structure of PORTx Mapping Registers-----------------------------*/
typedef struct {
	volatile u32 CRL ;
	volatile u32 CRH ;
	volatile u32 IDR ;
	volatile u32 ODR ;
	volatile u32 BSRR;
	volatile u32 BRR ;
	volatile u32 LCKR;
}GPIOx_Reg;
/*---------------------------------------------------------------------------------------*/

#endif /* GPIO_PRIVATE_H_ */
