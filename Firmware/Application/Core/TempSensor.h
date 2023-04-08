/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        TempSensor.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Header file for B-L475E temperature sensor initialization.
 ******************************************************************************/

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"
#include "stm32l475e_iot01_tsensor.h"


/** CONSTANT AND MACRO DEFINITIONS ********************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void TempSensor_Init(void);
void TempSensor_GetData();

#ifdef __cplusplus
}
#endif

#endif
