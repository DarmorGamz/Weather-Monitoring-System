#ifndef HUMIDITYSENSOR_H_
#define HUMIDITYSENSOR_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"
#include "stm32l475e_iot01_hsensor.h"

/** CONSTANT AND MACRO DEFINITIONS ********************************************/


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void HumiditySensor_Init(void);
void HumiditySensor_GetData();

#ifdef __cplusplus
}
#endif

#endif
