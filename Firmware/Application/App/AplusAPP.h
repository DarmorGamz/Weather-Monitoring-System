#ifndef APLUSAPP_H_
#define APLUSAPP_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Debug.h"
#include "Timestamp.h"
#include "Watchdog.h"
#include "Flash.h"
#include "Timer.h"

/** CONSTANT AND MACRO DEFINITIONS ********************************************/
typedef enum {
    RESET_CAUSE_UNKNOWN = 0,
    RESET_CAUSE_LOW_POWER_RESET,
    RESET_CAUSE_WINDOW_WATCHDOG_RESET,
    RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET,
    RESET_CAUSE_SOFTWARE_RESET,
    RESET_CAUSE_POWER_ON_POWER_DOWN_RESET,
    RESET_CAUSE_EXTERNAL_RESET_PIN_RESET,
    RESET_CAUSE_BROWN_OUT_RESET
} ResetCause_t;

#define USER_CONFIG_INIT_CODE                0x5A5A


#define APPLICATION_SPACE_ORIGIN                    0x8000000
#define USER_CONFIG_SPACE_ORIGIN                    0x8040960
#define STORAGE_SPACE_ORIGIN                        0x8043008

#define APPLICATION_SPACE_SIZE_BYTES                0x40960
#define USER_CONFIG_SPACE_SIZE_BYTES                0x2048
#define STORAGE_SPACE_SIZE_BYTES                    0x40960


typedef struct {
	uint16_t  u16InitCode;
	uint16_t  u16CfgSize;
	uint8_t   au8Timestamp[4];
} AplusUserConfig;



/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void AplusAPP_Init(void);
void AplusAPP_Entry(void);

ResetCause_t Get_Reset_Cause(void);


#ifdef __cplusplus
}
#endif

#endif
