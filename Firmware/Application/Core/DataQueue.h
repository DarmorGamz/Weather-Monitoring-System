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

#ifdef __cplusplus
}
#endif

#endif
