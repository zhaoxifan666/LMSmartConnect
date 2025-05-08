//
//  LMMPWindowCellData.h
//  LMAccessNetSDK
//
//  Created by jeremy on 2023/5/24.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LMAccessNetCategory.h"

NS_ASSUME_NONNULL_BEGIN

@class LMAccessNetCategoryDevice;
@class LMMPQRCodeData;
@class LMMPBLEServiceDataModel;
@class LMMatterBLEServiceDataModel;

@interface LMMPBLEDevice : NSObject

@property(nonatomic, copy)NSString *name;

@property(nonatomic, copy)NSString *icon;

@property (nonatomic, strong) UIImage *matterDevicePlaceholderImage;

@property(nonatomic, assign)BOOL isMdns;

@property(nonatomic, strong)CBPeripheral *peripheral;

@property(nonatomic, strong)NSDictionary *advertisementData;

@property(nonatomic, strong)LMAccessNetCategoryDevice *categoryDevice;

@property(nonatomic, strong)NSMutableArray *rssiArray;
///信号强度
@property(nonatomic, strong)NSNumber *rssi;
///功率
@property(nonatomic, strong)NSNumber *db;

@property(nonatomic, assign)BOOL isNear;

///展示的设备，记录检测出距离很远的次数
@property(nonatomic, assign)NSInteger caculateTimes;

///上次搜索到的时间
@property(nonatomic, strong)NSDate* lastFoundTime;

/// 蓝牙或mdns广播model
@property(nonatomic, strong)LMMPQRCodeData *manufactureModel;

/// 多协议切换数据模型
@property (nonatomic, strong) LMMPBLEServiceDataModel *mpBLEServiceDataModel;

/// Matter数据模型
@property (nonatomic, strong) LMMatterBLEServiceDataModel *matterBLEServiceDataModel;

@property(nonatomic, strong)NSString *mp;


@property(nonatomic, strong)NSNetService *service;

@property(nonatomic, copy)NSString *ip;

@property(nonatomic, copy)NSString *port;

///网关did
@property(nonatomic, copy)NSString *did;

///模型值
@property(nonatomic, copy)NSString *modelId;

///当前是否绑定云平台
//@property(nonatomic, assign)BOOL bindToAiot;

///当前以太网是否连接
@property(nonatomic, assign)BOOL ethernetConnect;

///是否支持以太网
@property(nonatomic, assign)BOOL supportEthernet;

///以太网是否链接
@property(nonatomic, assign)BOOL ethernetIsReady;


/// used for deduplication
@property(nonatomic,copy)NSString *key;


- (instancetype)initWithPeripheral:(CBPeripheral*)peripheral advertisment:(NSDictionary*)advertisementData andRssi:(NSNumber*)rssi;

/// Matter/双协议切换的设备初始化
- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral
                          mpAdData:(NSDictionary *)mpAdData
                           andRssi:(NSNumber *)rssi;

- (instancetype)initWithService:(NSNetService *)service;

- (BOOL)isEqualToDevice:(LMMPBLEDevice*)device;

- (BOOL)isEqualOTADevice:(LMMPBLEDevice*)device;

- (void)updateRssi:(NSNumber*)rssi;

///根据rssi计算距离，如果是mdns设备返回0
- (CGFloat)calcDistByRSSI;

///是否绑定aqarhome
- (BOOL)isBindToAiot;

/// 是否连上网
//- (BOOL)isConnectToNet;

/// 是否是安全设备
- (BOOL)isPassCodeRequired;

- (void)resolutionGroup:(dispatch_group_t)group;

///从云端查询设备信息
- (void)fetchDeviceinfoCompletion:(void(^)(NSDictionary* obj))completion;

/// 是否是Matter设备
- (BOOL)isMatterDevice;

/// 是否是AqaraMatter设备
- (BOOL)isAqaraMatterDevice;

/// 是否是第三方Matter设备
- (BOOL)isThirdPartyMatterDevice;

/// 是否是多协议设备
- (BOOL)isMultipleProtocolsDevice;

/// 厂商Id
- (NSInteger)vendorId;

/// 产品Id
- (NSInteger)productId;

/// 鉴别码
- (NSInteger)discriminator;

@end


@interface LMMPWindowCellData : NSObject

@property(nonatomic, strong)NSString *title;

@property(nonatomic, strong)NSString *icon;

@property (nonatomic, strong) UIImage *matterDevicePlaceholderImage;

@property(nonatomic, assign)BOOL disable;

@property(nonatomic, strong)LMMPBLEDevice *device;

@end
 
NS_ASSUME_NONNULL_END
