
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
int8_t Wifi_Init(void) {
	// Init vars.
	WIFI_Status_t stmRet;

	// Initialize the WiFi info structure
	memset((uint8_t *)&s_stWiFiInfo, 0, sizeof(sWiFiInfo));

	// Initalize Wifi stack.
	stmRet = WIFI_Init();
	if(stmRet != WIFI_STATUS_OK) { return stmRet; }

	// Set Response.
	return 0;
}

int8_t Wifi_Connect(void) {
	// Init vars.
	WIFI_Status_t stmRet;

	memset(&s_stWiFiInfo.au8IpAddr[0], 0, 4);
//	memset(&s_stWiFiInfo.au8SubnetMask[0], 0, 4);
//	memset(&s_stWiFiInfo.au8Gateway[0], 0, 4);
//	memset(&s_stWiFiInfo.au8Dns[0], 0, 4);

	// Attempt connect with hardcode SSID and Password.
	stmRet = WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK);
	if(stmRet != WIFI_STATUS_OK) { return stmRet; }

	// Get network information
	stmRet = WIFI_GetIP_Address(&s_stWiFiInfo.au8IpAddr[0], sizeof(&s_stWiFiInfo.au8IpAddr[0]));
	if(stmRet != WIFI_STATUS_OK) { return stmRet; }
//	memcpy(&s_stWiFiInfo.au8IpAddr[0], esWifiObj.NetSettings.IP_Addr, 4);
//	memcpy(&s_stWiFiInfo.au8SubnetMask[0], esWifiObj.NetSettings.IP_Mask, 4);
//	memcpy(&s_stWiFiInfo.au8Gateway[0], esWifiObj.NetSettings.Gateway_Addr, 4);
//	memcpy(&s_stWiFiInfo.au8Dns[0], esWifiObj.NetSettings.DNS1, 4);

	// Set Response.
	return 0;
}

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

void Wifi_Send(void) {
#define TX_BUFFER_SIZE 4096

	char pTxDst[TX_BUFFER_SIZE];
	memset(&pTxDst[0], 0, TX_BUFFER_SIZE);
	init_post_request_header(pTxDst);

	uint16_t u16ReadingBytes = 0;
	char *payload_start = strstr(pTxDst, "\r\n\r\n");
	if (payload_start != NULL) {
		payload_start += 5;

		uint16_t remaining_space = TX_BUFFER_SIZE - (payload_start - pTxDst);
		u16ReadingBytes = DataQueue_Send(payload_start, remaining_space);
	}

	char *content_length_placeholder = strstr(pTxDst, "Content-Length: %u");
	if (content_length_placeholder != NULL) {
	    char new_content_length[32];
	    snprintf(new_content_length, sizeof(new_content_length), "Content-Length: %u\r\n\r\n", u16ReadingBytes);

	    size_t new_content_length_len = strlen(new_content_length);
	    memcpy(content_length_placeholder, new_content_length, new_content_length_len);
	}

	uint16_t total_data_length = (payload_start - pTxDst) + u16ReadingBytes;

	uint8_t ipaddr[4];
	const char *url = "hw.darmorgamz.ca";
	if(WIFI_GetHostAddress(url, ipaddr, sizeof(ipaddr)) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }
	printf("Wifi Got Host.\r\n");

	if( WIFI_OpenClientConnection(0, WIFI_TCP_PROTOCOL, "TCP_CLIENT", ipaddr, 80, 80) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }
	printf("Wifi Got Connection.\r\n");

	uint16_t Datalen = 0;
	if(WIFI_SendData(0, (uint8_t *)pTxDst, total_data_length, &Datalen, 10000) != WIFI_STATUS_OK) { printf("Wifi fail.\r\n"); return; }

	printf("Sent Data: \r\n");
	for (int i = 0; i < total_data_length; i++) {
	  fflush(stdin);
	  printf("%c", pTxDst[i]);
	  fflush(stdin);
	}
	printf("\r\n\r\n");

	static char RxData [500];
	uint16_t ReceivedDataLength;

	if (WIFI_ReceiveData(0, (uint8_t *)RxData, sizeof(RxData), &ReceivedDataLength, 10000) != WIFI_STATUS_OK) { printf("ERROR : Failed to Receive Data\r\n"); return; }
	if(WIFI_CloseClientConnection(0) != WIFI_STATUS_OK) {  printf("ERROR : Failed to close socket\r\n"); }

	if (strncmp(RxData, "HTTP/1.1 200 OK", 15) != 0) { printf("Did not receive 200 OK: \r\n"); return; }
	printf("Received 200 OK status.\r\n");

	char *response_payload_start = strstr(RxData, "\r\n\r\n");
	if (response_payload_start == NULL) { printf("Payload not found.\r\n"); return; }

	response_payload_start += 4; // Move the pointer past the "\r\n\r\n" sequence.

	// Process the payload

	printf("Payload: %s\r\n", response_payload_start);
	uint32_t timestamp;
	sscanf(response_payload_start, "%lu", &timestamp);

	SetSystemTime(timestamp);
}

int8_t Wifi_IsConnected(void) { // Get Ip address does the network layer Is_Connected(). If GetIp fails, it's not connected.
	return WIFI_GetIP_Address(&s_stWiFiInfo.au8IpAddr[0], sizeof(&s_stWiFiInfo.au8IpAddr[0]));
}

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/
