//
//  NCRoutePath.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 29/03/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NCRouteEvent, NCLocationPoint;

NS_ASSUME_NONNULL_BEGIN

@interface NCRoutePath : NSObject<NSCoding>

/**
 * Sequence of route events on the route path (see class NCRouteEvent)
 */
@property (nonatomic, readonly) NSArray<NCRouteEvent *> *events;

/**
 * Sequence of path points (see class NCLocationPoint)
 */
@property (nonatomic, readonly) NSArray<NCLocationPoint *> *points;

/**
 * Full path length (in meters)
 */
@property (nonatomic, readonly) float lenght;

- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
