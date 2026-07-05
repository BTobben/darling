#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible SafariServices shims for Chromium/Electron.
 */

@interface SFUniversalLink : NSObject {
    NSURL *_url;
}
- (instancetype)initWithURL:(NSURL *)url;
+ (instancetype)universalLinkWithURL:(NSURL *)url;
- (NSURL *)URL;
- (NSURL *)url;
@end

@implementation SFUniversalLink

- (instancetype)init {
    return [self initWithURL:nil];
}

- (instancetype)initWithURL:(NSURL *)url {
    self = [super init];
    if (self) {
        _url = [url retain];
    }
    return self;
}

+ (instancetype)universalLinkWithURL:(NSURL *)url {
    return [[[self alloc] initWithURL:url] autorelease];
}

- (void)dealloc {
    [_url release];
    [super dealloc];
}

- (NSURL *)URL {
    return _url;
}

- (NSURL *)url {
    return _url;
}

@end
