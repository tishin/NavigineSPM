//
//  NCLocation.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 11/03/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NCSublocation, NCZone, NCLocationlPoint;

NS_ASSUME_NONNULL_BEGIN

@interface NCLocation : NSObject<NSCoding>

/**
 *  Location id in personal account
 */
@property (nonatomic, readonly) NSInteger id;

/**
 *  Location name in personal account
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 *  Location description in personal account 
 */
@property (nonatomic, copy, readonly) NSString *localDescription;

/**
 *  Location version
 */
@property (nonatomic, readonly) NSInteger version;

/**
 *  Array with sublocations of your location
 */
@property (nonatomic, strong, readonly) NSArray<NCSublocation *> *sublocations;

/**
 *  Is local modified Archive
 */
@property (nonatomic, readonly) BOOL modified;

/**
 *  Function is used for getting sublocation at id or nil error
 *
 *  @param sublocationId of sublocation
 *
 *  @return Sublocation object or nil
 */
- (NCSublocation *_Nullable) subLocationWithId: (NSInteger) sublocationId;

- (NCZone *_Nullable) zoneWithId: (NSInteger) zoneId;

- (NSArray<NCZone *> *) zonesContainingPoint: (NCLocationlPoint *) point;

- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END

