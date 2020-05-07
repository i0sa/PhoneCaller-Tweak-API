//
//  HsitoryViewController.h
//  PhoneCaller3Xcode
//
//  Created by Osama on 3/26/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PCSearchItem.h"
#import "PCEngine.h"
#import "PCCaller.h"

NS_ASSUME_NONNULL_BEGIN

@interface PCSearchItemVC :UIViewController

// to init with a SearchItem object received from PhoneCallerHelper
-(instancetype)initWithSearchItem:(PCSearchItem *)searchItem;

// to search directly with a phone number
-(instancetype)initWithSearchNumber:(NSString *)number;

@property (nonatomic, strong) PCSearchItem *item;
@end

NS_ASSUME_NONNULL_END
