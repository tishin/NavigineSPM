//
//  NCRouteEvent.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 27/07/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NCRouteEventType) {
  NCRouteEventTypeUndefined = 0,
  NCRouteEventTypeTurnLeft,
  NCRouteEventTypeTurnRight,
  NCRouteEventTypeTransition
};

@interface NCRouteEvent : NSObject <NSCoding>

/**
 * Distance from the beginning of the path to the current route event (in meters)
 */
@property (nonatomic, readonly) float distance;

/**
 * Event type. (Turn left, Turn right or sublocation change);
 */
@property (nonatomic, readonly) NCRouteEventType type;

/**
 * Rotation angle(in degrees)
 */
@property (nonatomic, readonly) int value;

- (BOOL) isValid;

@end
