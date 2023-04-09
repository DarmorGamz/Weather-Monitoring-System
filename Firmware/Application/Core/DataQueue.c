/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        DataQueue.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common data queue functionality for the product firmware.
 ******************************************************************************/

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

/**************************************************************************//**
 *  Initializes Data queue for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void DataQueue_Init(void) {
	// Clear the contents of the reading queue
	memset(&g_acReadingBuffer[0], 0, READING_BUFF_NUM_BYTES);
	s_u16QueueCount = 0;
}

/**************************************************************************//**
 *  Main processing loop for the product application
 *  @param[in]  eDataType Data Type .
 *  @param[in]  int Magnitude of data value.
 *  @param[in]  int Floating point of data value.
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void DataQueue_Add(eDataType eType, int u8DataValue, int u8DataFloat) {
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

/**************************************************************************//**
 *  Sends Data from the queue.
 *  @param[in]  char* Pointer of send buffer.
 *  @param[in]  uint16_t Maximum amount of bytes to be sent.
 *  @param[out] None
 *  @return     uint16_t Bytes being sent.
 ******************************************************************************/
uint16_t DataQueue_Send(char *pDst, uint16_t maxBytes) {
    // Init vars.
    uint16_t u16BytesSent = 0;
    uint16_t i = 0;

    while (i < s_u16QueueCount && u16BytesSent < maxBytes) {
        char temp_str[64]; // Temporary string buffer to store the formatted data
        int n = snprintf(temp_str, sizeof(temp_str),
                 "Type:%d,Value:%d,Float:%d,Timestamp:%lu;",
                 g_acReadingBuffer[i].eType,
                 g_acReadingBuffer[i].u8DataValue,
                 g_acReadingBuffer[i].u8DataFloat,
                 g_acReadingBuffer[i].u32Timestamp);

        // Calculate the remaining space in pDst buffer.
        uint16_t remaining_space = maxBytes - u16BytesSent;

        // Concatenate temp_str to pDst, but do not exceed maxBytes.
        strncat(pDst + u16BytesSent, temp_str, remaining_space - 1);

        // Update the bytes sent counter.
        if (n < remaining_space) {
            u16BytesSent += n;

            // Shift the elements of the array to the left.
            for (int j = 0; j < s_u16QueueCount - 1; j++) {
                g_acReadingBuffer[j] = g_acReadingBuffer[j + 1];
            }

            // Reduce queue count.
            s_u16QueueCount--;
        } else {
            u16BytesSent = maxBytes;
        }
    }

//    // Null-terminate the pDst buffer if there's space left.
//    if (u16BytesSent < maxBytes) {
//        pDst[u16BytesSent] = '\0';
//    }

    // Return Bytes sent.
    return u16BytesSent;
}

/**************************************************************************//**
 *  Returns Data queue count.
 *  @param[in]  None
 *  @param[out] None
 *  @return     uint16_t Data queue count.
 ******************************************************************************/
uint16_t DataQueue_GetCount(void) {
	return s_u16QueueCount;
}
