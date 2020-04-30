//
//  PhoneCallerHelper.h
//  
//
//  Created by Osama on 4/30/20.
//  Copyright © 2020 Osama Gamal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PCCaller.h"
#import "PCEngine.h"
#import "PCSearchItem.h"

@interface PhoneCallerHelper : NSObject

typedef void(^postRequestBlock)(PCCaller *details);
typedef void(^searchingBlock)(PCEngine *engine);
typedef void(^searchCompleteBlock)(PCEngine *engine);
typedef void(^searchItemBlock)(PCSearchItem *searchItem);


@property (nonatomic, copy) postRequestBlock completed;
@property (nonatomic, copy) searchingBlock searching;
@property (nonatomic, copy) searchItemBlock searchItem;
@property (nonatomic, copy) searchCompleteBlock searchComplete;


//MARK: Normal Search With Mobile
-(void)searchForNumber:(NSString *)number
             completed:(postRequestBlock)completed
             searching:(searchingBlock)searching
            searchItem:(searchItemBlock)searchItem
        searchComplete:(searchCompleteBlock)searchComplete;

@end


