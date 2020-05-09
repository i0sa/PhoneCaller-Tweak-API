//
//  PhoneCallerPopup.h
//  PhoneCallerApp
//
//  Created by Osama on 4/22/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface PhoneCallerPopup : NSObject<UIViewControllerTransitioningDelegate,  UIViewControllerAnimatedTransitioning>
+ (void)show:(UIViewController *)viewControllerToPresent on:(UIViewController *)parentViewController;
@end

NS_ASSUME_NONNULL_END
