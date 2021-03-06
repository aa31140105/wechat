//
//  XMPPTool.h
//  weChat
//
//  Created by 天佑 on 16/3/28.
//  Copyright © 2016年 天佑. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Single.h"
#import "XMPPFramework.h"

typedef enum {
    XMPPResultTypeLoginSuccess,//登陆成功的枚举
    XMPPResultTypeLoginFailure,//登陆失败的枚举
    XMPPResultTypeResultSuccess,//注册成功的枚举
    XMPPResultTypeResultFailure//注册失败的枚举
    
}XMPPResultType;
/** 与服务器交互的block回调结果 */
typedef void (^XMPPResultBlock)(XMPPResultType);

@interface XMPPTool : NSObject
SingleH(XMPPTool)

/** 声明登陆方法 */
- (void)xmppLogin:(XMPPResultBlock  )resultBlock;

/** 声明退出方法 */
- (void)xmpplogout;

/** 声明注册方法 */
- (void)xmppRegister:(XMPPResultBlock)resultBlock;


/** 与服务器交互的核心类 */
@property (nonatomic, strong,readonly) XMPPStream *xmppStream;

/** 判断用户的操作是注册还是登陆,1是登陆,0是注册 */
@property(nonatomic,assign,getter=isLoginSuccess)BOOL loginSuccess;

/** 电子名片模块 */
@property (nonatomic, strong,readonly) XMPPvCardTempModule *vCard;

/** 电子头像模块 */
@property (nonatomic, strong,readonly) XMPPvCardAvatarModule *vavatar;

/** 电子名片数据 */
@property (nonatomic, strong,readonly) XMPPvCardCoreDataStorage *vCardStorage;

/** 花名册 */
@property (nonatomic, strong,readonly) XMPPRoster *roster;
/** 花名册数据 */
@property (nonatomic, strong,readonly) XMPPRosterCoreDataStorage *rosterStorage;

/** 消息模块 */
@property (nonatomic, strong) XMPPMessageArchiving *msgArchiving;
@property (nonatomic, strong) XMPPMessageArchivingCoreDataStorage *msgArchivingStorage;

@end