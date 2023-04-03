
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

void Watchdog_Init(void) {
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = WATCHDOG_PRESCALER;
	hiwdg.Init.Reload = WATCHDOG_RELOAD;
	hiwdg.Init.Window = IWDG_WINDOW_DISABLE;


	if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
		/* Initialization Error */
	}
}


void Watchdog_Feed(void) {
	HAL_IWDG_Refresh(&hiwdg);
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/

