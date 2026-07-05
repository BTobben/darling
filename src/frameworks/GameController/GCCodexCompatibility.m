#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal loader-only GameController.framework ABI shims for Chromium/Electron.
 * Keep this file free of Objective-C message sends so the i386 slice does not
 * need lazy binding through dyld_stub_binder.
 */

#define GC_COMPAT_EXPORT __attribute__((visibility("default")))

GC_COMPAT_EXPORT NSString * const GCControllerDidConnectNotification =
    @"GCControllerDidConnectNotification";
GC_COMPAT_EXPORT NSString * const GCControllerDidDisconnectNotification =
    @"GCControllerDidDisconnectNotification";

GC_COMPAT_EXPORT NSString * const GCHapticsLocalityDefault =
    @"GCHapticsLocalityDefault";
GC_COMPAT_EXPORT NSString * const GCHapticsLocalityLeftHandle =
    @"GCHapticsLocalityLeftHandle";
GC_COMPAT_EXPORT NSString * const GCHapticsLocalityLeftTrigger =
    @"GCHapticsLocalityLeftTrigger";
GC_COMPAT_EXPORT NSString * const GCHapticsLocalityRightHandle =
    @"GCHapticsLocalityRightHandle";
GC_COMPAT_EXPORT NSString * const GCHapticsLocalityRightTrigger =
    @"GCHapticsLocalityRightTrigger";

GC_COMPAT_EXPORT double GCHapticDurationInfinite = 1.0e100;

@interface GCController : NSObject
+ (id)controllers;
+ (void)startWirelessControllerDiscoveryWithCompletionHandler:(id)completionHandler;
+ (void)stopWirelessControllerDiscovery;
- (id)vendorName;
- (NSInteger)playerIndex;
- (void)setPlayerIndex:(NSInteger)playerIndex;
- (id)gamepad;
- (id)extendedGamepad;
- (id)microGamepad;
- (id)motion;
@end

@implementation GCController
+ (id)controllers { return nil; }
+ (void)startWirelessControllerDiscoveryWithCompletionHandler:(id)completionHandler {}
+ (void)stopWirelessControllerDiscovery {}
- (id)vendorName { return nil; }
- (NSInteger)playerIndex { return -1; }
- (void)setPlayerIndex:(NSInteger)playerIndex {}
- (id)gamepad { return nil; }
- (id)extendedGamepad { return nil; }
- (id)microGamepad { return nil; }
- (id)motion { return nil; }
@end

@interface GCDualSenseGamepad : NSObject
@end
@implementation GCDualSenseGamepad
@end

@interface GCDualShockGamepad : NSObject
@end
@implementation GCDualShockGamepad
@end

@interface GCXboxGamepad : NSObject
@end
@implementation GCXboxGamepad
@end
