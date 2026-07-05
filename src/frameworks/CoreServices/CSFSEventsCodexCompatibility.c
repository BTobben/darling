#include <CoreFoundation/CoreFoundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreServices FSEvents shims for Chromium/Electron.
 */

#define CS_FSE_COMPAT_EXPORT __attribute__((visibility("default")))

typedef uint64_t FSEventStreamEventId;
typedef uint32_t FSEventStreamCreateFlags;
typedef uint32_t FSEventStreamEventFlags;

typedef struct __CodexFSEventStream *FSEventStreamRef;
typedef const struct __CodexFSEventStream *ConstFSEventStreamRef;

typedef struct FSEventStreamContext {
    CFIndex version;
    void *info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} FSEventStreamContext;

typedef void (*FSEventStreamCallback)(
    ConstFSEventStreamRef streamRef,
    void *clientCallBackInfo,
    size_t numEvents,
    void *eventPaths,
    const FSEventStreamEventFlags eventFlags[],
    const FSEventStreamEventId eventIds[]
);

struct __CodexFSEventStream {
    FSEventStreamEventId latest;
    void *info;
};

static FSEventStreamEventId codex_fse_current_event_id = 1;

static FSEventStreamRef codex_fse_create(FSEventStreamContext *context) {
    struct __CodexFSEventStream *stream =
        (struct __CodexFSEventStream *)calloc(1, sizeof(struct __CodexFSEventStream));

    if (!stream) {
        return NULL;
    }

    stream->latest = codex_fse_current_event_id;
    stream->info = context ? context->info : NULL;
    return stream;
}

CS_FSE_COMPAT_EXPORT FSEventStreamEventId FSEventsGetCurrentEventId(void) {
    return codex_fse_current_event_id++;
}

CS_FSE_COMPAT_EXPORT FSEventStreamRef FSEventStreamCreate(
    CFAllocatorRef allocator,
    FSEventStreamCallback callback,
    FSEventStreamContext *context,
    CFArrayRef pathsToWatch,
    FSEventStreamEventId sinceWhen,
    CFTimeInterval latency,
    FSEventStreamCreateFlags flags
) {
    return codex_fse_create(context);
}

CS_FSE_COMPAT_EXPORT FSEventStreamRef FSEventStreamCreateRelativeToDevice(
    CFAllocatorRef allocator,
    FSEventStreamCallback callback,
    FSEventStreamContext *context,
    int deviceToWatch,
    CFArrayRef pathsToWatchRelativeToDevice,
    FSEventStreamEventId sinceWhen,
    CFTimeInterval latency,
    FSEventStreamCreateFlags flags
) {
    return codex_fse_create(context);
}

CS_FSE_COMPAT_EXPORT FSEventStreamRef FSEventStreamRetain(FSEventStreamRef streamRef) {
    return streamRef;
}

CS_FSE_COMPAT_EXPORT void FSEventStreamRelease(FSEventStreamRef streamRef) {
    /* Intentionally leaked/no-op: avoids double-free from incomplete refcount emulation. */
}

CS_FSE_COMPAT_EXPORT void FSEventStreamScheduleWithRunLoop(
    FSEventStreamRef streamRef,
    CFRunLoopRef runLoop,
    CFStringRef runLoopMode
) {
}

CS_FSE_COMPAT_EXPORT void FSEventStreamUnscheduleFromRunLoop(
    FSEventStreamRef streamRef,
    CFRunLoopRef runLoop,
    CFStringRef runLoopMode
) {
}

CS_FSE_COMPAT_EXPORT void FSEventStreamSetDispatchQueue(FSEventStreamRef streamRef, void *queue) {
}

CS_FSE_COMPAT_EXPORT Boolean FSEventStreamStart(FSEventStreamRef streamRef) {
    return 1;
}

CS_FSE_COMPAT_EXPORT void FSEventStreamStop(FSEventStreamRef streamRef) {
}

CS_FSE_COMPAT_EXPORT void FSEventStreamInvalidate(FSEventStreamRef streamRef) {
}

CS_FSE_COMPAT_EXPORT void FSEventStreamFlushSync(FSEventStreamRef streamRef) {
}

CS_FSE_COMPAT_EXPORT FSEventStreamEventId FSEventStreamFlushAsync(FSEventStreamRef streamRef) {
    return FSEventsGetCurrentEventId();
}

CS_FSE_COMPAT_EXPORT FSEventStreamEventId FSEventStreamGetLatestEventId(FSEventStreamRef streamRef) {
    return streamRef ? streamRef->latest : codex_fse_current_event_id;
}

CS_FSE_COMPAT_EXPORT CFArrayRef FSEventStreamCopyPathsBeingWatched(FSEventStreamRef streamRef) {
    return NULL;
}

CS_FSE_COMPAT_EXPORT Boolean FSEventStreamSetExclusionPaths(
    FSEventStreamRef streamRef,
    CFArrayRef exclusionPaths
) {
    return 1;
}

CS_FSE_COMPAT_EXPORT void FSEventStreamShow(FSEventStreamRef streamRef) {
}

CS_FSE_COMPAT_EXPORT CFStringRef FSEventStreamCopyDescription(FSEventStreamRef streamRef) {
    return NULL;
}
