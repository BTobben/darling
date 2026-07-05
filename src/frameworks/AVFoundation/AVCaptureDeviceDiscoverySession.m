#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible AVCaptureDeviceDiscoverySession stub.
 * This does not implement real camera/device discovery.
 */

@interface AVCaptureDeviceDiscoverySession : NSObject {
@private
    NSArray *_deviceTypes;
    NSString *_mediaType;
    NSInteger _position;
}

+ (instancetype)discoverySessionWithDeviceTypes:(NSArray *)deviceTypes
                                      mediaType:(NSString *)mediaType
                                       position:(NSInteger)position;

- (id)initWithDeviceTypes:(NSArray *)deviceTypes
                mediaType:(NSString *)mediaType
                 position:(NSInteger)position;

- (NSArray *)devices;
- (NSArray *)deviceTypes;
- (NSString *)mediaType;
- (NSInteger)position;
- (NSSet *)supportedMultiCamDeviceSets;

@end

@implementation AVCaptureDeviceDiscoverySession

+ (instancetype)discoverySessionWithDeviceTypes:(NSArray *)deviceTypes
                                      mediaType:(NSString *)mediaType
                                       position:(NSInteger)position
{
    return [[[self alloc] initWithDeviceTypes:deviceTypes
                                    mediaType:mediaType
                                     position:position] autorelease];
}

- (id)initWithDeviceTypes:(NSArray *)deviceTypes
                mediaType:(NSString *)mediaType
                 position:(NSInteger)position
{
    self = [super init];
    if (self) {
        _deviceTypes = [deviceTypes copy];
        _mediaType = [mediaType copy];
        _position = position;
    }
    return self;
}

- (void)dealloc
{
    [_deviceTypes release];
    [_mediaType release];
    [super dealloc];
}

- (NSArray *)devices
{
    return [NSArray array];
}

- (NSArray *)deviceTypes
{
    return _deviceTypes ? _deviceTypes : [NSArray array];
}

- (NSString *)mediaType
{
    return _mediaType;
}

- (NSInteger)position
{
    return _position;
}

- (NSSet *)supportedMultiCamDeviceSets
{
    return [NSSet set];
}

@end
