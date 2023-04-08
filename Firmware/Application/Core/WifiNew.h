/*******************************************************************************
 *                              C O P Y R I G H T  (c)
 *                                 D A R M O R ™
 *                             All Rights Reserved
 *******************************************************************************
 * @file        WifiNew.h
 * @copyright   COPYRIGHT (c) 2023 Darmor™. All rights reserved.
 * @author      Darren Morrison
 * @brief       Header file for Wifi functionality.
 ******************************************************************************/

#ifndef WIFI_H_
#define WIFI_H_

#ifdef __cplusplus
extern "C"	{
#endif

/** INCLUDES ******************************************************************/
#include "AplusAPP.h"
#include "wifi.h"

/** CONSTANT AND MACRO DEFINITIONS ********************************************/
// WiFi info
typedef struct Wifi {
    bool fConnected;                    // Flag of WiFi connection
    uint8_t u8Rssi;                     // Most recent RSSI value
    uint8_t u8Channel;                  // Most recent channel
    uint8_t au8IpAddr[4];               // IP Address
    uint8_t au8SubnetMask[4];           // Subnet Mask
    uint8_t au8Gateway[4];              // Gateway
    uint8_t au8Dns[4];                  // DNS Address
} sWiFiInfo; // STM32 Wifi stack sucks, Can't get anything but IP address from connected network.

#define TX_BUFFER_SIZE 4096


/** PUBLIC FUNCTION PROTOTYPES ************************************************/
int8_t Wifi_Init(void);
int8_t Wifi_Connect();

int8_t Wifi_IsConnected(void);

void Wifi_Send(void);

#ifdef __cplusplus
}
#endif

#endif
