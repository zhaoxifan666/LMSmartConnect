//
//  LMAccessNetConfiguration.h
//  LMSmartConnect
//
//  Created by 赵希帆 on 2025/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 商业SDK入网信息配置
@interface LMAccessNetConfiguration : NSObject

/// 是否为商业SDK
@property (nonatomic, assign, readonly) BOOL isExternalSDK;
/// 家庭ID获取
@property (nonatomic, strong, readonly) NSString *homeId;
/// 家庭名称获取
@property (nonatomic, strong, readonly) NSString *homeName;
/// 房间ID获取
@property (nonatomic, strong, readonly) NSString *roomId;
/// 房间名称获取
@property (nonatomic, strong, readonly) NSString *roomName;
/// 当前地区信息
@property (nonatomic, strong, readonly) NSDictionary *countryDic;
/// 是否为主家庭
@property (nonatomic, assign, readonly) BOOL isAdmin;
/// App Group
@property (nonatomic, strong, readonly) NSString *appGroupKey;

/// 单例调用属性
+ (instancetype)sharedInstance;

/// 设置家ID （设置了说明是对外SDK）
/// - Parameter homeId: 家ID
+ (void)saveHomeId:(NSString *)homeId;

/// 设置家庭名称（Matter使用）
/// - Parameter homeName: 家庭名称
+ (void)saveHomeName:(NSString *)homeName;

/// 设置房间ID （Matter使用）
/// - Parameter roomId: 房间ID
+ (void)saveRoomId:(NSString *)roomId;

/// 设置房间名称 （Matter使用）
/// - Parameter roomName: 房间名称
+ (void)saveRoomName:(NSString *)roomName;

/// 设置是否是主家庭（默认YES，NO表示当前设置家庭为分享家庭）
/// - Parameter isAdmin: 是否主家庭
+ (void)saveIsAdminHome:(BOOL)isAdmin;

/// 设置宿主工程使用的App Group，用于和Matter拓展共享数据
/// MatterExtension里的RequestHandler文件的appGroupKey需要跟这里传的值一致
/// - Parameter appGroupKey: App Group Key
+ (void)saveAppGroupKey:(NSString *)appGroupKey;

@end

NS_ASSUME_NONNULL_END
