
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
void HumiditySensor_Init(void) {
	BSP_HSENSOR_Init();
}

void HumiditySensor_GetData(void) {
	float hum_value = 0;  // Measured temperature value
	hum_value = BSP_HSENSOR_ReadHumidity();
	uint8_t humInt1 = hum_value;
	float humFrac = hum_value - humInt1;
	uint8_t humInt2 = trunc(humFrac * 100);

	DataQueue_Add(DATA_TYPE_HUM, humInt1, humInt2);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
