/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        Flash.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common NVM flash functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "Flash.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_flash.h"
#include "stm32l4xx_hal_flash_ex.h"

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes Flash for Read, Write, Erase.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Flash_Init(void) {

}

/**************************************************************************//**
 *  Read from NVM flash.
 *  @param[in]  uint32_t Address to read from flash memory.
 *  @param[in]  char* Buffer location to store data.
 *  @param[in]  uint32_t Size of buffer. Needs to be multiple of flash page(2048 bytes)
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Flash_ReadFlash(uint32_t u32ByteAddress, char* pcBuffer, uint32_t u32BufferSize) {
    uint32_t u32DataChunk;
    uint64_t u64Data;

    for (u32DataChunk = 0; u32DataChunk < u32BufferSize; u32DataChunk += 8) {
        // Read 8 bytes (double word) from the flash memory
    	u64Data = *(__IO uint64_t *)(u32ByteAddress + u32DataChunk);

        // Copy the data to the buffer
        memcpy(&pcBuffer[u32DataChunk], &u64Data, (u32DataChunk + 8 <= u32BufferSize) ? 8 : (u32BufferSize - u32DataChunk));
    }
}

/**************************************************************************//**
 *  Erase NVM flash.
 *  @param[in]  uint32_t Address to erase flash memory.
 *  @param[in]  uint32_t Size of memory to erase. Needs to be multiple of flash page(2048 bytes)
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Flash_EraseFlash(uint32_t u32ByteAddress, uint32_t u32DataSize) {
	// Init vars.
	uint32_t u32PageError = 0;
	FLASH_EraseInitTypeDef eraseInitStruct;

	// Calculate the start page number
	uint32_t u32StartPage = (u32ByteAddress - FLASH_BASE) / FLASH_PAGE_SIZE;

	// Unlock the Flash memory
	HAL_FLASH_Unlock();

	// Clear any existing error flags
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

	eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	eraseInitStruct.Page = u32StartPage;
	eraseInitStruct.NbPages = (u32DataSize/FLASH_PAGE_SIZE);

	if (HAL_FLASHEx_Erase(&eraseInitStruct, &u32PageError) != HAL_OK) {
		// Handle erase error
	}

	// Lock the Flash memory
	HAL_FLASH_Lock();
}

/**************************************************************************//**
 *  Write to NVM flash.
 *  @param[in]  uint32_t Address to write flash memory.
 *  @param[in]  char* Buffer location to store data.
 *  @param[in]  uint32_t Size of memory to erase. Needs to be multiple of flash page(2048 bytes)
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Flash_WriteFlash(uint32_t u32ByteAddress, char* pcBuffer, uint32_t u32DataSize) {
    uint32_t u32DataChunk;
    uint64_t u64Data;

    // Unlock the Flash memory
    HAL_FLASH_Unlock();

    // Clear any existing error flags
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

    for (u32DataChunk = 0; u32DataChunk < u32DataSize; u32DataChunk += 8) {
        // Zero the data variable to ensure proper padding
    	u64Data = 0;

        // Read up to 8 bytes from the buffer
        memcpy(&u64Data, &pcBuffer[u32DataChunk], (u32DataChunk + 8 <= u32DataSize) ? 8 : (u32DataSize - u32DataChunk));

        // Write the double word to the flash memory
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, u32ByteAddress + u32DataChunk, u64Data) != HAL_OK) {
            // Handle write error
        }
    }

    // Lock the Flash memory
    HAL_FLASH_Lock();
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
