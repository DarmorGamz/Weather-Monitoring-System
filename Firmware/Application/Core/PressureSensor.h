/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        HumiditySensor.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Header file for B-L475E pressure sensor initialization.
 ******************************************************************************/

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"
#include "stm32l475e_iot01_psensor.h"


/** CONSTANT AND MACRO DEFINITIONS ********************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void PressureSensor_Init(void);
void PressureSensor_GetData();

#ifdef __cplusplus
}
#endif

#endif
