//
//  LMSmartConnectManager.h
//  LMSmartConnect
//
//  Created by 江顺金 on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^LMSDKCallBack)(__nullable id response, NSError * _Nullable error);

@interface LMSmartConnectManager : NSObject

// LumisdkSendEncrypData2TargetDevice(paramStr, ipAddress, callBack)

/// 发送数据到指定ip地址
/// @param paramStr 数据参数
/// @param ipAddress ip地址
/// @param callBack 回调
+ (void)sendEncrypData:(NSString *)paramStr toIpAddress:(NSString *)ipAddress callBack:(LMSDKCallBack)callBack;

// LumisdkGatewayFastLink(NO, paramStr, callBack);

/// 网关入网
/// @param paramStr 入网参数
/// @param callBack 回调
- (void)gatewayFastLinkByUDPWithData:(NSString *)paramStr callBack:(LMSDKCallBack)callBack;

// LumisdkGetTimeZone
/// 获取当前时区
+ (NSString *)getTimeZone;

+ (NSString *)getIPAddress;

+ (NSString *)jsonStringFromObject:(id)object;

+ (NSData *)aes256EncryptWithData:(NSData *)data;

+ (NSData *)aes256DecryptWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
