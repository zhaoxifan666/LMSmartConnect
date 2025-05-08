//
//  LMSmartBLEConst.h
//  LMSmartConnect
//
//  Created by jeremy on 2021/7/26.
//

#import<Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kNotificationSleepConnectNotificationName @"kNotificationSleepConnectNotificationName"

//注册回调数据类型
typedef enum {
    LH_UNKNOW_TYPE,         //未知类型
    LH_LOCK_BLE_REG_DID,        //数据类型是请求did返回的
    LH_LOCK_BLE_REG_REG_START,
    LH_LOCK_BLE_REG_PUBKEY_EX, //数据类型是请求密钥(pubkey)交换返回的
    LH_LOCK_BLE_REG_VERIFY,   //数据交互认证
    LH_LOCK_BLE_REG_NOTIFY,  //注册成功通知
    LH_LOCK_BLE_REG_LOGINSTART, //登录开始
    LH_LOCK_BLE_REG_LOGINVERIFY, //登录认证
    LH_LOCK_BLE_DEVICE_INFO, // 获取子设备信息
    LH_LOCK_BLE_SEND_BACK,  //子设备回复
    LH_LOCK_BLE_REG_BUTT
}LH_LOCK_BLE_REG_DATA_TYPE;

/// OTA错误码
typedef enum {
    LM_BLE_FIRMWARE_ERROR_NONE = 0x00, //没有错误
    LM_BLE_FIRMWARE_ERROR_COMMON = 0x01, //通用错误
    LM_BLE_FIRMWARE_ERROR_BLECRC =0x02, //BLE CRC校验失败
    LM_BLE_FIRMWARE_ERROR_FLASHCODE = 0x03, //FLASH 校验失败
    LM_BLE_FIRMWARE_ERROR_DATALEN = 0x04, //数据长度有误
    LM_BLE_FIRMWARE_ERROR_LOWPOWER = 0x05, //电量低不予许升级
    LM_BLE_FIRMWARE_ERROR_DECRYP = 0x06, //数据解码失败
    LM_BLE_FIRMWARE_ERROR_RAND_TIMEOUT = 0x07, //随机数超时
    LM_BLE_FIRMWARE_ERROR_RAND_NOTMATCH = 0x08, //随机数不匹配
    LM_BLE_FIRMWARE_ERROR_OTA = 0x09, //OTA 固件长度错误
    LM_BLE_FIRMWARE_ERROR_REJ = 0x0a, // 设备已经注册
    LM_BLE_FIRMWARE_ERROR_NOTSUPPORT = 0x0b, //要求特性不支持
    LM_BLE_FIRMWARE_ERROR_VER_FAIL = 0x0c,   //证书链校验失败
    LM_BLE_FIRMWARE_ERROR_FAIL = 0x0d,   //注册校验失败
    LM_BLE_FIRMWARE_ERROR_LOGIN_FAIL = 0x0e, //登录校验不通过
    LM_BLE_FIRMWARE_ERROR_ENCRYPT = 0x0f,    //要求通信加密
    LM_BLE_FIRMWARE_ERROR_OTA_INDEX = 0x10,  //OTA碎片包序号错误
    LM_BLE_FIRMWARE_ERROR_OTA_COMMAND = 0x11, //OTA命令不支持
    LM_BLE_FIRMWARE_ERROR_OTA_VERSION = 0x12, //OTA 版本不匹配
    LM_BLE_FIRMWARE_ERROR_OTA_PARAMS = 0x13,  //OTA参数错误
    LM_BLE_FIRMWARE_ERROR_OTA_INTERRUPT = 0x14, //OTA断点序号错误
    LM_BLE_FIRMWARE_ERROR_OTA_JUMP = 0x15, //OTA碎片包序号需要跳转
    LM_BLE_FIRMWARE_ERROR_OTA_BUSY = 0x16, //OTA正忙
    LH_BLE_FIRMWARE_ERROR_UNSUPPORT_CHANGE_PROTOCOL = 0x17, //指定切换的协议不支持
    LH_BLE_FIRMWARE_ERROR_OTA_FRAGGMENT_SEQ_NUM = 0x18, // OTA碎片序号错误
    LH_BLE_FIRMWARE_ERROR_OTA_PROTOCOL_TYPE_NOT_SET = 0x19, // 未指定协议类型
    LH_BLE_FIRMWARE_ERROR_OTA_CONFIG_NOT_FOUND = 0x20 //设备未烧录配置文件
}LM_BLE_FIRMWARE_ERROR_CODE;

/// 蓝牙OTA命令
typedef NS_ENUM(UInt16, LMAccessNetMPBLEOTACmd) {
    /// 查询上次 OTA 信息
    LMAccessNetMPBLEOTACmdLastOTAInfo = 0x0001,
    /// 开始 OTA 升级
    LMAccessNetMPBLEOTACmdStartOTAUpgrade = 0x0002,
    /// 退出 OTA 升级
    LMAccessNetMPBLEOTACmdExitOTAUpgrade = 0x0003,
    /// OTA 状态上报
    LMAccessNetMPBLEOTACmdOTAStateReport = 0x0004,
    /// RFU
    LMAccessNetMPBLEOTACmdRFU1 = 0x0005,
    /// RFU
    LMAccessNetMPBLEOTACmdRFU2 = 0x0006,
    /// 发送 OTA 升级包数据
    LMAccessNetMPBLEOTACmdSendOTAUpgradeData = 0x0007,
    /// 获取真实固件偏移
    LMAccessNetMPBLEOTACmdGetOTAOffset = 0x0008,
    /// 发送固件头信息
    LMAccessNetMPBLEOTACmdSendOTAHeader = 0x0009,
    /// 获取设备当前版本号
    LMAccessNetMPBLEOTACmdGetVersion = 0x000A,
    /// 获取指定协议升级包信息,TLV格式返回
    /// 0x00: Reserve
    /// 0x01: Matter Info
    /// 0x02: Zigbee Info
    /// 0x03 ~ 0xFF: Reserve
    LMAccessNetMPBLEOTACmdGetProtocolInfo = 0x000B,
};

//注册回调状态码
//#define LH_LOCK_BLE_REG_ERROR_TIMEOUT (999)
typedef enum {
    LH_LOCK_BLE_REG_ERROR_NONE = 0x00, //没有错误
    LH_LOCK_BLE_REG_ERROR_COMMON = 0x01, //通用错误
    LH_LOCK_BLE_REG_ERROR_BLECRC =0x02, //BLE CRC校验失败
    LH_LOCK_BLE_REG_ERROR_FLASHCODE = 0x03, //FLASH 校验失败
    LH_LOCK_BLE_REG_ERROR_DATALEN = 0x04, //数据长度有误
    LH_LOCK_BLE_REG_ERROR_LOWPOWER = 0x05, //电量低不予许升级
    LH_LOCK_BLE_REG_ERROR_DECRYP = 0x06, //数据解码失败
    LH_LOCK_BLE_REG_ERROR_RAND_TIMEOUT = 0x07, //随机数超时
    LH_LOCK_BLE_REG_ERROR_RAND_NOTMATCH = 0x08, //随机数不匹配
    LH_LOCK_BLE_REG_ERROR_OTA = 0x09, //OTA 固件长度错误
    LH_LOCK_BLE_REG_ERROR_REJ = 0x0a, // 设备已经注册
    LH_LOCK_BLE_REG_ERROR_NOTSUPPORT = 0x0b, //要求特性不支持
    LH_LOCK_BLE_REG_ERROR_VER_FAIL = 0x0c,   //证书链校验失败
    LH_LOCK_BLE_REG_ERROR_REG_FAIL = 0x0d,   //注册校验失败
    LH_LOCK_BLE_REG_ERROR_LOGIN_FAIL = 0x0e, //登录校验不通过
    LH_LOCK_BLE_REG_ERROR_ENCRYPT = 0x0f,    //要求通信加密
    
    LH_LOCK_BLE_REG_ERROR_CUSTOM = 9999,         //自定义错误
    LH_LOCK_BLE_REG_ERROR_TIMEOUT = 10000,   //添加超时
    LH_LOCK_BLE_REG_ERROR_LOGIN_TIMEOUT = 10001, //登录超时
    LH_LOCK_BLE_REG_ERROR_LOGIN_DID_EMPTY = 10002, //DID为空
    LH_LOCK_BLE_REG_ERROR_DEVICE_RESET = 10003,    //设备已经重置
}LH_LOCK_BLE_REG_ERROR_CODE;


NS_ASSUME_NONNULL_END
