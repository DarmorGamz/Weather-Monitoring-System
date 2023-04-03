#ifndef STM_START_H_INCLUDED
#define STM_START_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "driver_init.h"

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void stm_start_init(void);


#ifdef __cplusplus
}
#endif

#endif
