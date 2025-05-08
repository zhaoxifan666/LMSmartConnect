//
//  LMMPQRCodeData.h
//  LMAccessNetSDK
//
//  Created by jeremy on 2023/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// MagicPair广播最少包含以下字段，共计11个byte
/// Manufacture 16bits
/// CoD  24 bits
/// Discriminator 12 bits
/// Vendor ID 16 bits
/// Product ID 16 bits
/// Password Required  2 bits
/// Is Commissioned  2 bits
#define kMagicPairDataMinLength 11

/// 套装二维码头部标识
#define kSuiteKitPayloadHeader @"PK_"
/// 套装二维码主设备头部标识
#define kSuiteKitMagicPairPayloadHeader @"_MP_"
/// MagicPair设备头部标识
#define kMagicPairPayloadHeader @"MP_"

/// Tag类型
typedef NS_ENUM(NSUInteger, LMMPBLEServiceDataModelTagType) {
    /// Tag ID: 0 == Aqara 多协议
    LMMPBLEServiceDataModelTagTypeMP = 0,
};

typedef NS_ENUM(int8_t, LMMPCommissioningFlow) {
    LMMPCommissioningFlowStandard = 0,
    LMMPCommissioningFlowUserAction = 1,
    LMMPCommissioningFlowCustom = 2,
};

@interface LMMPQRCodeData : NSObject

///3-bit value specifying the QR code payload version. SHALL be 000.
@property(nonatomic, assign)int8_t version;

/// 厂商ID
@property(nonatomic, assign)int16_t vendorId;

///产品ID是一个16 bits的数值
@property(nonatomic, assign)int16_t productId;

///入网流程，0表示标准流程，设备通电后，即可进入入网状态；1表示需要用户进行操作才能进入入网状态；2：表示自定义入网流程，由厂商来定义如何才能进入入网状态；3作为保留选项；
@property(nonatomic, assign) LMMPCommissioningFlow commissioningFlow;


/// bit 0：Soft AP； bit 1：BLE；bit 2：mDNS；bit 3~7 Reserved, Shall be 0
@property(nonatomic, assign)int8_t discoveryMethod;

///鉴别码是一个由12 bits组合而成的数值，它与设备在入网过程中广播的鉴别码的值相匹配，用于识别蓝牙、AP广播范围或者局域网内的设备
@property(nonatomic, assign)int16_t discriminator;

@property(nonatomic, assign)int16_t shortDiscriminator;

///17bits ,密码，若Passcode Required为0，则表示没有密码，密码数据须设置为0
@property(nonatomic, assign)int32_t pwd;

///2 bits
/// 0: No Required & No Passcode; 1: Have Passcode but No Required ; 2：Have Passcode & Required
@property(nonatomic, assign)int8_t pwdRequired;


///补齐 '0000’ ;4bits
@property(nonatomic, assign)int8_t padding;

//从蓝牙广播里读到的

/// 表示设备是否已入网。0：未入网 1：本地已入网 2：已绑定到Aq,3:设备超过窗口期
@property(nonatomic, assign)int8_t isCommissioned;

///是否支持滚动码标记位，若支持，则建立蓝牙连接后去读取Rotating ID
@property(nonatomic, assign)BOOL rotatingIDFlag;


///用于已建立配对关系后，手机筛选并连接到某个指定的设备。Device Matching采用2个字节表示，Device Matching = CRC16(did)。
@property(nonatomic, assign)uint16_t deviceMatching;


///是否支持双重安全鉴权。0表示仅支持本地安全鉴权，1表示本地和云端双重安全鉴权。
//@property(nonatomic, assign)BOOL twoFactorAuthentication;

///0：JSON 1：CBOR（针对资源受限设备类型，MagicPair的通讯报文格式采用CBOR编码（https://datatracker.ietf.org/doc/html/rfc8949），CBOR与JSON可实现无损互转。） 2~3：Reserved
@property(nonatomic, assign)uint8_t transmissionProtocol;


///MagicPair 版本号，范围是 0~255，支持获取 Device ID 功能从 20 版本开始。
@property(nonatomic, assign)uint8_t bleBrodcastVersion;

/// 预留拓展，默认为0
@property (nonatomic, assign) UInt8 reserve;

/// 1: 使能TLV拓展数据 0:关闭TLV拓展数据
@property (nonatomic, assign) BOOL tlvSupport;

/// Tag ID: 0 == Aqara 多协议
@property (nonatomic, assign) LMMPBLEServiceDataModelTagType tag;

/// 支持的协议类型
@property (nonatomic, assign) UInt8 supportProtocol;

/// 当前协议类型
@property (nonatomic, assign) UInt8 currentProtocol;

#pragma mark - 套装相关

///3-bit value specifying the QR code payload version. SHALL be 000.
@property (nonatomic, assign) UInt8 pk_version;

/// 厂商ID
@property (nonatomic, assign) UInt16 pk_vendorId;

///产品ID是一个16 bits的数值
@property (nonatomic, assign) UInt16 pk_productId;

/// 套装 唯一 ID，每台套装的 Unique ID 唯一，用于后续售后追踪。
@property (nonatomic, assign) UInt64 pk_uniqueId;

/// Padding
@property (nonatomic, assign) UInt16 pk_padding;

/// 解析扫到的QRcode数据
/// - Parameter dataStr: base36str
- (instancetype)initWithDataStr:(NSString*)dataStr;

/// 解析套装QRCode数据
/// - Parameter dataStr: base36str
- (instancetype)initWithPKDataStr:(NSString *)dataStr;

/// 解析蓝牙广播数据
/// - Parameter manufactureData: 广播数据
- (instancetype)initWithManufactureData:(NSData*)manufactureData;


/// 解析配对码
/// - Parameter digtalCode: 配对码
- (instancetype)initWithDigtalCode:(NSString*)digtalCode;


/// 解析dns广播
/// - Parameter mp: 输入数据
/// - Parameter did: 设备did
- (instancetype)initWithMdnsData:(NSString*)mp did:(NSString*)did;

///是否需要密码
- (BOOL)isPassCodeRequired;



@end

/// 安全鉴权类型
typedef NS_ENUM(UInt8, LMMPBLEServiceDataModelAuthType) {
    /// 开放式鉴权
    LMMPBLEServiceDataModelAuthTypeOpen = 1 << 0,
    /// SPAKE2+
    LMMPBLEServiceDataModelAuthTypeSpake = 1 << 1,
};

/// 协议切换方式
typedef NS_ENUM(UInt8, LMMPBLEServiceDataModelProtocolConversionMethodType) {
    /// OTA
    LMMPBLEServiceDataModelProtocolConversionMethodTypeOTA = 1 << 0,
    /// APP
    LMMPBLEServiceDataModelProtocolConversionMethodTypeAPP = 1 << 1,
};

/// 协议类型
typedef NS_ENUM(UInt8, LMMPBLEServiceDataModelProtocolType) {
    /// Matter
    LMMPBLEServiceDataModelProtocolTypeMatter = 1 << 0,
    /// Zigbee
    LMMPBLEServiceDataModelProtocolTypeZigbee = 1 << 1,
};

/// 双协议广播报文模型
@interface LMMPBLEServiceDataModel : NSObject

/// 协议操作码（Aqara多协议广播数据单元 == 0）
@property (nonatomic, assign) NSInteger opCode;

/// 协议版本号
@property (nonatomic, assign) NSInteger version;

/// 安全鉴权
@property (nonatomic, assign) LMMPBLEServiceDataModelAuthType securityAuthentication;

/// 协议切换方式
@property (nonatomic, assign) LMMPBLEServiceDataModelProtocolConversionMethodType protocolConversionMethodType;

/// 支持的协议类型
@property (nonatomic, assign) LMMPBLEServiceDataModelProtocolType supportProtocol;

/// 当前协议类型
@property (nonatomic, assign) LMMPBLEServiceDataModelProtocolType currentProtocol;

///// 是否是双协议的广播报文
///// - Parameter advertisementData: 广播报文
//+ (BOOL)isMultipleProtocolsDevice:(NSDictionary<NSString *,id> *)advertisementData;

/// 是否是Matter设备广播报文
/// - Parameter advertisementData: 广播报文
+ (BOOL)isMatterDevice:(NSDictionary<NSString *,id> *)advertisementData;

/// 是否是MagicPair设备广播报文
/// - Parameter advertisementData: 广播报文
+ (BOOL)isMagicPairDevice:(NSDictionary<NSString *,id> *)advertisementData;

- (instancetype)initWithServcieData:(NSData *)data;

@end

/// Matter广播报文模型
@interface LMMatterBLEServiceDataModel : NSObject

@property (nonatomic, assign) NSInteger opCode;

@property (nonatomic, assign) NSInteger version;

@property (nonatomic, assign) NSInteger discriminator;

@property (nonatomic, assign) NSInteger vendorId;

@property (nonatomic, assign) NSInteger productId;

@property (nonatomic, assign) NSInteger flag;

- (instancetype)initWithServcieData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
