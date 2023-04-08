/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        stm_start.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief
 ******************************************************************************/

#ifndef STM_START_H_INCLUDED
#define STM_START_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "driver_init.h"

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void stm_start_init(void);


#ifdef __cplusplus
}
#endif

#endif
