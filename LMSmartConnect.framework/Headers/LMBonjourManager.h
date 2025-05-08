//
//  LHBonjourManager.h
//  AqaraHome
//
//  Created by 绿米 on 2020/9/24.
//  Copyright © 2020 Lumi United Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LHConnectStatus) {
    LHConnectStatusLocalSearching,      //本地查找mDNS
    LHConnectStatusAnalysisNetInfo,     //解析mDNS service
    LHConnectStatusCreatBindKey,        //创建bindKey
    LHConnectStatusSendBindKey,
    LHConnectStatusBindKeySended,     //bindkey通过socket发送成功
    LHConnectStatusConfirmInfo,       // socket消息发送完毕，准备查询bindkey
    LHConnectStatusQueryBindKey,
    LHConnectStatusConnectSuccess,
    LHConnectStatusConnectFail,
};

@class LHDevice, LMBonjourManager;

@protocol LMBonjourManagerDelegate <NSObject>

- (void)mdnsConnectStatus:(LHConnectStatus)connectStatus manager:(LMBonjourManager *)manager;

@end

@interface LMBonjourManager : NSObject

@property(nonatomic, strong)NSString *did;

@property(nonatomic)LHConnectStatus connectStatus;

@property(nonatomic)BOOL isBindHomekit; //是否已经绑定到HomeKit,在Home APP中绑定过

@property(nonatomic, strong)LHDevice *freshAddedDevice;

@property(nonatomic, weak)id<LMBonjourManagerDelegate> delegate;

/// 要绑定的IP和端口
@property(nonatomic, strong)NSString *mdnsIp;
@property(nonatomic)int mdnsport;

- (void)buildData;

/// 通过socket连接设备
- (void)connectSocketWithIPAdress:(int16_t)port;

- (void)sendNetworkInfoWithBindKey:(NSString *)bindKey;

- (void)queryBindkeyResultWithCompletion:(void (^)(NSString *bindKey, NSError *error))completion;

- (void)disconnect;

@end

