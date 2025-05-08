//
//  LMAccessNetCategory.h
//  LMDeviceAccessNet
//
//  Created by MadHeart on 2021/3/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LMAccessNetCategory : NSObject

@property (nonatomic, copy)NSString *categoryId;

@property (nonatomic, copy)NSString *label;

@property (nonatomic, strong)NSArray <LMAccessNetCategory *> *children;

@end


@interface LMAccessNetCategoryDevice : NSObject

@property(nonatomic, strong)NSArray <LMAccessNetCategory *> *categories;

////子设备可以入网的网关列表
//@property(nonatomic, strong)NSArray *dependOnGateways;

@property(nonatomic, copy)NSString *deviceName;

@property(nonatomic, assign)NSInteger isHomekit;

//是否需要弹出窗口（比如：隐私协议） 1 = 需要
@property(nonatomic, assign)NSInteger isPopupTerm;

@property(nonatomic, strong)NSArray *terms;

@property(nonatomic, copy)NSString *model;

@property(nonatomic, assign)NSInteger ord;

@property(nonatomic, assign)NSInteger status;
//是否支持配置化入网 0 支持， 1 不支持
@property(nonatomic, assign)NSInteger isAlternative;

@property(nonatomic, copy)NSString *pid;

@property(nonatomic, copy)NSString *deviceIconPath;

// 设备是否支持当前App版本，为 1 表示不支持
@property (nonatomic, assign) NSInteger appNotMatch;

/// 设备安装码，由扫描包装二维码获得
@property(nonatomic, copy)NSString *installCode;

/// 设备X码
@property (nonatomic, copy) NSString *xcode;

@property (nonatomic, copy) NSString *matterPid;

@property (nonatomic, copy) NSString *accessMode;

- (BOOL)supportMatter;

@end

@interface LMAccessNetCategoryDevice (Matter)

/// Matter设备类型
@property (nonatomic, assign) NSInteger usageType;

/// 是否是Matter设备
@property (nonatomic, assign) BOOL isMatterDevice;

@end




@interface LMAccessNetCategoryDeviceGroup : NSObject

@property(nonatomic, copy)NSString *groupTitle;

@property(nonatomic, strong)NSMutableArray <LMAccessNetCategoryDevice *> *catrgoryDeviceList;

@property(nonatomic, assign)NSInteger categoryIndex;

@end


///该类用于子设备入网可选的网关列表
@interface LMAccessNetAddGatewayDevice : NSObject

@property(nonatomic, copy)NSString *model;

@property(nonatomic, copy)NSString *deviceName;

@property(nonatomic, copy)NSString *imgUrl;

@property(nonatomic, assign)BOOL isSelected;

@end

NS_ASSUME_NONNULL_END
