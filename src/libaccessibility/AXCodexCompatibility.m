#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal Accessibility.framework ABI shims for Chromium/Electron.
 */

#define AX_COMPAT_EXPORT __attribute__((visibility("default")))

AX_COMPAT_EXPORT BOOL AXPrefersNonBlinkingTextInsertionIndicator(void) {
    return NO;
}

AX_COMPAT_EXPORT NSString * const AXPrefersNonBlinkingTextInsertionIndicatorDidChangeNotification =
    @"AXPrefersNonBlinkingTextInsertionIndicatorDidChangeNotification";

@interface AXCustomContent : NSObject {
    id _label;
    id _value;
    NSInteger _importance;
}
+ (instancetype)customContentWithLabel:(id)label value:(id)value;
- (instancetype)initWithLabel:(id)label value:(id)value;
- (id)label;
- (void)setLabel:(id)label;
- (id)value;
- (void)setValue:(id)value;
- (NSInteger)importance;
- (void)setImportance:(NSInteger)importance;
@end

@implementation AXCustomContent
+ (instancetype)customContentWithLabel:(id)label value:(id)value {
    return [[[self alloc] initWithLabel:label value:value] autorelease];
}
- (instancetype)initWithLabel:(id)label value:(id)value {
    self = [super init];
    if (self) {
        _label = [label copy];
        _value = [value retain];
        _importance = 0;
    }
    return self;
}
- (void)dealloc {
    [_label release];
    [_value release];
    [super dealloc];
}
- (id)label { return _label; }
- (void)setLabel:(id)label {
    if (_label != label) {
        [_label release];
        _label = [label copy];
    }
}
- (id)value { return _value; }
- (void)setValue:(id)value {
    if (_value != value) {
        [_value release];
        _value = [value retain];
    }
}
- (NSInteger)importance { return _importance; }
- (void)setImportance:(NSInteger)importance {
    _importance = importance;
}
@end
