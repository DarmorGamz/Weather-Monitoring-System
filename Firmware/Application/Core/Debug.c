/** INCLUDES ******************************************************************/
#include "Debug.h"

/** VARIABLES *****************************************************************/


/** LOCAL (PRIVATE) STRUCTURES AND ENUMERATIONS *******************************/
PUTCHAR_PROTOTYPE {
  HAL_UART_Transmit(&hDiscoUart, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
void Debug_InitLog() {
	/* Initialize all configured peripherals */
	  hDiscoUart.Instance = DISCOVERY_COM1;
	  hDiscoUart.Init.BaudRate = 115200;
	  hDiscoUart.Init.WordLength = UART_WORDLENGTH_8B;
	  hDiscoUart.Init.StopBits = UART_STOPBITS_1;
	  hDiscoUart.Init.Parity = UART_PARITY_NONE;
	  hDiscoUart.Init.Mode = UART_MODE_TX_RX;
	  hDiscoUart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  hDiscoUart.Init.OverSampling = UART_OVERSAMPLING_16;
	  hDiscoUart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	  hDiscoUart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	  BSP_COM_Init(COM1, &hDiscoUart);
}


