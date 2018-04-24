//
//  EHOMEDeviceModel.h
//  WhatieSDK
//
//  Created by Change on 2018/4/16.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "EHOMEBaseObject.h"

@class Device;
@class Function;
@class FunctionValuesMap;
@class Product;
@class Version;
@class Picture;

@interface EHOMEDeviceModel : EHOMEBaseObject

@property (nonatomic, strong) Device *device;
@property (nonatomic, strong) NSArray <Function *> *functionList;
@property (nonatomic, strong) FunctionValuesMap *functionValuesMap;
@property (nonatomic, assign) int host;// = 1;



#pragma MARK - Functions About Device

/**
 GetMyDeviceList
 
 Get my devices if the userModel's isLogin is YES.
 The successblock returns the devices with <EHOMEDeviceModel *> array.
 */
+(void)getMyDeviceListWithAccessId:(NSString *)accessId
                         accessKey:(NSString *)accessKey
                        startBlock:(startBlock)startblock
                      successBlock:(successBlock)successblock
                         failBlock:(failBlock)failblock;

/**
 UpdateDeviceName
 
 Edit the Name of Device with one deviceModel as EHOMEDeviceModel.
 
 @param deviceModel : current deviceModel'name edting.
 @param name : new device name.
 */
+(void)updateDeviceNameWithDeviceModel:(EHOMEDeviceModel *)deviceModel
                                  name:(NSString *)name
                            startBlock:(startBlock)startblock
                          suucessBlock:(successBlock)successblock
                             failBlock:(failBlock)failblock;

/**
 UnBindDevice
 
 Unbind device.Also means delete device.User should reSet the device while use next.
 
 @param deviceModel : current unbinding deviceModel.
 */
+(void)unBindDeviceWithDeviceModel:(EHOMEDeviceModel *)deviceModel
                        startBlock:(startBlock)startblock
                      suucessBlock:(successBlock)successblock
                         failBlock:(failBlock)failblock;



/**
 SharedDevice
 
 Share Device to sharedUser from AdminUser.
 That means the device is belongs to AdminUser,it is shared to sharedUser.
 This FUNCTION is used by sharedUser.
 The AdminUser genetate the String include "adminUserId","deviceId","timestamp","accessId","accessKey",and so on.
 And the deviceId is the EHOMEDeviceModel.device.id
 
 @param adminUserId : adminUser'id
 @param sharedUserId : who the device shared to
 @param deviceId : EHOMEDeviceModel.device.id
 @param timestamp : timestamp unit to ms
 @param accessId : accessId
 @param accessKey : accessKey
 */
+(void)sharedDeviceWithAdminUserId:(int)adminUserId
                      sharedUserId:(int)sharedUserId
                          deviceId:(int)deviceId
                         timestamp:(long)timestamp
                          accessId:(NSString *)accessId
                         accessKey:(NSString *)accessKey
                        startBlock:(startBlock)startblock
                      suucessBlock:(successBlock)successblock
                         failBlock:(failBlock)failblock;


@end




@interface Device : EHOMEBaseObject

@property (nonatomic, assign) int actived;// = 1;
@property (nonatomic, copy) NSString *authKey;// = "<null>";
@property (nonatomic, assign) long long createTime;// = 1522225904000;
@property (nonatomic, assign) int deleted;// = 0;
@property (nonatomic, copy) NSString *devId;// = "0000000e_52_14_5";
@property (nonatomic, assign) long long firstActiveTime;// = 1522486103000;
@property (nonatomic, copy) NSString *hid;// = "dc:4f:22:28:af:79";
@property (nonatomic, assign) int id;// = 787;
@property (nonatomic, assign) long long lastOnlineTime;// = 1522630245000;
@property (nonatomic, assign) double lat;// = "<null>";
@property (nonatomic, assign) double lng;// = "<null>";
@property (nonatomic, copy) NSString *localKey;// = "<null>";
@property (nonatomic, copy) NSString *name;// = Hjjdlk;
@property (nonatomic, assign) int onlineTimes;// = 539;
@property (nonatomic, strong) Product *product;
@property (nonatomic, copy) NSString *secKey;// = "<null>";
@property (nonatomic, assign) int sellerId;// = 14;
@property (nonatomic, copy) NSString *status;// = "\U79bb\U7ebf";
@property (nonatomic, copy) NSString *token;// = "<null>";
@property (nonatomic, assign) long long updateTime;// = 1523522816000;
@property (nonatomic, assign) int uuid;// = 5;
@property (nonatomic, strong) Version *version;
@property (nonatomic, assign) int virtual;// = 0;


@end




@interface Function : EHOMEBaseObject

@property (nonatomic, assign) long long createTime;// = 1522225821000;
@property (nonatomic, assign) int deleted;// = 0;
@property (nonatomic, copy) NSString *funcType;// = "\U5e03\U5c14\U578b";
@property (nonatomic, assign) int id;// = 46;
@property (nonatomic, copy) NSString *name;// = "\U5f00\U51731";
@property (nonatomic, copy) NSString *nameEn;// = power;
@property (nonatomic, assign) int productId;// = 52;
@property (nonatomic, copy) NSString *remarks;// = "";
@property (nonatomic, copy) NSString *transType;// = "\U53ef\U4e0b\U53d1\U53ef\U4e0a\U62a5";
@property (nonatomic, assign) long long updateTime;// = 1522225821000;
@property (nonatomic, copy) NSString *value;// = "<null>";

@end




@interface FunctionValuesMap : EHOMEBaseObject

@property (nonatomic, assign) BOOL power;

@end




@interface Product : EHOMEBaseObject

@property (nonatomic, assign) int adminId;// = 14;
@property (nonatomic, copy) NSString *appId;// = "<null>";
@property (nonatomic, copy) NSString *brand;// = "<null>";
@property (nonatomic, copy) NSString *communicateType;// = WiFi;
@property (nonatomic, assign) int count;// = 73;
@property (nonatomic, assign) long long createTime;// = 1522226480000;
@property (nonatomic, assign) int deleted;// = 0;
//@property (nonatomic, copy) NSString *description;// = "<null>";
@property (nonatomic, assign) int id;// = 53;
@property (nonatomic, copy) NSString *name;// = WhatiePlug;
@property (nonatomic, strong) Picture *picture;
@property (nonatomic, strong) Picture *pictureThumb;
@property (nonatomic, copy) NSString *productKey;// = "53_14";
@property (nonatomic, assign) int productType;// = 3;
@property (nonatomic, copy) NSString *status;// = "\U5df2\U53d1\U5e03";
@property (nonatomic, assign) int sum;// = 10000;
@property (nonatomic, copy) NSString *topic;// = "0*3";
@property (nonatomic, assign) long long updateTime;// = "<null>";

@end




@interface Version : EHOMEBaseObject

@property (nonatomic, assign) long long createTime;// = 1522137915000;
@property (nonatomic, assign) int deleted;// = 0;
@property (nonatomic, strong) Picture *file;
@property (nonatomic, strong) Picture *fileRelated;
@property (nonatomic, assign) int id;// = 21;
@property (nonatomic, copy) NSString *remarks;// = "<null>";
@property (nonatomic, assign) int type;// = 50;
@property (nonatomic, copy) NSString *upgradeDoc;// = "<null>";
@property (nonatomic, assign) long long upgradeTime;// = "<null>";
@property (nonatomic, copy) NSString *upgradeType;// = "APP\U63d0\U9192\U5347\U7ea7";
@property (nonatomic, assign) int version;// = 1;

@end




@interface Picture : EHOMEBaseObject

@property (nonatomic, assign) long long createTime;// = 1522137915000;
@property (nonatomic, assign) int id;// = 145;
@property (nonatomic, copy) NSString *path;// = "https://files.d9lab.net/group1/M00/00/02/wKgA0lq8OX6AURfEAADFSQELCgo046.png";
@property (nonatomic, copy) NSString *type;// = "\U56fe\U7247";

@end




