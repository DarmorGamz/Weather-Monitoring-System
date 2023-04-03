#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

extern RTC_HandleTypeDef hrtc;
extern IWDG_HandleTypeDef hiwdg;
extern TIM_HandleTypeDef htim;

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);
extern  SPI_HandleTypeDef hspi;

#ifdef __cplusplus
}
#endif

#endif // DRIVER_INIT_H_
