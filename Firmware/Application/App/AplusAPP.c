/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        AplusAPP.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Main entry point for product firmware.
 * @details     /n Initializes devices, register callbacks, handle events
 ******************************************************************************/

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

/**************************************************************************//**
 *  Callback function for (one second) Timer interrupt.
 *  @param[in]  TIM_HandleTypeDef Hardware time object.
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void TimerCallback(TIM_HandleTypeDef *htim) {
	// Measurement collection
	TempSensor_GetData();
	HumiditySensor_GetData();
	PressureSensor_GetData();
}

/**************************************************************************//**
 *  Initialize application specific functionality
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
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

	// Initialize flash - where user configuration is stored
	Flash_Init();
	printf("Flash initialized\r\n");

	// Read user configuration from flash
	_FlashReadAppUserConfig();
	printf("User configuration retrieved\r\n");

	 // Set current time from the last timestamp stored in flash.
	uint32_t u32Timestamp;
	u32Timestamp = g_stUserConfig.u32Timestamp;
	if(u32Timestamp > 0) { Timestamp_SetTimestamp(u32Timestamp); }
	printf("Timestamp Initialized\r\n");

	// Initialize Wifi stack.
	int8_t s8Status = 0;
	s8Status = Wifi_Init();
	if (s8Status!=0) { printf("Wifi failed to initialize.\r\n"); while(1) {} }
	printf("Wifi initialized.\r\n");

	// Initialize temperature sensor.
	TempSensor_Init();
	printf("Temp sensor initialize.\r\n");

	// Initialize humidity sensor.
	HumiditySensor_Init();
	printf("Humidity sensor initialize.\r\n");

	// Initialize pressure sensor.
	PressureSensor_Init();
	printf("Pressure sensor initialize.\r\n");

	// Initialize data queue.
	DataQueue_Init();
	printf("Storage queue initialize.\r\n");

	// Initialize timer(s).
	Timer_Init();
	printf("Timer initialize.\r\n");

	printf("Application init complete\r\n");
}

/**************************************************************************//**
 *  Main processing loop for the product application
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void AplusAPP_Entry(void) {
	// Init vars.
	static bool s_bCheckLink = true;
	printf("Entering main state machine\r\n");

	// Infinite application loop.
	while(1) {
		// Feed the watchdog every time through this callback - if not, the device will reset after 8 seconds
		Watchdog_Feed();

		// Attempt connect to Wifi if not currently connected.
		if (s_bCheckLink==true) {
			// Init vars.
			int8_t s8Status;

			// Attempt connect to stored SSID.
			s8Status = Wifi_Connect();
			if (s8Status!=0) { printf("Wifi to connect.\r\n"); while(1) {} }
			printf("Wifi connected.\r\n");

			Watchdog_Feed();
			s_bCheckLink = false;
		}

		// Determine if it is time to send to the server
		bool bTimeToSend = false;

		if(DataQueue_GetCount() != 0) { bTimeToSend = true; }

		// Transmit any pending packets/responses to server if it has been determined we need to send
		if (bTimeToSend==true) {
			printf("Wifi to Send.\r\n");
			Wifi_Send();
		}
	}
}

/**************************************************************************//**
 *  Used to set current system time.
 *  @param[in]  uint32_t
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void SetSystemTime(uint32_t u32Timestamp) {
	Timestamp_SetTimestamp(u32Timestamp);
	_FlashWriteAppUserConfig();
}

/**************************************************************************//**
 *  Used to get the last know reset cause after system restart
 *  @param[in]  None
 *  @param[out] None
 *  @return     ResetCause_t Reset cause.
 ******************************************************************************/
ResetCause_t Get_Reset_Cause(void) {
	// Init vars.
    ResetCause_t eCause;

    // Determine reset cause.
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST)) {
    	eCause = RESET_CAUSE_LOW_POWER_RESET;
        printf("Reset Cause: Low Power Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST)) {
    	eCause = RESET_CAUSE_WINDOW_WATCHDOG_RESET;
        printf("Reset Cause: Window Watchdog Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST)) {
    	eCause = RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET;
        printf("Reset Cause: Independent Watchdog Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST)) {
    	eCause = RESET_CAUSE_SOFTWARE_RESET;
        printf("Reset Cause: Software Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST)) {
    	eCause = RESET_CAUSE_EXTERNAL_RESET_PIN_RESET;
        printf("Reset Cause: External Reset Pin Reset\r\n");
    } else if (__HAL_RCC_GET_FLAG(RCC_FLAG_BORRST)) {
    	eCause = RESET_CAUSE_BROWN_OUT_RESET;
        printf("Reset Cause: Brown Out Reset\r\n");
    } else {
    	eCause = RESET_CAUSE_UNKNOWN;
        printf("Reset Cause: Unknown\r\n");
    }

    // Set Response.
    return eCause;
}

/**************************************************************************//**
 *  Used to read the User Config from NVM.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void _FlashReadAppUserConfig(void) {
	// Read from NVM flash.
	Flash_ReadFlash(USER_CONFIG_SPACE_ORIGIN, (char*)&g_stUserConfig, sizeof(AplusUserConfig));

	// Determine if config has been initialized.
	if(g_stUserConfig.u16InitCode != USER_CONFIG_INIT_CODE) {
		printf("Init User Config\r\n");
		_InitUserConfig();
	}
}

/**************************************************************************//**
 *  Used to write the User Config to NVM.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void _FlashWriteAppUserConfig(void) {
	// Set timestamp
	uint32_t u32Timestamp;
	Timestamp_GetTimestamp(&u32Timestamp);
	g_stUserConfig.u32Timestamp = u32Timestamp;

	// Erase flash. Needs to be done to unlock and clear before writing.
	Flash_EraseFlash(USER_CONFIG_SPACE_ORIGIN, USER_CONFIG_SPACE_SIZE_BYTES);

	// Write to flash.
	Flash_WriteFlash(USER_CONFIG_SPACE_ORIGIN, (char*)&g_stUserConfig, sizeof(AplusUserConfig));
}

/**************************************************************************//**
 *  Used to initalize the user config. This is stored in NVM.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void _InitUserConfig(void) {
	// Clear structure.
	memset(&g_stUserConfig, 0, sizeof(AplusUserConfig));

	// Set vars.
	g_stUserConfig.u16InitCode = USER_CONFIG_INIT_CODE;
	g_stUserConfig.u16CfgSize  = sizeof(AplusUserConfig);

	// Flash config.
	_FlashWriteAppUserConfig();
}






