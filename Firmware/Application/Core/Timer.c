/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "Timer.h"

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/
TIM_HandleTypeDef htim;

/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

int16_t Timer_Init(void) {
	__HAL_RCC_TIM2_CLK_ENABLE(); // Enable the clock for the TIM2 peripheral

	htim.Instance = TIM2;
	htim.Init.Prescaler = 8000 - 1; // 80 MHz / 8000 = 10 kHz
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = 10000 - 1; // 10 kHz / 10000 = 1 Hz
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&htim); // Initialize the timer
	HAL_TIM_Base_Start_IT(&htim); // Start the timer with interrupt

	// Enable the timer interrupt and set its priority
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
    return 0;
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
void TIM2_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        TimerCallback(htim);
    }
}

