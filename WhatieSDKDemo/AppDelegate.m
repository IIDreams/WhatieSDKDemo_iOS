//
//  AppDelegate.m
//  WhatieSDKDemo
//
//  Created by Change on 2018/4/13.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "AppDelegate.h"
#import <IQKeyboardManager/IQKeyboardManager.h>
#import "ViewController.h"
#import "EHOMETabBarController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    IQKeyboardManager *keyboardManager = [IQKeyboardManager sharedManager];
    keyboardManager.enable = YES;
    keyboardManager.shouldResignOnTouchOutside = YES;
    
    

//    NSString * appId = @"Your AccessId";
//    NSString * secretKey = @"Your AccessKey";
    
    NSString * appId;
    NSString * secretKey;
    
    switch (CurrentApp) {
        case eHome:{

            appId = @"4601134601";
            secretKey = @"c5cb80b69c5af7e41baded615391bbc0";
        }
            break;

            
        default:{
            appId = @"4601134601";
            secretKey = @"c5cb80b69c5af7e41baded615391bbc0";
        }
            break;
    }
    



    
    //Init WhatieSDK
    [[EHOMESDK shareInstance] startWithAppId:appId secretKey:secretKey];

    
    if ([EHOMEUserModel isLogin]) {
        //login
        EHOMETabBarController *tabBarController = [[EHOMETabBarController alloc] initWithNibName:@"EHOMETabBarController" bundle:nil];
        
        self.window.rootViewController = tabBarController;
    }else{
        UIStoryboard *mainSB = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        ViewController *loginVC = [mainSB instantiateViewControllerWithIdentifier:@"LoginVC"];
        self.window.rootViewController = loginVC;
    }

    
    [self.window makeKeyAndVisible];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    
    [EHOMEDataStore setDevicesToDBWithDevices:[EHOMEUserModel shareInstance].deviceArray];
}


@end
