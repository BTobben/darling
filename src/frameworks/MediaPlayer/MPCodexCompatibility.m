#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal MediaPlayer.framework ABI shims for Chromium/Electron.
 */

#define MP_COMPAT_EXPORT __attribute__((visibility("default")))

MP_COMPAT_EXPORT NSString * const MPMediaItemPropertyAlbumTitle = @"MPMediaItemPropertyAlbumTitle";
MP_COMPAT_EXPORT NSString * const MPMediaItemPropertyArtist = @"MPMediaItemPropertyArtist";
MP_COMPAT_EXPORT NSString * const MPMediaItemPropertyArtwork = @"MPMediaItemPropertyArtwork";
MP_COMPAT_EXPORT NSString * const MPMediaItemPropertyPlaybackDuration = @"MPMediaItemPropertyPlaybackDuration";
MP_COMPAT_EXPORT NSString * const MPMediaItemPropertyTitle = @"MPMediaItemPropertyTitle";
MP_COMPAT_EXPORT NSString * const MPNowPlayingInfoPropertyCurrentPlaybackDate = @"MPNowPlayingInfoPropertyCurrentPlaybackDate";
MP_COMPAT_EXPORT NSString * const MPNowPlayingInfoPropertyElapsedPlaybackTime = @"MPNowPlayingInfoPropertyElapsedPlaybackTime";
MP_COMPAT_EXPORT NSString * const MPNowPlayingInfoPropertyPlaybackRate = @"MPNowPlayingInfoPropertyPlaybackRate";


@interface MPMediaItemArtwork : NSObject
@end

@implementation MPMediaItemArtwork
@end


@interface MPNowPlayingInfoCenter : NSObject
@end

@implementation MPNowPlayingInfoCenter
@end


@interface MPRemoteCommandCenter : NSObject
@end

@implementation MPRemoteCommandCenter
@end

