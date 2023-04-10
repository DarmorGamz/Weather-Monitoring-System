/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        TempSensor.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common temperature sensor functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "AplusApp.h"
#include "TempSensor.h"
#include <math.h>

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes temperature sensor for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void TempSensor_Init(void) {
	BSP_TSENSOR_Init();
}


/**************************************************************************//**
 *  Gets current sensor reading and adds to Data queue.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void TempSensor_GetData(void) {
	// Init vars.
	float fTemperatureValue = 0;  // Measured temperature value

	// Get value.
	fTemperatureValue = BSP_TSENSOR_ReadTemp();

	// Data analysis.
	int u8TemperatureInt1 = fTemperatureValue;
	float fTemperatureDecimal = fTemperatureValue - u8TemperatureInt1;
	int u8TemperatureInt2 = trunc(fTemperatureDecimal * 100);

	// Add to data queue.
	DataQueue_Add(DATA_TYPE_TEMP, u8TemperatureInt1, u8TemperatureInt2);

}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/



