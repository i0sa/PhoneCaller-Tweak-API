//
//  PCImageManager.h
//  PhoneCallerApp
//
//  Created by Osama on 4/6/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PCImageManager : NSObject
+(UIImage *)imageNamed:(NSString *)name;
+(UIImage *)imageNamed:(NSString *)name withPath:(NSString *)path;
+ (void)setImageFromURL:(NSURL *)url imageView:(UIImageView *)imageView;

@end

NS_ASSUME_NONNULL_END
