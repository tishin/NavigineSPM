//
//  NCCategory.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 03/10/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NCCategory : NSObject <NSCoding, NSCopying>

/**
 * Category's identifier
 */
@property (nonatomic, readonly) NSInteger id;

/**
 * Category's name
 */
@property (nonatomic, copy, readonly) NSString * name;

/**
 * Method for category validation
 *
 * @return YES if valid, NO othetwise
 */
- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
