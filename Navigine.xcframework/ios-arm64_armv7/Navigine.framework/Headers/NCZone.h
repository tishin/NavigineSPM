//
//  NCZone.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 25/07/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NCLocationPoint;

NS_ASSUME_NONNULL_BEGIN

@interface NCZone : NSObject <NSCoding>

/**
 * Zone's Identifier
 */
@property (nonatomic, readonly) NSInteger id;

/**
 * Location Id to which the zone belongs
 */
@property (nonatomic, readonly) NSInteger location;

/**
 * Sublocation Id to which the zone belongs
 */
@property (nonatomic, readonly) NSInteger sublocation;

/**
 * Zone's name on map
 */
@property (nonatomic, readonly) NSString  *name;

/**
 * Zone's alias
 */
@property (nonatomic, readonly) NSString  *alias;

/**
 * Zone's color
 */
@property (nonatomic, readonly) NSString  *color;

/**
 * Zone's vertices
 */
@property (nonatomic, strong, readonly) NSArray<NCLocationPoint *> *points;

/**
 * Zone's geometric center
 */
@property (nonatomic, nullable, readonly) NCLocationPoint *center;

/**
 * Check that zone contains point
 *
 * @param point LocationPoint that you want to check for belonging to zone
 * @return YES if belongs, NO othetwise
 */
- (BOOL) containsPoint: (NCLocationPoint *) point;

/**
 * Zone validation
 *
 * @return YES if valid, NO othetwise
 */
- (BOOL) isValid;

/**
 Method for comparing zones.
 
 @param otherZone Compared zone
 @return YES if equals, NO othetwise
 */
- (BOOL)isEqualToZone: (NCZone *)otherZone;

@end

NS_ASSUME_NONNULL_END
