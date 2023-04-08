/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        main.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Main entry point for product firmware.
 * @details     Initialize device, initialize BSP and jump into the app.
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm_start.h"
#include "AplusAPP.h"

/* Private defines -----------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/


int main(void) {

	/* Initializes MCU, drivers and middleware */
	stm_start_init();

	// Initialize specific functionality
	AplusAPP_Init();

	// Main processing loop
	AplusAPP_Entry();
}

