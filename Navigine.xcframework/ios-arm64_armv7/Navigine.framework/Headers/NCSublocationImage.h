//
//  NCSublocationImage.h
//  NavigineSDK
//
//  Created by Dmitry Stavitsky on 12/03/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIImage;

typedef NS_ENUM(NSUInteger, NCImageType) {
  NCPNGImageType,
  NCJPGImageType,
  NCSVGImageType,
  NCUnknownImageType
};

@interface NCSublocationImage : NSObject<NSCoding>

- (nullable instancetype) initWithImageData:(NSData *_Nonnull) imageData
                               andImageType:(NCImageType) imageType;

/**
 Returns nil if the image is not supported or corrupted.
 */
@property(nullable, nonatomic, strong, readonly) NSData *imageData;

/**
 Returns type of image(@see NCImageType)
 */
@property(nonatomic, assign, readonly) NCImageType imageType;

/**
 Returns underlying UIImage or nil if image is not supported or corrupted.
 */
@property(nullable, nonatomic, strong, readonly) UIImage *image;

@end
