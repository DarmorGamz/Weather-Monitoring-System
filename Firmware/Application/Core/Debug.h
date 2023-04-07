#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "stm32l475e_iot01.h"

/** CONSTANT AND MACRO DEFINITIONS ********************************************/
extern UART_HandleTypeDef hDiscoUart;
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void Debug_InitLog(void);

#ifdef __cplusplus
}
#endif

#endif
