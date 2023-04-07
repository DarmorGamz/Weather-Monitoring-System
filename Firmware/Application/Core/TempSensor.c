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
void TempSensor_Init(void) {
	BSP_TSENSOR_Init();
}

void TempSensor_GetData(void) {
	float temp_value = 0;  // Measured temperature value
	temp_value = BSP_TSENSOR_ReadTemp();
	uint8_t tmpInt1 = temp_value;
	float tmpFrac = temp_value - tmpInt1;
	uint8_t tmpInt2 = trunc(tmpFrac * 100);

	DataQueue_Add(DATA_TYPE_TEMP, tmpInt1, tmpInt2);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/



