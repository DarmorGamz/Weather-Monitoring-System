/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        stm_start.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common STM32 functionality for the product firmware.
 ******************************************************************************/

#include "stm_start.h"

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void stm_start_init(void) {
	system_init();
}
