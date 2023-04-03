/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "Timestamp.h"

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
void Timestamp_Init(void) {
	// Enable the RTC Clock
	__HAL_RCC_RTC_ENABLE();

	// Configure the RTC
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

	if (HAL_RTC_Init(&hrtc) != HAL_OK) {
		/* Initialization Error */
	}
}

bool Timestamp_SetTimestamp(uint32_t timestamp) {
	RTC_DateTypeDef date;
	RTC_TimeTypeDef time;
	struct tm *tm;

	// Convert the epoch timestamp to tm struct
	tm = localtime((time_t *)&timestamp);

	// Populate the date and time structs
	date.Year = tm->tm_year - 100;
	date.Month = tm->tm_mon + 1;
	date.Date = tm->tm_mday;

	time.Hours = tm->tm_hour;
	time.Minutes = tm->tm_min;
	time.Seconds = tm->tm_sec;

	// Set the RTC date and time
	HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
	HAL_RTC_SetTime(&hrtc, &time, RTC_FORMAT_BIN);

	return true;
}

void Timestamp_GetTimestamp(uint32_t *timestamp) {
	RTC_DateTypeDef date;
	RTC_TimeTypeDef time;
	struct tm tm;

	// Read the current date and time from RTC
	HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);

	// Populate the tm struct
	tm.tm_year = date.Year + 100;  // Years since 1900
	tm.tm_mon = date.Month - 1;
	tm.tm_mday = date.Date;
	tm.tm_hour = time.Hours;
	tm.tm_min = time.Minutes;
	tm.tm_sec = time.Seconds;

	*timestamp = mktime(&tm);
}
