#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"
#include "AplusAPP.h"
#include <stdbool.h>
#include <time.h>

/** CONSTANT AND MACRO DEFINITIONS ********************************************/
#define RTC_MINIMUM_TIMESTAMP   1577836800  // 01-Jan-2020 00:00:00
#define RTC_MAXIMUM_TIMESTAMP   2524608000  // 01-Jan-2050 00:00:00


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void Timestamp_Init(void);
bool Timestamp_SetTimestamp(uint32_t timestamp);
void Timestamp_GetTimestamp(uint32_t *timestamp);

#ifdef __cplusplus
}
#endif

#endif
