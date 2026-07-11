#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal loader-only LocalAuthenticationEmbeddedUI.framework ABI shim.
 */

@interface LAAuthenticationView : NSObject {
    id _delegate;
}
- (id)delegate;
- (void)setDelegate:(id)delegate;
- (void)startAuthentication;
- (void)cancelAuthentication;
@end

@implementation LAAuthenticationView
- (id)delegate { return _delegate; }
- (void)setDelegate:(id)delegate { _delegate = delegate; }
- (void)startAuthentication {}
- (void)cancelAuthentication {}
@end
