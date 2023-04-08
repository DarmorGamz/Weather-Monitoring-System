/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        HumiditySensor.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common humidity sensor functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "AplusApp.h"
#include "HumiditySensor.h"
#include <math.h>

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes humidity sensor for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void HumiditySensor_Init(void) {
	BSP_HSENSOR_Init();
}


/**************************************************************************//**
 *  Gets current sensor reading and adds to Data queue.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void HumiditySensor_GetData(void) {
	// Init vars.
	float fHumidityValue = 0;  // Measured temperature value

	// Get value.
	fHumidityValue = BSP_HSENSOR_ReadHumidity();

	// Data analysis.
	uint8_t u8HumidityInt1 = fHumidityValue;
	float fHumidityDecimal = fHumidityValue - u8HumidityInt1;
	uint8_t u8HumidityInt2 = trunc(fHumidityDecimal * 100);

	// Add to data queue.
	DataQueue_Add(DATA_TYPE_HUM, u8HumidityInt1, u8HumidityInt2);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
