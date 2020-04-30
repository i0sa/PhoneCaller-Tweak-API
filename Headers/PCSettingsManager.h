//
//  PCHistoryManager.h
//  PhoneCaller3Xcode
//
//  Created by Osama on 3/28/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PCEngine.h"
#import "PCCaller.h"
#import "PCSettingItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PCSettingsManager : NSObject

+ (instancetype)sharedObject;
-(NSDictionary *)country;
-(BOOL)isIncomingCallsEnabled;
-(BOOL)isOutgoingCallsEnabled;

/*
Modern
BasicLight
BasicDark
CompactLight
CompactDark
*/
-(NSString *)style;
-(float)backgroundTransparent;
-(BOOL)showForContactsEnabled;
// returns number of seconds to display the Phonecaller's view, 0 means it will be displayed forever (or until user dismisses)
- (int)displayDuration;
- (BOOL)showInCallButton;
@end

NS_ASSUME_NONNULL_END
