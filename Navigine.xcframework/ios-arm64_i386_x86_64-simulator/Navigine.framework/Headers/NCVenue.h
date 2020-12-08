//
//  NCVenue.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 17/06/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCLocationPoint.h"

@class NCCategory, UIImage;

@interface NCVenue : NCLocationPoint

/**
 * Identifier of venue
 */
@property(nonatomic, assign, readonly) NSInteger id;

/**
 * Venue's name
 */
@property(nonatomic, copy, readonly) NSString *name;

/**
 * Venue's phone number
 */
@property(nonatomic, copy, readonly) NSString *phone;

/**
 * Other information about venue
 */
@property(nonatomic, copy, readonly) NSString *descript;

/**
 * Venue's alias
 */
@property(nonatomic, copy, readonly) NSString *alias;

/**
 * Venue's category(caffe, point of interest, etc...)
 */
@property(nonatomic, copy, readonly) NCCategory *category;

/**
 * Venue's image
 */
@property(nonatomic, strong, readonly) UIImage *image;

/**
 * Method for venue validation
 *
 * @return YES if valid, NO othetwise
 */
- (BOOL) isValid;

/**
 Method for comparing venues.
 
 @param otherVenue Compared Venue
 @return YES if equals, NO othetwise
 */
- (BOOL)isEqualToVenue: (NCVenue *)otherVenue;

@end
