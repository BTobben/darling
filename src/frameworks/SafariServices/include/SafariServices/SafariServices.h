#import <Foundation/Foundation.h>

@interface SFUniversalLink : NSObject
- (instancetype)initWithURL:(NSURL *)url;
+ (instancetype)universalLinkWithURL:(NSURL *)url;
- (NSURL *)URL;
- (NSURL *)url;
@end
