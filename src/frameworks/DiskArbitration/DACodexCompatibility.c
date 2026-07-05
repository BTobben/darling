#include <CoreFoundation/CoreFoundation.h>
#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible DiskArbitration shims for Chromium/Electron.
 */

#define DA_COMPAT_EXPORT __attribute__((visibility("default")))

typedef const struct __DASession *DASessionRef;
typedef const struct __DADisk *DADiskRef;
typedef const struct __DADissenter *DADissenterRef;

typedef int32_t DAReturn;
typedef uint32_t io_service_t;

typedef uint32_t DADiskClaimOptions;
typedef uint32_t DADiskEjectOptions;
typedef uint32_t DADiskUnmountOptions;

typedef void (*DADiskClaimCallback)(DADiskRef disk, DADissenterRef dissenter, void *context);
typedef void (*DADiskClaimReleaseCallback)(DADiskRef disk, void *context);
typedef void (*DADiskEjectCallback)(DADiskRef disk, DADissenterRef dissenter, void *context);
typedef void (*DADiskUnmountCallback)(DADiskRef disk, DADissenterRef dissenter, void *context);

typedef void (*DADiskAppearedCallback)(DADiskRef disk, void *context);
typedef void (*DADiskDisappearedCallback)(DADiskRef disk, void *context);
typedef void (*DADiskDescriptionChangedCallback)(DADiskRef disk, CFArrayRef keys, void *context);

DA_COMPAT_EXPORT const CFStringRef kDADiskDescriptionMatchVolumeMountable = NULL;
DA_COMPAT_EXPORT const CFStringRef kDADiskDescriptionWatchVolumePath = NULL;

DA_COMPAT_EXPORT void DADiskClaim(
    DADiskRef disk,
    DADiskClaimOptions options,
    DADiskClaimReleaseCallback release,
    void *releaseContext,
    DADiskClaimCallback callback,
    void *callbackContext
) {
    if (callback) {
        callback(disk, NULL, callbackContext);
    }
}

DA_COMPAT_EXPORT void DADiskUnclaim(DADiskRef disk) {
}

DA_COMPAT_EXPORT void DADiskEject(
    DADiskRef disk,
    DADiskEjectOptions options,
    DADiskEjectCallback callback,
    void *context
) {
    if (callback) {
        callback(disk, NULL, context);
    }
}

DA_COMPAT_EXPORT void DADiskUnmount(
    DADiskRef disk,
    DADiskUnmountOptions options,
    DADiskUnmountCallback callback,
    void *context
) {
    if (callback) {
        callback(disk, NULL, context);
    }
}

DA_COMPAT_EXPORT void DARegisterDiskAppearedCallback(
    DASessionRef session,
    CFDictionaryRef match,
    DADiskAppearedCallback callback,
    void *context
) {
}

DA_COMPAT_EXPORT void DARegisterDiskDescriptionChangedCallback(
    DASessionRef session,
    CFDictionaryRef match,
    CFArrayRef watch,
    DADiskDescriptionChangedCallback callback,
    void *context
) {
}

DA_COMPAT_EXPORT void DARegisterDiskDisappearedCallback(
    DASessionRef session,
    CFDictionaryRef match,
    DADiskDisappearedCallback callback,
    void *context
) {
}
