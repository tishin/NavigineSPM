//
//  NavigineSDK.h
//  NavigineSDK
//
//  Created by Dmitry Stavitsky on 06/02/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class NCLocationPoint, NCRoutePath, NCRouteEvent;
@class NCDeviceInfo, NCVenue, NCZone, NCBeacon, NCGlobalPoint;
@class NCLocation, NCLocationInfo;

typedef NS_ENUM(NSInteger, NCError) {
  NCLocationDoesNotExist = 1000,
  NCDownloadImpossible   = 1010,
  NCUploadImpossible     = 1020,
  NCURLRequestImpossible = 1030,
  NCInvalidArchive       = 1040,
  NCInvalidClient        = 1050,
  NCInvalidBeacon        = 1060
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^locationListCompletionHandler)(NSError * _Nullable error,
                                              NSArray<NCLocationInfo *> * _Nullable locationInfo);

/**
 *  Protocol is used for getting navigation resutls in timeout
 */
@protocol NavigineCoreNavigationDelegate;

/**
 *  Protocol is used for getting pushes in timeout
 */
@protocol NavigineCoreDelegate;

/**
 *  Protocol is used for tracking location updates and AuthorizationStatus
 */
@protocol NavigineCoreLocationDelegate;

/**
 *  Protocol is used for tracking bluetooth status
 */
@protocol NavigineCoreBluetoothDelegate;

@interface NavigineCore : NSObject

/**
 @see NCLocation class
 */
@property (nonatomic, strong, readonly) NCLocation *location;

/**
 @see NCDeviceInfo class
 */
@property (nonatomic, strong, readonly) NCDeviceInfo *deviceInfo;

/**
 @property lastKnownLocation
 @brief Last global location coordinates received from CLLocationManager
 */
@property (nonatomic, strong, nullable, readonly) NCGlobalPoint *lastKnownLocation;

/**
 @property userHash
 @brief User security key
 */
@property (nonatomic, copy, readonly) NSString *userHash;

/**
 @property server
 @brief Server URL (in the format http[s]://host[:port], e.g. "https://api.navigine.com")
 */
@property (nonatomic, copy, readonly) NSString *server;

@property (nonatomic, readonly, nullable) NSArray<NCLocationInfo *> *locationList;

@property (nonatomic, weak, nullable) id<NavigineCoreNavigationDelegate> navigationDelegate;

@property (nonatomic, weak, nullable) id<NavigineCoreBluetoothDelegate> bluetoothDelegate;

@property (nonatomic, weak, nullable) id<NavigineCoreLocationDelegate> locationDelegate;

@property (nonatomic, weak, nullable) id<NavigineCoreDelegate> delegate;

- (instancetype) initWithUserHash:(NSString *)userHash;

- (instancetype) initWithUserHash:(NSString *)userHash
                           server:(NSString *)server NS_DESIGNATED_INITIALIZER;

/**
 *  Function is used for downloading location and start navigation
 *
 *  @param locationId Location name from web site.
 If set, the content data would be loaded even if the same version has been downloaded already earlier.
 If flag is not set, the download process compares the current downloaded version with the last version on the server.
 If server version equals to the current downloaded version, the re-downloading is not done.
 *  @param processBlock show downloading process
 *  @param successBlock run when download complete successfull
 *  @param failBlock    show error message and stop downloading
 */
- (void) downloadLocationById :(NSInteger)locationId
                 processBlock :(void(^)(NSInteger loadProcess))processBlock
                 successBlock :(void(^)(NSDictionary *userInfo))successBlock
                    failBlock :(void(^)(NSError *error))failBlock;

- (void) downloadLocationByName :(NSString *)location
                   processBlock :(void(^)(NSInteger loadProcess))processBlock
                   successBlock :(void(^)(NSDictionary *userInfo))successBlock
                      failBlock :(void(^)(NSError *error))failBlock;

/**
 *  Function is used for downloading location and start navigation
 *
 *  @param locationId Location name from web site.
 *  @param forced The boolean flag.
 If set, the content data would be loaded even if the same version has been downloaded already earlier.
 If flag is not set, the download process compares the current downloaded version with the last version on the server.
 If server version equals to the current downloaded version, the re-downloading is not done.
 *  @param processBlock show downloading process
 *  @param successBlock run when download complete successfull
 *  @param failBlock    show error message and stop downloading
 */
- (void) downloadLocationById :(NSInteger)locationId
                  forceReload :(BOOL) forced
                 processBlock :(void(^)(NSInteger loadProcess))processBlock
                 successBlock :(void(^)(NSDictionary *userInfo))successBlock
                    failBlock :(void(^)(NSError *error))failBlock DEPRECATED_MSG_ATTRIBUTE("Deprecated method. Use -startLocationLoaderBylocationName: locationName instead.");

- (void) downloadLocationByName :(NSString *)location
                    forceReload :(BOOL) forced
                   processBlock :(void(^)(NSInteger loadProcess))processBlock
                   successBlock :(void(^)(NSDictionary *userInfo))successBlock
                      failBlock :(void(^)(NSError *error))failBlock DEPRECATED_MSG_ATTRIBUTE("Deprecated method. Use -startLocationLoaderBylocationName: locationName instead.");

/**
 @brief The function is used to get a list of locations that are available for this user
 @discussion To get a list of locations you can use property (@see locationList)
*/
- (void) downloadLocationListWithCompletionHandler : (nullable locationListCompletionHandler) completionHandler;

/**
 @brief Function is used for starting Navigine service.
 */
- (void) startNavigine;

/**
 @brief Function is used for forced termination of Navigine service.
 */
- (void) stopNavigine;

/**
 *  Function is used for creating a content download process from the server.
 Download is done in a separate thread in the non-blocking mode.
 Function startLocationLoader doesn't wait until download is finished and returns immediately.
 *
 *  @param locationId location name from web site.
 *
 *  @return the download process identifier. This number is used further for checking the download process state and for download process terminating.
 */

- (NSInteger)startLocationLoaderByLocationId: (NSInteger)locationId;

- (NSInteger)startLocationLoaderByLocationName: (NSString *)locationName;

/**
 *  Function is used for checking the download process state and progress.
 *
 *  @param loaderId download process identifier.
 *
 *  @return Integer number — the download process state:
 •  values in interval [0, 99] mean that download is in progress.
 In that case the value shows the download progress percentage;
 •  value 100 means that download has been successfully finished;
 •  other values mean that download process is impossible for some reason.
 */
- (NSInteger) checkLocationLoader :(NSInteger)loaderId;

/**
 *  Function is used for forced termination of download process which has been started earlier.
 Function should be called when download process is finished (successfully or not) or by a timeout.
 *
 *  @param loaderId download process identifier.
 */
- (void) stopLocationLoader :(NSInteger)loaderId;

/**
 *  Function is used for load location from downloaded archive.
 *
 *  @param locationId Location name from web site.
 *  @param error Error if archive invalid.
 */
- (BOOL) loadLocationById:(NSInteger)locationId
                    error:(NSError * _Nullable __autoreleasing *)error;

- (BOOL) loadLocationByName:(NSString *)location
                      error:(NSError * _Nullable __autoreleasing *)error;

- (void) cancelLocation;

/**
 *  Function is used for sending custom user events to server.
 *
 *  @param content Event content.
 *  @return event tag.
*/
- (NSString *) publishUserEvent:(NSString *)content;

/**
 *  Function is used for sending data to server using POST sequests
 */
- (void) startSendingPostRequests;

/**
 * Function is used to stop sending data to server
 */
- (void) stopSendingPostRequests;

- (void) addBeaconGenerator: (NSString *)uuid
                      major: (NSInteger)major
                      minor: (NSInteger)minor
                    timeout: (NSInteger)timeout
                    rssiMin: (NSInteger)rssiMin
                    rssiMax: (NSInteger)rssiMax;

- (void) removeBeaconGenerator: (NSString *)uuid
                         major: (NSInteger)major
                         minor: (NSInteger)minor;

- (void) removeBeaconGenerators;

/**
 @brief Function is used for building routes between the two location points,
 specified in the parameters.
 
 @discussion Route is a polyline represented as an array of location points.
 Location points can belong to different sublocations. For example, this function
 can be used for building the optimal route from the current device position to
 the specified position in the location.
 
 @param startPoint A source LocationPoint
 @param endPoint A destination LocationPoint
 @return If route is successfully build, function returns the RoutePath,
 starting from the source point, ending in the destination point.
 If route can't be build function returns nil.
 */
- (NCRoutePath *) makeRouteFrom: (NCLocationPoint *)startPoint
                             to: (NCLocationPoint *)endPoint;

- (NCRoutePath *) makeRouteFrom: (NCLocationPoint *)startPoint
                             to: (NCLocationPoint *)endPoint
                        options: (nullable NSDictionary *)options;

/**
 @brief Function is used for setting up a target point for the device.
 @discussion If a target point is set up, NavigineCore will automatically
 build route to that point as soon as new device coordinates are be determined.
 The route will be stored in a path parameter in the DeviceInfo(@see NCDeviceInfo) class.
 
 @param target Target LocationPoint.
 */
- (void) setTarget:(NCLocationPoint *)target;

/**
 @brief Functions are used for canceling all target points for the device, which have been set up earlier.
 */
- (void) cancelTarget;
- (void) cancelTargets;

/**
 @brief Function is used for specifying the graph on which routing is performed.
 
 @param tag Tag name of the specified routing graph.
 */
- (void) setGraphTag:(NSString *)tag;

/**
 @brief Function is used for determine the current routing graph.
 
 @return The tag name of the currently used routing graph. If the location is not loaded,
 function returns nil.
 */
- (nullable NSString *)getGraphTag;

/**
 @brief Function is used for determine the description of the specified routing graph.
 
 @param tag Tag name of the specified routing graph.
 @return Description of the specified routing graph or nil
 if there is no routing graph with the specified tag.
 If the location is not loaded, function returns nil.
 */
- (nullable NSString *)getGraphDescription:(NSString *)tag;

- (nullable NSArray<NCLocationPoint *> *)getExternalPoints:(NSString *)tag;

/**
 @brief Function is used for determine the list of available routing graphs.
 
 @return Function returns a list of tags corresponding to the available routing graphs.
 If the location is not loaded, function returns nil.
 */
- (nullable NSArray *)getGraphTags;

/**
 @brief Function is used for adding a new target point for the device.
 NavigineSDK will automatically build routes to all target points which were added.
 Routes will be stored in a path parameter in the DeviceInfo(@see NCDeviceInfo) class.
 
 @param target Target LocationPoint.
 */
- (void) addTarget:(NCLocationPoint *)target;

@end

@protocol NavigineCoreNavigationDelegate <NSObject>
@optional
/**
 * Tells the delegate if navigation results changed
 */
- (void) navigineCore:(NavigineCore *)navigineCore didUpdateDeviceInfo:(NCDeviceInfo *)deviceInfo;

/**
 * Tells the delegate if point enter the zone
 *
 * @param zone - entered zone
 */
- (void) navigineCore:(NavigineCore *)navigineCore didEnterZone:(NCZone *)zone;

/**
 * Tells the delegate if point came out of the zone
 *
 * @param zone - exit zone
 */
- (void) navigineCore:(NavigineCore *)navigineCore didExitZone:(NCZone *)zone;

@end

@protocol NavigineCoreDelegate <NSObject>
@optional

/**
 *  Tells the delegate that push in range. Function is called by the timeout of the web site.
 *
 *  @param title   title of push.
 *  @param content content of push.
 *  @param image   url path to image of push.
 *  @param id      push id.
 */
- (void) didRangePushWithTitle :(NSString *)title
                       content :(NSString *)content
                         image :(NSString *)image
                            id :(NSInteger) id;

- (void) didRangeBeacons: (NSArray *)beacons;

- (void) beaconFounded: (NCBeacon *)beacon error:(NSError **)error;

- (void) measuringBeaconWithProcess: (NSInteger) process;

@end

@protocol NavigineCoreLocationDelegate <NSObject>

@optional

- (void)navigineCore: (NavigineCore *)navigineCore didUpdateLocations:(NSArray<CLLocation *> *)locations;

- (void)navigineCore: (NavigineCore *)navigineCore didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

- (void)navigineCore: (NavigineCore *)navigineCore didFailWithError:(NSError *)error;

@end

@protocol NavigineCoreBluetoothDelegate <NSObject>

- (void)navigineCore: (NavigineCore *)navigineCore didUpdateBluetoothState:(CBManagerState)status;

@end

NS_ASSUME_NONNULL_END
