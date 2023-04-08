/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        Watchdog.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common watchdog functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "Watchdog.h"

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_iwdg.h"

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes Watchdog for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Watchdog_Init(void) {
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = WATCHDOG_PRESCALER;
	hiwdg.Init.Reload = WATCHDOG_RELOAD;
	hiwdg.Init.Window = IWDG_WINDOW_DISABLE;

	if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
		/* Initialization Error */
	}
}

/**************************************************************************//**
 *  Feed the watchdog to ensure application doesn't restart.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Watchdog_Feed(void) {
	HAL_IWDG_Refresh(&hiwdg);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/

