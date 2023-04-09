/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        WifiNew.c
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Common wifi functionality for the product firmware.
 ******************************************************************************/

/** INCLUDES ******************************************************************/
#include "driver_init.h"
#include "AplusApp.h"
#include "WifiNew.h"


/** VARIABLES *****************************************************************/
static sWiFiInfo    s_stWiFiInfo;

/** LOCAL (PRIVATE) CONSTANT AND MACRO DEFINITIONS ****************************/


/** LOCAL (PRIVATE) TYPEDEFS, STRUCTURES AND ENUMERATIONS *********************/


/** LOCAL (PRIVATE) FUNCTION PROTOTYPES ***************************************/


/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**************************************************************************//**
 *  Initializes Wifi stack for use.
 *  @param[in]  None
 *  @param[out] None
 *  @return     int8_t Initialization was successful.
 ******************************************************************************/
int8_t Wifi_Init(void) {
	// Init vars.
	WIFI_Status_t eStmRet;

	// Initialize the WiFi info structure
	memset((uint8_t *)&s_stWiFiInfo, 0, sizeof(sWiFiInfo));

	// Initalize Wifi stack.
	eStmRet = WIFI_Init();
	if(eStmRet != WIFI_STATUS_OK) { return eStmRet; }

	// Set Response.
	return 0;
}

/**************************************************************************//**
 *  Connect to a network. This is currently hardcoded.
 *  @param[in]  None
 *  @param[out] None
 *  @return     int8_t Connection was successful.
 ******************************************************************************/
int8_t Wifi_Connect(void) {
	// Init vars.
	WIFI_Status_t eStmRet;

	memset(&s_stWiFiInfo.au8IpAddr[0], 0, 4);
//	memset(&s_stWiFiInfo.au8SubnetMask[0], 0, 4);
//	memset(&s_stWiFiInfo.au8Gateway[0], 0, 4);
//	memset(&s_stWiFiInfo.au8Dns[0], 0, 4);

	// Attempt connect with hardcode SSID and Password.
	eStmRet = WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK);
	if(eStmRet != WIFI_STATUS_OK) { return eStmRet; }

	// Get network information
	eStmRet = WIFI_GetIP_Address(&s_stWiFiInfo.au8IpAddr[0], sizeof(&s_stWiFiInfo.au8IpAddr[0]));
	if(eStmRet != WIFI_STATUS_OK) { return eStmRet; }
//	memcpy(&s_stWiFiInfo.au8IpAddr[0], esWifiObj.NetSettings.IP_Addr, 4);
//	memcpy(&s_stWiFiInfo.au8SubnetMask[0], esWifiObj.NetSettings.IP_Mask, 4);
//	memcpy(&s_stWiFiInfo.au8Gateway[0], esWifiObj.NetSettings.Gateway_Addr, 4);
//	memcpy(&s_stWiFiInfo.au8Dns[0], esWifiObj.NetSettings.DNS1, 4);

	// Set Response.
	return 0;
}

/**************************************************************************//**
 *  Get default Post request overhead.
 *  @param[in]  char* Buffer location to store POST header.
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void init_post_request_header(char *pHeader) {
    const char *URL = "hw.darmorgamz.ca";
    const char *PATH = "/index.php";
    snprintf(pHeader, 256,
             "POST %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Content-Type: text/plain\r\n"
             "Connection: close\r\n"
             "Content-Length: %s\r\n"
    		 "\r\n", PATH, URL, "%u");
}

/**************************************************************************//**
 *  Send data in Data queue to hardware server.
 *  @param[in]  None
 *  @param[out] None
 *  @return     Nothing
 ******************************************************************************/
void Wifi_Send(void) {
	// Init vars.
	char pTxDst[TX_BUFFER_SIZE];
	uint16_t u16ReadingBytes = 0;
	memset(&pTxDst[0], 0, TX_BUFFER_SIZE);

	// Get default POST overhead.
	init_post_request_header(pTxDst);

	char* pcPayloadStart = strstr(pTxDst, "\r\n\r\n");
	if (pcPayloadStart == NULL) { printf("POST request overhead failed.\r\n"); return; }

	pcPayloadStart += 5; // Hardcoded. Could be a problem. Deal with it later.

	uint16_t u16RemainingSpace = TX_BUFFER_SIZE - (pcPayloadStart - pTxDst);
	u16ReadingBytes = DataQueue_Send(pcPayloadStart, u16RemainingSpace);


	char* cpContentLengthPlaceholder = strstr(pTxDst, "Content-Length: %u");
	if (cpContentLengthPlaceholder == NULL) { printf("Content length wasn't found.\r\n"); return; }

	char acNewContentLength[32];
	snprintf(acNewContentLength, sizeof(acNewContentLength), "Content-Length: %u\r\n\r\n", u16ReadingBytes);

	size_t NewContentLength_Len = strlen(acNewContentLength);
	memcpy(cpContentLengthPlaceholder, acNewContentLength, NewContentLength_Len);


	uint16_t u16TotalDataLength = (pcPayloadStart - pTxDst) + u16ReadingBytes;

	uint8_t u8IpAddress[4];
	const char* cpcUrl = "hw.darmorgamz.ca"; // Hardcoded.
	if(WIFI_GetHostAddress(cpcUrl, u8IpAddress, sizeof(u8IpAddress)) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }
	printf("Wifi Got Host.\r\n");

	if(WIFI_OpenClientConnection(0, WIFI_TCP_PROTOCOL, "TCP_CLIENT", u8IpAddress, 80, 80) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }
	printf("Wifi Got Connection.\r\n");

	uint16_t u16DataLength = 0;
	if(WIFI_SendData(0, (uint8_t *)pTxDst, u16TotalDataLength, &u16DataLength, 10000) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }

	printf("Sent Data.\r\n");
//	for (int i = 0; i < total_data_length; i++) {
//	  fflush(stdin);
//	  printf("%c", pTxDst[i]);
//	  fflush(stdin);
//	}
//	printf("\r\n\r\n");

	static char acRxData [500];
	uint16_t u16ReceivedDataLength;

	if(WIFI_ReceiveData(0, (uint8_t *)acRxData, sizeof(acRxData), &u16ReceivedDataLength, 10000) != WIFI_STATUS_OK) { printf("ERROR : Failed to Receive Data\r\n"); return; }
	if(WIFI_CloseClientConnection(0) != WIFI_STATUS_OK) {  printf("ERROR : Failed to close socket\r\n"); }

	if(strncmp(acRxData, "HTTP/1.1 200 OK", 15) != 0) { printf("Did not receive 200 OK: \r\n"); return; }
	printf("Received 200 OK status.\r\n");

	char* pcResponsePayloadStart = strstr(acRxData, "\r\n\r\n");
	if(pcResponsePayloadStart == NULL) { printf("Payload not found.\r\n"); return; }

	pcResponsePayloadStart += 4; // Move the pointer past the "\r\n\r\n" sequence.

	// Process the payload
	printf("Payload: %s\r\n", pcResponsePayloadStart);
	uint32_t u32Timestamp;
	sscanf(pcResponsePayloadStart, "%lu", &u32Timestamp);

	// Update system time.
	SetSystemTime(u32Timestamp);
}

/**************************************************************************//**
 *  Is Wifi connected to a network.
 *  @param[in]  None
 *  @param[out] None
 *  @return     int8_t Returns connected.
 ******************************************************************************/
int8_t Wifi_IsConnected(void) { // Get Ip address does the network layer Is_Connected(). If GetIp fails, it's not connected.
	return WIFI_GetIP_Address(&s_stWiFiInfo.au8IpAddr[0], sizeof(&s_stWiFiInfo.au8IpAddr[0]));
}


/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
