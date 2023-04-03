#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/


/** CONSTANT AND MACRO DEFINITIONS ********************************************/
#define WATCHDOG_TIMEOUT_MS 8000
#define WATCHDOG_TIMEOUT_S (WATCHDOG_TIMEOUT_MS / 1000.0)
#define LSE_FREQUENCY 32000
#define WATCHDOG_PRESCALER IWDG_PRESCALER_256
#define WATCHDOG_RELOAD ((WATCHDOG_TIMEOUT_S * LSE_FREQUENCY) / 256)

/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void    Watchdog_Init(void);
void    Watchdog_Feed(void);

#ifdef __cplusplus
}
#endif

#endif
