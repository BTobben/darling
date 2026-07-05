#include <CoreFoundation/CoreFoundation.h>
#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreServices LaunchServices shims for Chromium/Electron.
 */

#define CS_LS_COMPAT_EXPORT __attribute__((visibility("default")))

typedef uint32_t LSLaunchFlags;

#ifndef noErr
#define noErr 0
#endif

#ifndef kLSApplicationNotFoundErr
#define kLSApplicationNotFoundErr (-10814)
#endif

typedef struct LSLaunchURLSpec {
    CFArrayRef appURLs;
    CFArrayRef itemURLs;
    void *passThruParams;
    LSLaunchFlags launchFlags;
    void *asyncRefCon;
} LSLaunchURLSpec;

typedef const struct __LSSharedFileList *LSSharedFileListRef;
typedef const struct __LSSharedFileListItem *LSSharedFileListItemRef;

/* dyld wants symbol "__kLSOpenOptionBackgroundLaunchKey", so the C identifier needs one leading underscore. */
CS_LS_COMPAT_EXPORT const CFStringRef _kLSOpenOptionBackgroundLaunchKey = NULL;

CS_LS_COMPAT_EXPORT OSStatus LSOpenFromURLSpec(const LSLaunchURLSpec *inURLSpec, CFURLRef *outLaunchedURL) {
    if (outLaunchedURL) {
        *outLaunchedURL = NULL;
    }
    return kLSApplicationNotFoundErr;
}

CS_LS_COMPAT_EXPORT LSSharedFileListRef LSSharedFileListCreate(
    CFAllocatorRef inAllocator,
    CFStringRef inListType,
    CFTypeRef listOptions
) {
    return NULL;
}

CS_LS_COMPAT_EXPORT CFArrayRef LSSharedFileListCopySnapshot(
    LSSharedFileListRef inList,
    UInt32 *outSnapshotSeed
) {
    if (outSnapshotSeed) {
        *outSnapshotSeed = 0;
    }
    return NULL;
}

CS_LS_COMPAT_EXPORT LSSharedFileListItemRef LSSharedFileListInsertItemURL(
    LSSharedFileListRef inList,
    LSSharedFileListItemRef insertAfterThisItem,
    CFStringRef inDisplayName,
    void *inIconRef,
    CFURLRef inURL,
    CFDictionaryRef inPropertiesToSet,
    CFArrayRef inPropertiesToClear
) {
    return NULL;
}

CS_LS_COMPAT_EXPORT CFTypeRef LSSharedFileListItemCopyProperty(
    LSSharedFileListItemRef inItem,
    CFStringRef inPropertyName
) {
    return NULL;
}

CS_LS_COMPAT_EXPORT CFURLRef LSSharedFileListItemCopyResolvedURL(
    LSSharedFileListItemRef inItem,
    UInt32 inFlags,
    CFErrorRef *outError
) {
    if (outError) {
        *outError = NULL;
    }
    return NULL;
}

CS_LS_COMPAT_EXPORT OSStatus LSSharedFileListItemRemove(
    LSSharedFileListRef inList,
    LSSharedFileListItemRef inItem
) {
    return noErr;
}
