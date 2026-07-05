#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreServices/LaunchServices shims for Chromium/Electron.
 */

#define CS_COMPAT_EXPORT __attribute__((visibility("default")))

typedef const void *CFStringRef;
typedef const void *CFURLRef;
typedef const void *CFArrayRef;
typedef const void *CFErrorRef;
typedef const void *CFDictionaryRef;
typedef uint32_t LSRolesMask;
typedef int32_t OSStatus;
typedef unsigned char Boolean;

#ifndef noErr
#define noErr 0
#endif

#ifndef kLSApplicationNotFoundErr
#define kLSApplicationNotFoundErr (-10814)
#endif

CS_COMPAT_EXPORT const void *kLSQuarantineDataURLKey = 0;
CS_COMPAT_EXPORT const void *kLSQuarantineOriginURLKey = 0;
CS_COMPAT_EXPORT const void *kLSQuarantineTypeKey = 0;
CS_COMPAT_EXPORT const void *kLSQuarantineTypeOtherDownload = 0;
CS_COMPAT_EXPORT const void *kLSQuarantineTypeWebDownload = 0;
CS_COMPAT_EXPORT const void *kLSSharedFileListItemLast = 0;
CS_COMPAT_EXPORT const void *kLSSharedFileListLoginItemHidden = 0;
CS_COMPAT_EXPORT const void *kLSSharedFileListSessionLoginItems = 0;

CS_COMPAT_EXPORT OSStatus LSSetDefaultHandlerForURLScheme(CFStringRef inURLScheme, CFStringRef inHandlerBundleID) {
    return noErr;
}

CS_COMPAT_EXPORT OSStatus LSRegisterURL(CFURLRef inURL, Boolean inUpdate) {
    return noErr;
}
