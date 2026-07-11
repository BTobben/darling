#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible TKTokenWatcher class for Chromium/Electron.
 */

@interface TKTokenWatcher : NSObject
- (instancetype)initWithInsertionHandler:(id)insertionHandler;
+ (instancetype)tokenWatcherWithInsertionHandler:(id)insertionHandler;
- (NSArray *)tokenIDs;
- (void)addRemovalHandler:(id)removalHandler forTokenID:(NSString *)tokenID;
@end

@implementation TKTokenWatcher

- (instancetype)initWithInsertionHandler:(id)insertionHandler {
    return [super init];
}

+ (instancetype)tokenWatcherWithInsertionHandler:(id)insertionHandler {
    return [[self alloc] initWithInsertionHandler:insertionHandler];
}

- (NSArray *)tokenIDs {
    return nil;
}

- (void)addRemovalHandler:(id)removalHandler forTokenID:(NSString *)tokenID {
}

@end
