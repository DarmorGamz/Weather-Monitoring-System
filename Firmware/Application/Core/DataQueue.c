/** INCLUDES ******************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "AplusApp.h"
#include "DataQueue.h"

/** VARIABLES *****************************************************************/
static uint16_t   s_u16QueueCount;
tsData 				g_acReadingBuffer[READING_BUFF_NUM_BYTES];

/** LOCAL (PRIVATE) STRUCTURES AND ENUMERATIONS *******************************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
void DataQueue_Init(void) {
	// Clear the contents of the reading queue
	memset(&g_acReadingBuffer[0], 0, READING_BUFF_NUM_BYTES);
	s_u16QueueCount = 0;
}

void DataQueue_Add(eDataType eType, uint8_t u8DataValue, uint8_t u8DataFloat) {
	// Init vars.
	tsData tsTempData;

	// Set timestamp
	uint32_t timestamp;
	Timestamp_GetTimestamp(&timestamp);

	// Set data.
	tsTempData.u32Timestamp = timestamp;
	tsTempData.eType = eType;
	tsTempData.u8DataValue = u8DataValue;
	tsTempData.u8DataFloat = u8DataFloat;

	// Store the structure.
	memcpy(&g_acReadingBuffer[s_u16QueueCount], &tsTempData, sizeof(tsData));

	// Increase Queue index.
	s_u16QueueCount++;
}
