//
//  EHOMESmartConfig.h
//  WhatieSDK
//
//  Created by Change on 2018/4/18.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "EHOMEBaseObject.h"

@interface EHOMESmartConfig : EHOMEBaseObject

/**
 instance
 
 @return self
 */
+(EHOMESmartConfig *)shareInstance;

-(void)smartConfigWithWifiPassword:(NSString *)wifiPassword
                          accessId:(NSString *)accessId
                         accessKey:(NSString *)accessKey
                        startBlock:(startBlock)startblock
                     progressBlock:(progressBlock)progressblock
                      successBlock:(successBlock)successblock
                         failBlock:(failBlock)failblock;



@end
