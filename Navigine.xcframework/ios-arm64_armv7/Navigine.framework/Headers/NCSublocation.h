//
//  NCSublocation.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 27/04/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

@class NCZone, NCBeacon, NCVenue, NCLocationPoint, NCGlobalPoint, NCSublocationImage, UIImage;

NS_ASSUME_NONNULL_BEGIN

@interface NCSublocation : NSObject <NSCoding, NSCopying>

/**
 * Sublocation id in personal account
 */
@property (nonatomic, readonly) NSInteger id;

/**
 * Location id in personal account
 */
@property (nonatomic, readonly) NSInteger location;

/**
 *  Location name in personal account
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 *  Azimuth of image in degree
 */
@property (nonatomic, readonly) float azimuth;

/**
 *  Zones which sublocation contains
 */
@property (nonatomic, strong, readonly) NSArray<NCZone *> *zones;

/**
 *  Venues which sublocation contains
 */
@property (nonatomic, strong, readonly) NSArray<NCVenue *> *venues;

/**
 *  Beacons which sublocation contains
 */
@property (nonatomic, strong, readonly) NSArray<NCBeacon *> *beacons;

@property (nonatomic, strong, readonly) NCSublocationImage *sublocationImage;

/**
 @property dimensions
 Consists of sublocation width and sublocation height
 */
@property (nonatomic, assign, readonly) CGSize dimensions;

/**
 @property coordinates
 Sublocation's GPS coordinates
 */
@property (nonatomic, readonly, nullable) NCGlobalPoint *coordinates;

/**
 *  Function is used for getting zone at id
 *
 *  @param zoneId - Identifier of zone
 *  @return Zone object or nil
 */
- (NCZone *_Nullable) zoneWithId: (NSInteger) zoneId;

/**
 *  Validate sublocation
 */
- (BOOL) isValid;

/**
 * Convert GPS coordinates to local coordinates
 *
 * @param point LocationPoint that you want to convert
 */
- (NCGlobalPoint *) gpsFromLocal: (NCLocationPoint *) point;

/**
 * Convert local coordinates to GPS coordinates
 *
 * @param point GlobalPoint that you want to convert
 */
- (NCLocationPoint *) localFromGps: (NCGlobalPoint *) point;

@end

@interface NCSublocation (NCDeprecated)

/**
 *  Name of svg image or nil if svg image not exists
 */
@property (nonatomic, copy, readonly) NSString *svgFile DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Name of png image or nil if png image not exists
 */
@property (nonatomic, copy, readonly) NSString *pngFile DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Name of jpg image or nil if jpg image not exists
 */
@property (nonatomic, copy, readonly) NSString *jpgFile DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Data of svg image or nil if svg image not exists
 */
@property (nonatomic, readonly) NSData *svgImage DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Data of png image or nil if png image not exists
 */
@property (nonatomic, readonly) NSData *pngImage DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Data of jpg image or nil if jpg image not exists
 */
@property (nonatomic, readonly) NSData *jpgImage DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  UImage of map or nil if image invalid
 */
@property (nonatomic, strong, readonly, nullable) UIImage *image DEPRECATED_MSG_ATTRIBUTE("Use sublocationImage instead");

/**
 *  Width of image in meters
 */
@property (nonatomic, readonly) float width DEPRECATED_MSG_ATTRIBUTE("Use dimensions instead");

/**
 *  Height of image in meters
 */
@property (nonatomic, readonly) float height DEPRECATED_MSG_ATTRIBUTE("Use dimensions instead");

/**
 *  GPS latitude
 */
@property (nonatomic, readonly) double latitude DEPRECATED_MSG_ATTRIBUTE("Use coordinates instead");

/**
 *  GPS longitude
 */
@property (nonatomic, readonly) double longitude DEPRECATED_MSG_ATTRIBUTE("Use coordinates instead");

@end

NS_ASSUME_NONNULL_END

