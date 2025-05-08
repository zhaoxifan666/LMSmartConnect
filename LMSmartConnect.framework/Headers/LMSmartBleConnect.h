//
//  LMSmartBleConnect.h
//  LMSmartConnect
//
//  Created by MadHeart on 2021/7/8.
//

#import <Foundation/Foundation.h>

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LMSmartBleConnectType_gateway,
    LMSmartBleConnectType_zigbee,
} LMSmartBleConnectType;

@interface LMSmartBleConnect : NSObject

+ (instancetype)sharedInstance;


/// 开启蓝牙扫描
/// @param manufacture 广播数据中的设备厂商
/// @param model 广播数据中需要过滤的设备model数组
/// @param macAddress 指定设备的蓝牙地址
/// @param completion 结果回调（蓝牙状态、发现的外设、当前外设广播数据）， 这里屏蔽了系统的蓝牙弹框提示，需要自己根据蓝牙状态进行权限提醒
- (void)startBluetoothScanDevice:(NSString *)manufacture model:(NSArray *)models macAddress:(NSString *)macAddress completion:(void (^)(CBManagerState state, CBPeripheral *peripheral, NSString *macAddress, NSString *model))completion;




/// 停止蓝牙发现设备
- (void)stopBluetoothScanDevice;

- (void)disconnect;

/// 配置服务，读写特征值然后开始连接蓝牙
/// @param peripheralId 外设的id
/// @param serviceId 外设的服务id
/// @param writeCharacteristicId 写值特征id
/// @param readCharacteriticId 读值特征id
/// @param completion 结果回调
- (void)startConnectBleWithPeripheral:(NSString *)peripheralId serviceId:(NSString *)serviceId writeCharacteristicId:(NSString *)writeCharacteristicId readCharacteriticId:(NSString *)readCharacteriticId completion:(void (^)(NSError *error))completion;



/// 开始蓝牙入网
/// @param bleConnectType 蓝牙入网类型
/// @param bindKey bindKey 从私有云获取，不传会自动获取
/// @param homeId 设备入网的家庭位置，如果已经有bindKey，可不传
/// @param ssid wifi ssid
/// @param password wifi password
/// @param countryDomain access net domian url
/// @param deviceDomain 设备连接互联网的地址，设备不支持的话可以不传
/// @param completion 结果回调
/// @param macAddress 设备的mac地址，没有可以不传
- (void)startBleAccessToNetWithType:(LMSmartBleConnectType)bleConnectType
                            bindKey:(nullable NSString *)bindKey
                             homeId:(NSString *)homeId
                               ssid:(NSString *)ssid
                           password:(NSString *)password
                      countryDomain:(NSString *)countryDomain
                       deviceDomain:(nullable NSString *)deviceDomain
                         macAddress:(nullable NSString *)macAddress
                         completion:(void (^)(NSError *error))completion;

/// 开始蓝牙子设备入网
/// @param gatewayDid 所入网网关的did
/// @param model 该设备的model
/// @param homeId 家庭id
/// @param isBleSubDevice 当前是否为纯蓝牙子设备
/// @param completion 回调
- (void)startZigbeeBleAccessToNetWithGatewayDid:(NSString *)gatewayDid model:(NSString *)model homeId:(NSString *)homeId isBleSubDevice:(BOOL)isBleSubDevice completion:(void (^)(NSString *did, NSError *error))completion;
@end

NS_ASSUME_NONNULL_END
