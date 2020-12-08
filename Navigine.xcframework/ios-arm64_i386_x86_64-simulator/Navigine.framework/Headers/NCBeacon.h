//
//  NCBeacon.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 01/03/16.
//  Copyright © 2016 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCLocationPoint.h"

typedef NS_ENUM(NSUInteger, NCBeaconStatus) {
  NCBeaconOld = 0,
  NCBeaconNew,
  NCBeaconMod,
  NCBeaconDel
};

NS_ASSUME_NONNULL_BEGIN

@interface NCBeacon : NCLocationPoint

/**
 * Beacon's identifier
 */
@property (nonatomic, readonly) NSInteger id;

/**
 * Beacon's major and minor
 */
@property (nonatomic, readonly) NSInteger major;
@property (nonatomic, readonly) NSInteger minor;

/**
 * Beacon's UUID
 */
@property (nonatomic, copy, readonly) NSString *uuid;

/**
 * Beacon's name on map
 */
@property (nonatomic, copy, readonly) NSString *name;

@property (nonatomic, readonly) NCBeaconStatus status;

/**
 * Method for beacon validation
 *
 * @return YES if valid, NO othetwise
 */
- (BOOL) isValid;

/**
 Method for comparing beacons.

 @param otherBeacon Compared beacon
 @return YES if equals, NO othetwise
 */
- (BOOL) isEqualToBeacon: (NCBeacon *)otherBeacon;

@end

NS_ASSUME_NONNULL_END
