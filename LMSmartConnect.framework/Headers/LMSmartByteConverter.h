//
//  LHByteConverter.h
//  AqaraHome
//
//  Created by Charles on 2019/11/4.
//  Copyright © 2019 Lumi United Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LMSmartByteConverter : NSObject

#pragma mark - Value To Bytes
/// int8_t转Byte
/// @param value int8_t value
+ (const void *)byteFromInt8:(int8_t)value;

/// UInt8转Byte
/// @param value UInt8 value
+ (const void *)byteFromUInt8:(UInt8)value;

/// UInt16转Byte
/// @param value UInt16 value
+ (const void *)byteFromUInt16:(UInt16)value;

/// UInt24转Byte
/// @param value UInt32 value
+ (const void *)byteFromUInt24:(UInt32)value;

    
/// UInt32转Byte
/// @param value UInt32 value
+ (const void *)byteFromUInt32:(UInt32)value;

/// UInt64转Byte
/// @param value UInt64 value
+ (const void *)byteFromUInt64:(UInt64)value;

/// Short转Byte
/// @param value Short value
+ (const void *)byteFromShort:(short)value;

/// Bool转Byte
/// @param value Bool value
+ (const void *)byteFromBool:(BOOL)value;

/// String转NSData
/// @param value NSString value
+ (NSData *)byteFromString:(NSString *)value;

///不带\0
+ (NSData *)byteFromString2:(NSString *)value;
/// HexString转NSData
/// @param value NSString hex
+ (NSData *)byteHexStringToData:(NSString *)value;

#pragma mark - Btyes to Value
/// Byte转int8_t
/// @param bytes bytes
+ (int8_t)int8FromByte:(const char *)bytes;

/// Byte转UInt8
/// @param bytes bytes
+ (UInt8)UInt8FromByte:(const char *)bytes;

/// Byte转UInt16
/// @param bytes bytes
+ (UInt16)UInt16FromByte:(const char *)bytes;

/// Byte转UInt32
/// @param bytes bytes
+ (UInt32)UInt32FromByte:(const char *)bytes;

/// Byte转UInt64
/// @param bytes bytes
+ (UInt64)UInt64FromByte:(const char *)bytes;

/// Byte转Short
/// @param bytes bytes
+ (short)shortFrombyte:(const char *)bytes;

/// Byte转BOOL
/// @param bytes bytes
+ (BOOL)BoolFrombyte:(const char *)bytes;

/// Byte转NSData
/// @param bytes bytes
/// @param length bytes length
+ (NSData *)dateFromByte:(const void *)bytes withLength:(NSInteger)length;

/// Byte转NSString
/// @param bytes bytes
/// @param length bytes length
+ (NSString *)stringFromByte:(const void *)bytes withLength:(NSInteger)length;

/// NSData转NSString
/// @param data NSData
//+ (NSString *)stringFromData:(NSData*)data;

/// Byte转HexString
/// @param bytes bytes
/// @param length bytes length
+ (NSString *)hexStringFromeByte:(const void *)bytes withLength:(NSInteger)length;

//data转换为十六进制数据字符串
+ (NSString *)byteToHexString:(NSData *)data;

//大小端数据转换（其实还有更简便的方法）
+ (NSData *)dataTransfromBigOrSmall:(NSData *)data;

/// data转ascii字符串
+ (NSString *)dataToAsciiString:(NSData *)data;

//16进制字符串转整型
+ (NSInteger)byteToInteger:(NSData *)data;

//数字转十六进制字符串
+ (NSString *)numberToHexString:(NSUInteger)hexNumber;

@end

NS_ASSUME_NONNULL_END
