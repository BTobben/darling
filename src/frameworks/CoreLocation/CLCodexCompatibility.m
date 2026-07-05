#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal loader-only CoreLocation.framework ABI shims for Chromium/Electron.
 */

#define CL_COMPAT_EXPORT __attribute__((visibility("default")))

CL_COMPAT_EXPORT double kCLLocationAccuracyBest = -1.0;
CL_COMPAT_EXPORT double kCLLocationAccuracyHundredMeters = 100.0;

@interface CLLocationManager : NSObject {
    id _delegate;
    double _desiredAccuracy;
    double _distanceFilter;
}
+ (BOOL)locationServicesEnabled;
+ (int)authorizationStatus;
+ (BOOL)headingAvailable;
+ (BOOL)significantLocationChangeMonitoringAvailable;
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass;

- (id)delegate;
- (void)setDelegate:(id)delegate;
- (double)desiredAccuracy;
- (void)setDesiredAccuracy:(double)accuracy;
- (double)distanceFilter;
- (void)setDistanceFilter:(double)filter;
- (int)authorizationStatus;
- (id)location;

- (void)requestWhenInUseAuthorization;
- (void)requestAlwaysAuthorization;
- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
- (void)startMonitoringSignificantLocationChanges;
- (void)stopMonitoringSignificantLocationChanges;
@end

@implementation CLLocationManager
+ (BOOL)locationServicesEnabled { return NO; }
+ (int)authorizationStatus { return 2; }
+ (BOOL)headingAvailable { return NO; }
+ (BOOL)significantLocationChangeMonitoringAvailable { return NO; }
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass { return NO; }

- (id)delegate { return _delegate; }
- (void)setDelegate:(id)delegate { _delegate = delegate; }
- (double)desiredAccuracy { return _desiredAccuracy; }
- (void)setDesiredAccuracy:(double)accuracy { _desiredAccuracy = accuracy; }
- (double)distanceFilter { return _distanceFilter; }
- (void)setDistanceFilter:(double)filter { _distanceFilter = filter; }
- (int)authorizationStatus { return 2; }
- (id)location { return nil; }

- (void)requestWhenInUseAuthorization {}
- (void)requestAlwaysAuthorization {}
- (void)startUpdatingLocation {}
- (void)stopUpdatingLocation {}
- (void)startMonitoringSignificantLocationChanges {}
- (void)stopMonitoringSignificantLocationChanges {}
@end
