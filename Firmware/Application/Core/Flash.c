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
void Flash_Init(void) {

}

void Flash_ReadFlash(uint32_t byteAddress, char *buffer, uint32_t size) {
    uint32_t i;
    uint64_t data;

    for (i = 0; i < size; i += 8) {
        // Read 8 bytes (double word) from the flash memory
        data = *(__IO uint64_t *)(byteAddress + i);

        // Copy the data to the buffer
        memcpy(&buffer[i], &data, (i + 8 <= size) ? 8 : (size - i));
    }
}


void Flash_EraseFlash(uint32_t byteAddress, uint32_t size) {
	uint32_t pageError = 0;
	FLASH_EraseInitTypeDef eraseInitStruct;

	// Calculate the start page number
	uint32_t startPage = (byteAddress - FLASH_BASE) / FLASH_PAGE_SIZE;

	// Unlock the Flash memory
	HAL_FLASH_Unlock();

	// Clear any existing error flags
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

	eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	eraseInitStruct.Page = startPage;
	eraseInitStruct.NbPages = (size/FLASH_PAGE_SIZE);

	if (HAL_FLASHEx_Erase(&eraseInitStruct, &pageError) != HAL_OK) {
		// Handle erase error
	}

	// Lock the Flash memory
	HAL_FLASH_Lock();
}

void Flash_WriteFlash(uint32_t byteAddress, char *buffer, uint32_t size) {
    uint32_t i;
    uint64_t data;

    // Unlock the Flash memory
    HAL_FLASH_Unlock();

    // Clear any existing error flags
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

    for (i = 0; i < size; i += 8) {
        // Zero the data variable to ensure proper padding
        data = 0;

        // Read up to 8 bytes from the buffer
        memcpy(&data, &buffer[i], (i + 8 <= size) ? 8 : (size - i));

        // Write the double word to the flash memory
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, byteAddress + i, data) != HAL_OK) {
            // Handle write error
        }
    }

    // Lock the Flash memory
    HAL_FLASH_Lock();
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
