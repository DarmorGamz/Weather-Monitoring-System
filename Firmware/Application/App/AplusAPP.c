/** INCLUDES ******************************************************************/
#include "AplusApp.h"

/** LOCAL (PRIVATE) STRUCTURES AND ENUMERATIONS *******************************/
AplusUserConfig g_stUserConfig;

/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/

/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/
void _FlashReadAppUserConfig(void);
void _FlashWriteAppUserConfig(void);
void _InitUserConfig(void);


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
void TimerCallback(TIM_HandleTypeDef *htim) {
	// Measurement collection
	TempSensor_GetData();
	HumiditySensor_GetData();
}

void AplusAPP_Init(void) {
	// Initialize the debug log
	Debug_InitLog();
	printf("Debug log initialized\r\n");

	// Capture reset cause
	/*ResetCause_t reset_cause =*/ Get_Reset_Cause();

	// Initialize the watchdog timer
	Watchdog_Init();
	printf("Watchdog initialized\r\n");

	// Initialize the RTC.
	Timestamp_Init();
	printf("RTC initialized\r\n");

	uint32_t new_timestamp = 1680554930;
	Timestamp_SetTimestamp(new_timestamp);

	// Initialize flash - where user configuration is stored
	Flash_Init();
	printf("Flash initialized\r\n");

	// Read user configuration from flash
	_FlashReadAppUserConfig();
	printf("User configuration retrieved\r\n");

	 // Set current time from the last timestamp stored in flash.
	uint32_t timestamp;
	memcpy(&timestamp, &g_stUserConfig.au8Timestamp[0], 4);
	if(timestamp>0) {
		Timestamp_SetTimestamp(timestamp);
	}
	printf("Timestamp Initialized\r\n");

	int8_t s8Status = 0;

	s8Status = Wifi_Init();
	if (s8Status!=0) {
		printf("Wifi failed to initialize.\r\n");
		while(1) {}
	}
	printf("Wifi initialized.\r\n");

	TempSensor_Init();
	printf("Temp sensor initialize.\r\n");

	HumiditySensor_Init();
	printf("Humidity sensor initialize.\r\n");

	DataQueue_Init();
	printf("Storage queue initialize.\r\n");

	Timer_Init();
	printf("Timer initialize.\r\n");

	printf("Application init complete\r\n");
}

void AplusAPP_Entry(void) {
	static bool s_fCheckLink = true;

	printf("Entering main state machine\r\n");

	while(1) {
		// Feed the watchdog every time through this callback - if not, the device will reset after 8 seconds
		Watchdog_Feed();

		if (s_fCheckLink==true) {
			// Init vars.
			int8_t s8Status;

			// Attempt connect to stored SSID.
			s8Status = Wifi_Connect();
			if (s8Status!=0) {
				printf("Wifi to connect.\r\n");
				while(1) {}
			}
			printf("Wifi connected.\r\n");
			s_fCheckLink = false;
		}

		// Determine if it is time to send to the server
		bool fTimeToSend = false;

		if(DataQueue_GetCount() != 0) { fTimeToSend = true; }

		// Transmit any pending packets/responses to server if it has been determined we need to send
		if (fTimeToSend==true) {

		}

	}
}

ResetCause_t Get_Reset_Cause(void) {
    ResetCause_t cause;

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST)) {
        cause = RESET_CAUSE_LOW_POWER_RESET;
        printf("Reset Cause: Low Power Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST)) {
        cause = RESET_CAUSE_WINDOW_WATCHDOG_RESET;
        printf("Reset Cause: Window Watchdog Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST)) {
        cause = RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET;
        printf("Reset Cause: Independent Watchdog Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST)) {
        cause = RESET_CAUSE_SOFTWARE_RESET;
        printf("Reset Cause: Software Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST)) {
        cause = RESET_CAUSE_EXTERNAL_RESET_PIN_RESET;
        printf("Reset Cause: External Reset Pin Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_BORRST)) {
        cause = RESET_CAUSE_BROWN_OUT_RESET;
        printf("Reset Cause: Brown Out Reset\r\n");
    } else {
        cause = RESET_CAUSE_UNKNOWN;
        printf("Reset Cause: Unknown\r\n");
    }

    return cause;
}

void _FlashReadAppUserConfig(void) {
	Flash_ReadFlash(USER_CONFIG_SPACE_ORIGIN, (char*)&g_stUserConfig, sizeof(AplusUserConfig));

	if(g_stUserConfig.u16InitCode!=USER_CONFIG_INIT_CODE) {
		printf("Init User Config\r\n");
		_InitUserConfig();
	}
}

void _FlashWriteAppUserConfig(void) {
	// Set timestamp
	uint32_t timestamp;
	Timestamp_GetTimestamp(&timestamp);
	memcpy(&g_stUserConfig.au8Timestamp[0], &timestamp, 4);

	printf("Erase Flash\r\n");
	Flash_EraseFlash(USER_CONFIG_SPACE_ORIGIN, USER_CONFIG_SPACE_SIZE_BYTES);

	printf("Write Flash\r\n");
	Flash_WriteFlash(USER_CONFIG_SPACE_ORIGIN, (char*)&g_stUserConfig, sizeof(AplusUserConfig));
}

void _InitUserConfig(void) {
	memset(&g_stUserConfig, 0, sizeof(AplusUserConfig));

	g_stUserConfig.u16InitCode = USER_CONFIG_INIT_CODE;
	g_stUserConfig.u16CfgSize  = sizeof(AplusUserConfig);

	_FlashWriteAppUserConfig();
}






