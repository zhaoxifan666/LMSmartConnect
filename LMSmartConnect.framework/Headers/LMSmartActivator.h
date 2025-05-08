//
//  LMSmartActivator.h
//  LMSmartConnect
//
//  Created by MadHeart on 2021/3/9.
//

#import <Foundation/Foundation.h>

#import <CoreBluetooth/CoreBluetooth.h>


NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LMConnectModeAP,
//    LMConnectModeTCP,
    LMConnectModeEthernet,
} LMConnectMode;

@interface LMSmartActivator : NSObject

+ (instancetype)sharedInstance;

/// get current phone ssid; return "nil" when occur error
- (NSString *)currentWiFiName;




/// config device access to the network
/// @param mode mode of access to network (AP / TCP / Ethernet(UDP).)
/// @param ssid WiFi ssid
/// @param password WiFi password
/// @param bindkey the key of access to network
/// @param countryDomain  the coap url of device access to network
/// @param ipAddress the device ip address , use it by LMConnectModeEthernet. Other, send the @"" or "nil";
/// @param completion result
- (void)startConfigConnect:(LMConnectMode)mode
                      ssid:(NSString *)ssid
                  password:(NSString *)password
                   bindkey:(NSString *)bindkey
             countryDomain:(NSString *)countryDomain
                 ipAddress:(NSString *)ipAddress
                completion:(void (^)(NSDictionary *_Nullable resonse, NSError *_Nullable error))completion;



/*
 
 Bluetooth蓝牙
 
 */
/// 开启蓝牙扫描
/// @param manufacture 广播数据中的设备厂商
/// @param model 广播数据中的设备model
/// @param macAddress 指定设备的蓝牙地址
/// @param completion 结果回调（蓝牙状态、发现的外设、当前外设广播数据）
- (void)startBluetoothScanDevice:(NSString *)manufacture model:(NSString *)model macAddress:(NSString *)macAddress completion:(void (^)(CBManagerState state, CBPeripheral *peripheral, NSString *macAddress, NSString *model))completion;



- (void)stopBluetoothScanDevice;





/*
 
 mDNS
 
 */
/// Discover mDNS device
/// @param type type name
/// @param domain domain
/// @param model device model, may nil
/// @param completion result block
- (void)startScanDeviceByAP_mDNSWithType:(NSString *)type domain:(NSString *)domain model:(NSString *)model completion:(void (^)(NSArray<NSNetService *> *serviceList,  NSError * _Nullable error))completion;


/// Discover mDNS device
/// @param type type name
/// @param domain domian
/// @param did device did
/// @param completion result block
- (void)startScanDeviceByAP_mDNSWithType:(NSString *)type domain:(NSString *)domain did:(NSString *)did completion:(void (^)(NSArray<NSNetService *> * _Nonnull, NSError * _Nullable))completion;


- (void)startSwitchPlatformForDeviceIpAddress:(NSString *)ipAddress port:(NSInteger)port completion:(void (^)(NSDictionary *response, NSError *error))completion;

/// Stop discover mDNS device
- (void)stopScanDevicByAp_mDNS;

/// resovle the ip address from the device mDNS
/// @param netService NSNetService Object
- (NSString *)resovleIpAddressInNetService:(NSNetService *)netService;

/// resovle the port from the device mDNS
/// @param netService NSNetService Object
- (NSInteger)resovlePortInNetService:(NSNetService *)netService;



#pragma -mark TCP

/// connect and access to net by TCP
/// @param ipAddress ipAddress (if not, send the @"" or nil)
/// @param port device ip Port
/// @param bindKey bindkey
/// @param ssid wifi ssid
/// @param password wifi password
/// @param completion result
- (void)startConfigNetByTCPWithIpAddress:(NSString *)ipAddress port:(NSString *)port bindKey:(NSString *)bindKey ssid:(NSString *)ssid password:(NSString *)password completion:(void (^)(NSError *))completion;

/// Connect device by TCP
/// @param ipAddress device ip (if not, send the @"")
/// @param port device port
/// @param completion result
- (void)startConnectByTCPWithIpAddress:(NSString *)ipAddress port:(NSString *)port completion:(void (^)(NSError *error))completion;


/// AccessNet devce by TCP
/// @param bindKey bindKey
/// @param ssid wifi ssid
/// @param password wifi password
/// @param completion result
- (void)startAccessNetByTCPWithBindKey:(NSString *)bindKey ssid:(NSString *)ssid password:(NSString *)password completion:(void (^)(NSError * _Nonnull))completion;
@end

NS_ASSUME_NONNULL_END
