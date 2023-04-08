/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        Debug.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Header file for Development debug functionality.
 ******************************************************************************/

#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"


/** CONSTANT AND MACRO DEFINITIONS ********************************************/
extern UART_HandleTypeDef hDiscoUart;
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void Debug_InitLog(void);


#ifdef __cplusplus
}
#endif

#endif
