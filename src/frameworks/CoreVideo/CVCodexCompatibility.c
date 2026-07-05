#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreVideo shims for Chromium/Electron.
 * These do not implement real display-link or image-buffer behavior.
 */

#define CV_COMPAT_EXPORT __attribute__((visibility("default")))

typedef void *CVDisplayLinkRef;
typedef struct __CVTimeStamp CVTimeStamp;
typedef int CVReturn;
typedef const struct __CVBuffer *CVBufferRef;
typedef CVBufferRef CVImageBufferRef;

static const CVReturn kCVReturnSuccessCompat = 0;
static const CVReturn kCVReturnErrorCompat = -6660;

CV_COMPAT_EXPORT CVDisplayLinkRef CVDisplayLinkRetain(CVDisplayLinkRef displayLink) {
    return displayLink;
}

CV_COMPAT_EXPORT CVReturn CVDisplayLinkGetCurrentTime(
    CVDisplayLinkRef displayLink,
    CVTimeStamp *outTime
) {
    return kCVReturnErrorCompat;
}

CV_COMPAT_EXPORT CGRect CVImageBufferGetCleanRect(CVImageBufferRef imageBuffer) {
    CGRect r = {{0, 0}, {0, 0}};
    return r;
}
