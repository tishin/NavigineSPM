//
//  NCGlobalPoint.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 26/10/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NCGlobalPoint : NSObject <NSCoding, NSSecureCoding, NSCopying>

@property (nonatomic, readonly) double latitude;
@property (nonatomic, readonly) double longitude;

- (double) distanceTo: (NCGlobalPoint *) point;

+ (instancetype) pointWithLatitude:(double) latitude
                         longitude:(double) longitude;

- (instancetype) initWithLatitude:(double) latitude
                        longitude:(double) longitude NS_DESIGNATED_INITIALIZER;

- (instancetype) initWithCoder: (NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
