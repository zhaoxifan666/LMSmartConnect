//
//  LMMPDefine.h
//  Pods
//
//  Created by jeremy on 2023/7/31.
//

#ifndef LMMPDefine_h
#define LMMPDefine_h

typedef enum : NSUInteger {
  LMMPEntrancePageTypeAccessNet=1,
  LMMPEntrancePageTypeUpdateSSid=2,
  LMMPEntrancePageTypeSwitchGateway=3,
} LMMPEntrancePageType;


///指的是设备MagicPair入网采用的通讯协议，但不包括用于设备配对所采用的BLE协议。
typedef enum : NSUInteger {
  LMMPDeviceAccessNetTypeWiFi = 1<<0,
  LMMPDeviceAccessNetTypeThread = 1<<1,
  LMMPDeviceAccessNetTypeEthernet = 1<<2,
  LMMPDeviceAccessNetTypeZigbee = 1<<3,
  LMMPDeviceAccessNetTypeBle = 1<<4,
    /// 蓝牙子设备
    LMMPDeviceAccessNetTypeBLEEndpoint  = 1 << 5,
    /// WiFi子设备
    LMMPDeviceAccessNetTypeWiFiEndpoint = 1 << 6,
    /// 预留
    LMMPDeviceAccessNetTypeReserved     = 1 << 7,
} LMMPDeviceAccessNetType;

/// 广播报文
#define kAqaraManufactureUUID [CBUUID UUIDWithString:@"0B27"]

/// 登录注册
#define kAqaraRegisterBLEServiceUUID [CBUUID UUIDWithString:@"FFA0"]
#define kAqaraRegisterBLEWriteCharactersticUUID [CBUUID UUIDWithString:@"FFB1"]
#define kAqaraRegisterBLEReadCharacteriticUUID [CBUUID UUIDWithString:@"FFB2"]

/// MagicPair
#define kMagicPairBLEServiceUUID [CBUUID UUIDWithString:@"FCB9"]
#define kMagicPairBLEWriteCharactersticUUID [CBUUID UUIDWithString:@"FF07"]
#define kMagicPairBLEReadCharacteriticUUID [CBUUID UUIDWithString:@"FF08"]
/// 新的MagicPairUUID
#define kMagicPairBLEWriteCharactersticUUIDNew [CBUUID UUIDWithString:@"802DFF07-2E76-4E66-89A0-524806BE3AD5"]
#define kMagicPairBLEReadCharacteriticUUIDNew [CBUUID UUIDWithString:@"802DFF08-2E76-4E66-89A0-524806BE3AD5"]

/// 多协议
#define kMultipleProtocolsDataMinLength 4 /// 双协议广播最小数据长度

/// Matter
#define kMatterBLEServiceUUID [CBUUID UUIDWithString:@"FFF6"]
#define kMatterBLEDataMinLength 8 /// Matter广播最小数据长度

/// OTA
#define kAqaraOTAWriteCharactersticUUID [CBUUID UUIDWithString:@"802DFD01-2E76-4E66-89A0-524806BE3AD5"]
#define kAqaraOTAReadCharacteriticUUID [CBUUID UUIDWithString:@"802DFD02-2E76-4E66-89A0-524806BE3AD5"]

#endif /* LMMPDefine_h */
