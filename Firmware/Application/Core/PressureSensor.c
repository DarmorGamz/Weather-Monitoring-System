/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        HumiditySensor.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common pressure sensor functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "AplusApp.h"
#include "PressureSensor.h"
#include <math.h>

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes pressure sensor for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void PressureSensor_Init(void) {
	BSP_PSENSOR_Init();
}


/**************************************************************************//**
 *  Gets current sensor reading and adds to Data queue.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void PressureSensor_GetData(void) {
	// Init vars.
	float fPressureValue = 0;  // Measured pressure value

	// Get value.
	fPressureValue = BSP_PSENSOR_ReadPressure();

	// Separate whole part and decimal part.
	float decimalPart;
	float wholePart;
	decimalPart = modff(fPressureValue, &wholePart);

	// Scale decimal part to fit in an int variable.
	int decimalPartScaled = (int)(decimalPart * 100); // Change the scaling factor as needed

	// Convert the whole part to an int.
	int wholePartInt = (int)wholePart;


	// Add to data queue.
	DataQueue_Add(DATA_TYPE_PRESSURE, wholePartInt, decimalPartScaled);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
