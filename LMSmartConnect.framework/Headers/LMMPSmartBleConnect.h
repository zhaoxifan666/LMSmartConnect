//
//  LMSmartBleConnect.h
//  LMSmartConnect
//
//  Created by MadHeart on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN


@class LMMPQRCodeData;
@class LMMPBLEDevice;
@class LMSmartBLEConnectMPData;
@class LMAccessNetCategoryDevice;
@class MTRSetupPayload;

@interface LMMPSmartBleConnect: NSObject


/// Magic Pair二维码的数据
@property(nonatomic, strong)LMMPQRCodeData* qrCodeModel;


//监听网线是否插上
- (void)setSupportNetWorkCompleitonObserver:(void (^)(NSError *, BOOL ethernetIsReady))supportNetWorkCompleitonObserver;

+ (instancetype)sharedInstance;

- (void)stopScan;
/// 断开蓝牙
- (void)disconnect;

///入网成功，清除数据缓存
- (void)clearCache;

#pragma mark - Ble

- (NSString *)getBLEDeviceId;

- (NSString *)getBLEGatewayId;

- (BOOL)isLogin:(NSString *)did;

- (void)setSelectedBleDevice:(LMMPBLEDevice *)device;

- (LMMPBLEDevice*)selectedBledevice;

/// 查询设备支持的平台
/// @param completion completion
- (void)querySupportedEcosystem:(void (^)(NSError* error,NSInteger value))completion;

/// 发送重启命令
/// @param completion 回调
- (void)sendRestartWithCompletion:(void (^)(NSError * _Nullable error))completion;

/// 打开Matter配对窗口
/// @param completion 回调
- (void)openMatterCommissioningWindowWithCompletion:(void (^)(NSError * _Nullable error))completion;

/// 移除Matter生态
/// @param vendorId 厂商Id
- (void)removeMatterFabricWithVendorId:(NSInteger)vendorId completion:(void (^)(NSError * _Nullable))completion;

/// 查询已绑定的生态信息
- (void)queryBoundEcosystemWithCompletion:(void (^)(NSError * _Nullable error, NSInteger value))completion;

/// 查询已连接的MatterFabrics
- (void)queryConnectedMatterFabricsWithCompletion:(void (^)(NSError * _Nullable error, NSArray *fabric))completion;

/// 查询设备的MatterPayload，门锁会打开配对窗口，并返回配对码信息
/// @param completion completion
- (void)queryMatterPayloadCompletion:(void (^)(NSError* error,NSInteger bind, NSString* qrCode,NSString*digitalPairingCode))completion;

/// 查询设备支持的网络
/// @param completion completion
- (void)querySupportedNetworkCompletion:(void (^)(NSError* error,NSInteger supportedNetworkValue,NSInteger lanStatus))completion;

///ble发送ssid 和密码
- (void)bleSendSsidAndPwdCompletion:(void(^)(NSInteger statusCode,NSError* error))completion;

/// 从云端查询设备绑定结果
/// - Parameter completion: 回调

- (void)queryBindResultCompletion:(void (^)(BOOL isZigbee,NSInteger supportNetWork,id result, NSError *error))completion;

- (void)queryZigbeeBindResultCompletion:(void (^)(BOOL isZigbee,NSInteger supportNetWork,id result, NSError *error))completion;

- (void)queryzigBeeInfoData:(void(^)(NSError* error,NSString* installCode,NSString* macAdress))completion;

///蓝牙扫描
- (void)startScanBleDeviceTimeout:(NSTimeInterval)timerInterval completion:(void(^)(NSArray<LMMPBLEDevice*>*devices,NSError* error))completion;

/// mdns和蓝牙扫描
- (void)startScanMdnsAndBleWithTimeout:(NSInteger)timeout completion:(void (^)(NSArray<LMMPBLEDevice *> *totals, NSError * _Nonnull error))completion;

///从扫描列表里移除某个设备
- (void)removeDeviceForDiscriminator:(NSString*)key;

/// 蓝牙扫描时，选择的设备
/// - Parameter selectedDevice:
- (void)setSelectedDevice:(LMMPBLEDevice *)selectedDevice;

- (void)startScanWithDid:(NSString*)did completion:(void(^)(NSError*))completion;

/// 扫描MagicPair设备广播
/// - Parameters:
///   - str: 二维码信息
///   - completion: 回答
- (void)startWithMagicPairPayload:(NSString *)str completion:(void (^)(NSError * _Nullable error, LMMPBLEDevice * _Nullable device))completion;

/// 扫描Matter设备广播
/// - Parameters:
///   - payload: 二维码信息
///   - completion: 回调
- (void)startWithMatterSetupPayload:(MTRSetupPayload *)payload completion:(void (^)(NSError * _Nullable error, LMMPBLEDevice * _Nullable device))completion API_AVAILABLE(ios(16.2), macos(13.1), watchos(9.2), tvos(16.2));

- (void)sendZigbeeInfoWithGatewayDid:(NSString *)did withCompletion:(void(^)(NSError *))completion;

- (void)sendZigbeeAccessNetInfoCompletion:(void(^)(NSDictionary* dic,NSError *))completion;

-(LMAccessNetCategoryDevice*)getCategorydeviceWithPrdId:(NSInteger)pid;


- (void)setSsid:(NSString*)ssid pwd:(NSString*)pwd;


- (void)queryThreadNetCompletion:(void(^)(NSError* error,NSArray* datas))completion;

/// 设备查找指令
- (void)sendIdentifyToDevice:(LMMPBLEDevice*)device completion:(void(^)(NSError* error)) completion;

- (void)sendFactoryResetWithDid:(NSString*)did completion:(void(^)(NSError *error))completion;

- (void)removeHomeKitPairingWithDid:(NSString*)did completion:(void(^)(NSError *error))completion;

- (void)sendDeviceToStartHomekitWithDid:(NSString*)did completion:(void(^)(NSError *error))completion;

- (BOOL)discriminatorNotEqual:(LMMPQRCodeData*)manufactureModel;

#pragma mark - mdns
- (void)mdnsquerySupportedNetworkCompletion:(void (^)(NSError* error))completion;
/// Mdns发送bindkey
/// - Parameter completion: 结果回调
- (void)sendBindKeyByMdnsCompletion:(void(^)(NSInteger statusCode,NSError* error))completion;

/// Magic Pair 向设备请求homekit 或者 payload
/// @param completion bind为-1代表没有搜索到设备。
- (void)mdnsQueryHomekitOrMatterPayLoad:(BOOL)homeKit withDid:(NSString*)did completion:(void (^)(NSError* error,NSInteger bind, NSString* qrCode,NSString*digitalPairingCode))completion;

//- (void)startScanMdnsDeviceCompletion:(void(^)(NSArray<LMMPBLEDevice*>*devices,NSError* error))completion;

#pragma mark - 门锁流程
- (void)writeUserIdIfNeed:(void(^)(NSError* error))completion;

- (void)sendCodeCompletion:(void(^)(NSError* error))completion;

- (LMSmartBLEConnectMPData *)getBLEDataModel;

- (void)setBLEDataModel:(LMSmartBLEConnectMPData * _Nullable)dateModel;

#pragma mark 蓝牙和局域网权限

- (void)getWifiAndBleAuthority:(void(^)(BOOL bleEnable,BOOL wifiEnable,BOOL localNetWorkEnable))competion;

- (BOOL)getBleAuthority;

- (CBManagerState)getBleState;

- (void)getLocalNetWorkAuthority:(void(^)(BOOL enable))competion;

@end



@interface LMMPSmartBleConnect (InfoManager)

///查询当前设备信息
- (void)getDeviceInfo:(id)cellData completion:(void(^)(BOOL isSuccess))completion;

- (void)clearAllDeviceInfo;

@end

NS_ASSUME_NONNULL_END
