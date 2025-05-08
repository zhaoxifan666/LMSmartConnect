//
//  LMMPErrorCodeTool.h
//  LMAccessNetSDK
//
//  Created by jeremy on 2023/6/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LMMPErrorCodeTool : NSObject

//错误码定义：https://confluence.aqara.com/pages/viewpage.action?pageId=91702194

typedef enum : NSUInteger {
  LMMPNetErrorCodeBlePowerOff = 0,//蓝牙开关没开
  LMMPNetErrorCodeUnknown = 3,//设备入网失败，且必须要重置设备，此时设备处于白灯亮的情况
//  LMMPNetErrorCodeSsidPwdWrong = 5,//用户输入密码不对
  LMMPNetErrorCodeBoundSuccess = 6,//连接WiFi成功后，绑定AIOT成功
  LMMPNetErrorCodeBoundFailure = 7,//设备入网失败，但无需重置设备，应引导用户进行重试，此时设备处于蓝灯亮的情况。设备应上报错误码BoundFailure
  LMMPNetErrrorCodeDeviceAlreadyRegister = 10, ///  <设备已注册，拒绝重新 注册
  LMMPNetErrorCodeReceiveDataTimeOut = 10014,//设备没有在5秒内回复
  LMMPNetErrorCodeReceiveDatainComplete = 41,//设备回复的数据不完整
  LMMPNetErrorCodebleLoginFailure = 12,//登录校验不通过
  LMMPNetErrorCodeBleConnectTimeout = 10008,//蓝牙连接超时10秒
  LMMPNetErrorCodebleScanTimeOutWithOutPid = 14,//蓝牙扫描，默认15秒不带pid
  LMMPNetErrorCodebleScanTimeOutWithPid = 15,//蓝牙扫描，默认15秒带pid
  LMMPNetErrorCodeBleDisconnect = 10007,//蓝牙断开
  LMMPNetErrorCodeZigbeeAccessNetTimeout = 10012,//子设备入网超时(10012)
  LMMPNetErrorCodeCameraAntiTheftMode = 11,//摄像头防盗模式错误码
  LMMPNetErrorCodeServerSignVerifyFailure = 7162,//未认证设备,退出
  LMMPNetErrorCodeCerficateTokenVerifyFailure = 7163,//token校验失败,需要重置
  LMMPNetErrorCodePublicKeyVerifyFailure = 5,//云端公钥校验失败
  LMMPNetErrorCodeDeviceRegisterFailure = 7164,//设备注册到云端失败,重试三次
} LMMPNetErrorCode;


+ (NSError*)generateErrorWithCode:(LMMPNetErrorCode)statusCode;

+ (NSError*)generateErrorWithCode:(LMMPNetErrorCode)statusCode title:(NSString*)title erroMessage:( NSString*)errorMsg andBtnText:(NSString*)btnText;

+ (BOOL)needRetry:(NSInteger)code;

@end

typedef enum : NSUInteger {
    /// 连接OTA设备超时
    LMMPOTAErrorCodeConnectTimeout = 100000,
    /// 服务未发现
    LMMPOTAErrorCodeServiceNotFound = 100001,
    /// 特征值未发现
    LMMPOTAErrorCodeCharacteristicNotFound = 100002,
    /// OTA升级失败
    LMMPOTAErrorCodeUpdateFailed = 100003,
    /// OTA下载失败
    LMMPOTAErrorCodeDownloadFailed = 100004,
    /// OTA文件校验失败
    LMMPOTAErrorCodeMD5VerifyFailed = 100005,
} LMMPOTAErrorCode;

FOUNDATION_EXPORT NSString *const kMPOTAErrorDomain;

@interface LMMPErrorCodeTool (OTA)

+ (NSError *)generateOTAErrorWithCode:(LMMPOTAErrorCode)statusCode;

+ (NSError *)generateOTAErrorWithCode:(LMMPOTAErrorCode)statusCode errorCode:(NSInteger)errorCode;

+ (NSError*)generateOTAErrorWithCode:(LMMPOTAErrorCode)statusCode
                            navTitle:(NSString *)navTitle
                               title:(NSString *)title
                         erroMessage:(NSString *)errorMsg
                          andBtnText:(NSString *)btnText;

@end

NS_ASSUME_NONNULL_END
