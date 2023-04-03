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

