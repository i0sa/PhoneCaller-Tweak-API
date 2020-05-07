//
//  searchItem.h
//  PhoneCaller3Xcode
//
//  Created by Osama on 3/28/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PCCaller.h"

NS_ASSUME_NONNULL_BEGIN

@interface PCSearchItem : NSObject
@property (nonatomic, strong) NSString *searchData;
// all results dictionary
@property (nonatomic, strong) NSMutableDictionary *enginesData;
@property (nonatomic, strong) NSString *date;

-(PCCaller *)getFirstCaller;

@end

NS_ASSUME_NONNULL_END
