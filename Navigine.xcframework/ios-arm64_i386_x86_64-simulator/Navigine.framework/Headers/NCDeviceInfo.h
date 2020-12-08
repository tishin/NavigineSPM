//
//  NCDeviceInfo.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 29/03/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCLocationPoint.h"

@class NCGlobalPoint, NCZone, NCRoutePath;

typedef NS_ENUM(NSUInteger, NCNavigationError) {
  NCIncorrectClient    = 1,
  NCNoSolution         = 4,
  NCNoBeacons          = 8,
  NCIncorrectBMP       = 10,
  NCIncorrectGP        = 20,
  NCIncorrectXMLParams = 21
};

NS_ASSUME_NONNULL_BEGIN

@interface NCDeviceInfo : NCLocationPoint

/**
 * Device UUID
 */
@property (nonatomic, copy, readonly, nonnull) NSString *id;

/**
 * Device measuring time (in milliseconds);
 */
@property (nonatomic, copy, readonly, nonnull) NSDate *time;

/**
 * Trusting radius of the current device position within the sub-location;
 */
@property (nonatomic, assign, readonly) float r;

/**
 * Device azimuth angle (in degrees)
 */
@property (nonatomic, assign, readonly) float azimuth;

/**
 * Device paths from the current position to the target points
 * or nil if target points are not defined (see NCRoutePath class)
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NCRoutePath *> *paths;

/**
 * Current list of sublocation zones where the device belongs
 * or nil if no such zones exists (see NCZone class)
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NCZone *> *zones;

/**
 * Navigation error or nil if navigation successful
 */
@property (nonatomic, copy, readonly, nullable) NSError *error;

/**
 @property coordinates
 Device's GPS coordinates
 */
@property (nonatomic, readonly, nullable) NCGlobalPoint *coordinates;

- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END

@interface NCDeviceInfo (NCDeprecated)

/**
 * Device latitude and longitude
 */
@property (nonatomic, assign, readonly) double latitude DEPRECATED_MSG_ATTRIBUTE("Use coordinates instead");
@property (nonatomic, assign, readonly) double longitude DEPRECATED_MSG_ATTRIBUTE("Use coordinates instead");

/**
 * X device position on map(relative coordinates)
 */
@property (nonatomic, assign, readonly) float kx DEPRECATED_ATTRIBUTE;

/**
 * Y device position on map(relative coordinates)
 */
@property (nonatomic, assign, readonly) float ky DEPRECATED_ATTRIBUTE;

@property (nonatomic, readonly, nullable) NCLocationPoint *locationPoint DEPRECATED_ATTRIBUTE;

@property (nonatomic, readonly, nullable) NCGlobalPoint *globalPoint DEPRECATED_MSG_ATTRIBUTE("Use coordinates instead");

@end
