#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal loader-only CoreHaptics.framework ABI shims for Chromium/Electron.
 */

#define CH_COMPAT_EXPORT __attribute__((visibility("default")))

CH_COMPAT_EXPORT NSString * const CHHapticDynamicParameterIDHapticIntensityControl =
    @"CHHapticDynamicParameterIDHapticIntensityControl";
CH_COMPAT_EXPORT NSString * const CHHapticDynamicParameterIDHapticSharpnessControl =
    @"CHHapticDynamicParameterIDHapticSharpnessControl";

CH_COMPAT_EXPORT NSString * const CHHapticEventParameterIDHapticIntensity =
    @"CHHapticEventParameterIDHapticIntensity";
CH_COMPAT_EXPORT NSString * const CHHapticEventParameterIDHapticSharpness =
    @"CHHapticEventParameterIDHapticSharpness";

CH_COMPAT_EXPORT NSString * const CHHapticEventTypeHapticContinuous =
    @"CHHapticEventTypeHapticContinuous";

@interface CHHapticDynamicParameter : NSObject
- (id)initWithParameterID:(id)parameterID value:(float)value relativeTime:(double)time;
@end

@implementation CHHapticDynamicParameter
- (id)initWithParameterID:(id)parameterID value:(float)value relativeTime:(double)time {
    return self;
}
@end

@interface CHHapticEvent : NSObject
- (id)initWithEventType:(id)type parameters:(id)parameters relativeTime:(double)time;
- (id)initWithEventType:(id)type parameters:(id)parameters relativeTime:(double)time duration:(double)duration;
@end

@implementation CHHapticEvent
- (id)initWithEventType:(id)type parameters:(id)parameters relativeTime:(double)time {
    return self;
}
- (id)initWithEventType:(id)type parameters:(id)parameters relativeTime:(double)time duration:(double)duration {
    return self;
}
@end

@interface CHHapticEventParameter : NSObject
- (id)initWithParameterID:(id)parameterID value:(float)value;
@end

@implementation CHHapticEventParameter
- (id)initWithParameterID:(id)parameterID value:(float)value {
    return self;
}
@end

@interface CHHapticPattern : NSObject
- (id)initWithEvents:(id)events parameters:(id)parameters error:(id *)error;
- (id)initWithDictionary:(id)dictionary error:(id *)error;
- (id)exportDictionaryAndReturnError:(id *)error;
@end

@implementation CHHapticPattern
- (id)initWithEvents:(id)events parameters:(id)parameters error:(id *)error {
    if (error) *error = nil;
    return self;
}
- (id)initWithDictionary:(id)dictionary error:(id *)error {
    if (error) *error = nil;
    return self;
}
- (id)exportDictionaryAndReturnError:(id *)error {
    if (error) *error = nil;
    return nil;
}
@end
