/*
 * std_type.h
 *
 *  Created on: Jan 2, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef STD_TYPE_H_
#define STD_TYPE_H_

 /* 1_Byte types */
typedef unsigned char		 u8;
typedef signed char 		 s8;
         /* 2_Byte types */
typedef unsigned short int   u16;
typedef short int 			 s16;
         /* 4_Byte types */
typedef unsigned long int    u32;
typedef signed long int      s32;
typedef float                f32;
         /* 8_Byte types */
typedef double               f64;

#define NULL ((void*)0)

typedef void(*PF)(void);

typedef enum {check_NOK=0,check_OK=1}check_type;

#endif /* STD_TYPE_H_ */
