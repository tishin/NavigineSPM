//
//  NCLocationInfo.h
//  NavigineSDK
//
//  Created by Dmitry Stavitsky on 11/11/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NCLocationInfo : NSObject

@property(nonatomic, assign, readonly) NSInteger identifier;

@property(nonatomic, copy, readonly) NSString *title;

@property(nonatomic, copy, readonly) NSString *descript;

@property(nonatomic, assign, readonly) NSInteger version;

- (instancetype)initWithIdentifier: (NSInteger) identifier
                             title: (NSString *) title
                       description: (NSString *) description
                           version: (NSInteger) version;

- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
