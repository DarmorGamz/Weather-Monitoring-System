/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        DataQueue.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Header file for data queue functionality.
 ******************************************************************************/

#ifndef DATAQUEUE_H_
#define DATAQUEUE_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/


/** CONSTANT AND MACRO DEFINITIONS ********************************************/
typedef enum {
	DATA_TYPE_TEMP,
	DATA_TYPE_HUM
} eDataType;

typedef struct {
	eDataType  eType;
	uint8_t  u8DataValue;
	uint8_t  u8DataFloat;
	uint32_t u32Timestamp;
} tsData;

extern tsData	g_acReadingBuffer[];


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
void DataQueue_Init(void);
void DataQueue_Add(eDataType, uint8_t, uint8_t);
uint16_t DataQueue_GetCount(void);
uint16_t DataQueue_Send(char *pDst, uint16_t maxBytes);


#ifdef __cplusplus
}
#endif

#endif
