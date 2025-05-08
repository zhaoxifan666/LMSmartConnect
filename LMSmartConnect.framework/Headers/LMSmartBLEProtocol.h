//
//  LHLHRemoveModelBLEProtocol.h
//  AqaraHome
//
//  Created by 赵希帆 on 2020/12/30.
//  Copyright © 2020 Lumi United Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LMSmartBLEConst.h"
//#import "LHByteConverter.h"
//#import "LHCommonSecurityTool.h"

#define LH_DQ1_MODELID @"0110a55a"
#define LH_BLE_MODELID @"0100a55a"

/*
 val SERVICE_UUID: UUID = UUID.fromString("0000ff60-2333-5b1e-9d7c-c687fd2f04f2")
 val WRITE_UUID: UUID = UUID.fromString("0000ff61-2333-5b1e-9d7c-c687fd2f04f2")
 val NOTIFY_UUID: UUID = UUID.fromString("0000ff62-2333-5b1e-9d7c-c687fd2f04f2")
 val OTA_WRITE_UUID: UUID = UUID.fromString("0000ff63-2333-5b1e-9d7c-c687fd2f04f2")
 val OTA_NOTIFY_UUID: UUID = UUID.fromString("0000ff64-2333-5b1e-9d7c-c687fd2f04f2")
 val DESCRIPTOR_UUID: UUID = UUID.fromString("00002902-0000-1000-8000-00805f9b34fb")

 val REG_SERVICE_UUID: UUID = UUID.fromString("0000ffa0-0000-1000-8000-00805f9b34fb")
 val REG_WRITE_UUID: UUID = UUID.fromString("0000ffb1-0000-1000-8000-00805f9b34fb")
 val REG_NOTIFY_UUID: UUID = UUID.fromString("0000ffb2-0000-1000-8000-00805f9b34fb")
 */


@interface LMSmartBLEProtocol : NSObject
 
+(NSArray<NSData*>*)reg_getDID;

+(NSArray<NSData*>*)reg_regStart;

+(NSArray<NSData*>*)reg_pubKeyExchange:(NSString *)pubKey;

+(NSArray<NSData*>*)reg_verifyAppConfirm:(NSString *)appConfirm appRand:(NSString *)appRand cloudRand:(NSString *)cloudRand;

+(NSArray<NSData*>*)reg_notifySuccess:(BOOL)isSuccess;

//登录开始
+(NSArray<NSData*>*)reg_loginStart:(NSString *)pubKey;

//登录认证
+(NSArray<NSData*>*)reg_loginVerify:(NSString *)verfiyData;

/// 获取子设备信息
+(NSArray<NSData *> *)ble_getBleInfo;

/// 发送普通数据
+(NSArray<NSData *> *)ble_sendCommand:(NSData *)infoData;

+(NSArray<NSData*> *)reg_unPackCMD:(NSData *)cmd isEncrypt:(BOOL)encrypt fragContent:(NSData *)content packLength:(NSInteger)packLength;

+(NSArray<NSData*> *)reg_unPackCMD:(NSData *)cmd 
                         isEncrypt:(BOOL)encrypt
                       fragContent:(NSData *)content
                        packLength:(NSInteger)packLength
                    fragmentsIndex:(int)fragmentsIndex
                   isLastFragments:(BOOL)isLastFragments;

+(NSArray<NSData *> *)ota_upPackData:(NSData *)data maxFragmentLength:(NSInteger)maxFragmentLength;
 
+(void)reg_appendData:(NSData *)data CB:(void(^)(LH_LOCK_BLE_REG_DATA_TYPE,id,NSError *))cb;

+(void)reg_appendFirmwareUpdateData:(NSData *)data CB:(void(^)(LMAccessNetMPBLEOTACmd,id,NSError *))cb;

@end

@interface LHRemoveModelShortPackModel : NSObject

@end

/*
0x01 用户 ID HEX 0x02 日志 HEX
0x03 硬件信息 HEX
0x04 WiFi 信息 UTF-8
0x05 NFC 公钥 HEX
0x06 OTA RSA 公钥 HEX
0x07 Wifi bindkey HEX
0x08 临时密码 HEX
0x09 待删除的用户 ID HEX
0x0A 设备信息 HEX
0x0B NFC CPLC HEX
0x0C NFC APDU HEX
0x0D NFC APDU_1 ASCII
0x0E 最新一条日志 HEX
0x0F 第一页重启信息 HEX
0x10 第二页重启信息 HEX
0x11 SE 写 APDU 结果回复 HEX
0x12 日志 V2 HEX
 */


