
/** INCLUDES ******************************************************************/
#include "driver_init.h"
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

//	memset(&s_stWiFiInfo.au8IpAddr[0], 0, 4);
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

/** LOCAL (PRIVATE) FUNCTION IMPLEMENTATIONS **********************************/




//uint8_t  MAC_Addr[6] = {0};
//  uint8_t  IP_Addr[4] = {0};
//  uint16_t Datalen;
//


//
//  const char *url = "hw.darmorgamz.ca";
//  const char *http_get_request = "POST /index.php HTTP/1.1\r\nHost: hw.darmorgamz.ca\r\nConnection: close\r\n\r\n";
//  uint8_t ipaddr[4];
//
//  #define WIFI_WRITE_TIMEOUT 10000
//  #define WIFI_READ_TIMEOUT  10000
//
//  #define CONNECTION_TRIAL_MAX          10


  //
  //  if(WIFI_GetMAC_Address(MAC_Addr, sizeof(MAC_Addr)) != WIFI_STATUS_OK) { TERMOUT("> ERROR : CANNOT get MAC address\r\n"); }
  //  else { TERMOUT("> es-wifi module MAC Address : %X:%X:%X:%X:%X:%X\r\n", MAC_Addr[0], MAC_Addr[1], MAC_Addr[2], MAC_Addr[3], MAC_Addr[4], MAC_Addr[5]); }
  //
  //  if( WIFI_Connect(SSID, PASSWORD, WIFI_ECN_WPA2_PSK) != WIFI_STATUS_OK) { TERMOUT("> ERROR : es-wifi module CANNOT get IP address\r\n"); }
  //  else { TERMOUT("> es-wifi module connected \r\n"); }
  //
  //  if(WIFI_GetIP_Address(IP_Addr, sizeof(IP_Addr)) != WIFI_STATUS_OK) { TERMOUT("> ERROR : es-wifi module CANNOT get IP address\r\n"); }
  //  else { TERMOUT("> es-wifi module got IP Address : %d.%d.%d.%d\r\n", IP_Addr[0], IP_Addr[1], IP_Addr[2], IP_Addr[3]); }
  //
  //  if(WIFI_GetHostAddress(url, ipaddr, sizeof(ipaddr)) != WIFI_STATUS_OK) { TERMOUT("> ERROR : es-wifi module CANNOT get Remote IP address\r\n"); }
  //  else { TERMOUT(">IP address for %s is %d.%d.%d.%d\r\n", url, ipaddr[0], ipaddr[1], ipaddr[2], ipaddr[3]); }
  //
  //  while (1) {
  //    if( WIFI_OpenClientConnection(0, WIFI_TCP_PROTOCOL, "TCP_CLIENT", ipaddr, 80, 80) != WIFI_STATUS_OK) { TERMOUT("> ERROR : es-wifi module open socket connection\r\n"); continue; }
  //
  //    if(WIFI_SendData(0, (uint8_t *)http_get_request, strlen(http_get_request), &Datalen, WIFI_WRITE_TIMEOUT) != WIFI_STATUS_OK) { TERMOUT("> ERROR : Failed to Send Data, connection closed\r\n");}
  //    else { TERMOUT("> Sent Data Success: %d \r\n", Datalen); }
  //
  //    static uint8_t RxData [500];
  //    uint16_t ReceivedDataLength;
  //
  //    if (WIFI_ReceiveData(0, RxData, sizeof(RxData), &ReceivedDataLength, WIFI_READ_TIMEOUT) != WIFI_STATUS_OK) { TERMOUT("> ERROR : Failed to Receive Data\r\n"); }
  //    else {
  //        TERMOUT("> Received Data: \r\n");
  //        for (int i = 0; i < ReceivedDataLength; i++) {
  //            TERMOUT("%c", RxData[i]);
  //        }
  //        TERMOUT("\r\n");
  //    }
  //
  //    if(WIFI_CloseClientConnection(0) != WIFI_STATUS_OK) {  TERMOUT("> ERROR : Failed to close socket\r\n"); }
  //    float temp_value = 0;  // Measured temperature value
  //    char str_tmp[100] = ""; // Formatted message to display the temperature value
  //
  //    temp_value = BSP_TSENSOR_ReadTemp();
  //    int tmpInt1 = temp_value;
  //    float tmpFrac = temp_value - tmpInt1;
  //    int tmpInt2 = trunc(tmpFrac * 100);
  //    snprintf(str_tmp,100," TEMPERATURE = %d.%02d\n\r", tmpInt1, tmpInt2);
  //    HAL_UART_Transmit(&hDiscoUart,( uint8_t * )str_tmp,sizeof(str_tmp),1000);
  //
  //    float hum_value = BSP_HSENSOR_ReadHumidity();
  //    int humInt1 = hum_value;
  //    float humFrac = hum_value - humInt1;
  //    int humInt2 = trunc(humFrac * 100);
  //    char str_hum[100];
  //    snprintf(str_hum, 100, " HUMIDITY = %d.%02d\n\r", humInt1, humInt2);
  //    HAL_UART_Transmit(&hDiscoUart, (uint8_t *)str_hum, strlen(str_hum), 1000);
  //
  //    HAL_Delay(1000);
  //  }
