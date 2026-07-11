#include <CoreFoundation/CoreFoundation.h>
#include <CoreVideo/CVBuffer.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CVBuffer attachment stubs.
 * This does not implement real CoreVideo attachment storage.
 *
 * Darling's current CoreVideo headers may not define CVAttachmentMode yet.
 */
typedef unsigned int CVAttachmentMode;

enum {
    kCVAttachmentMode_ShouldNotPropagate = 0,
    kCVAttachmentMode_ShouldPropagate = 1
};

__attribute__((visibility("default")))
CFTypeRef CVBufferCopyAttachment(CVBufferRef buffer, CFStringRef key, CVAttachmentMode *attachmentMode) {
    (void)buffer;
    (void)key;
    if (attachmentMode) {
        *attachmentMode = kCVAttachmentMode_ShouldNotPropagate;
    }
    return NULL;
}

__attribute__((visibility("default")))
CFDictionaryRef CVBufferCopyAttachments(CVBufferRef buffer, CVAttachmentMode attachmentMode) {
    (void)buffer;
    (void)attachmentMode;
    return CFDictionaryCreate(
        kCFAllocatorDefault,
        NULL,
        NULL,
        0,
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks
    );
}

__attribute__((visibility("default")))
CFTypeRef CVBufferGetAttachment(CVBufferRef buffer, CFStringRef key, CVAttachmentMode *attachmentMode) {
    (void)buffer;
    (void)key;
    if (attachmentMode) {
        *attachmentMode = kCVAttachmentMode_ShouldNotPropagate;
    }
    return NULL;
}

__attribute__((visibility("default")))
Boolean CVBufferHasAttachment(CVBufferRef buffer, CFStringRef key) {
    (void)buffer;
    (void)key;
    return 0;
}

__attribute__((visibility("default")))
void CVBufferSetAttachment(CVBufferRef buffer, CFStringRef key, CFTypeRef value, CVAttachmentMode attachmentMode) {
    (void)buffer;
    (void)key;
    (void)value;
    (void)attachmentMode;
}

__attribute__((visibility("default")))
void CVBufferSetAttachments(CVBufferRef buffer, CFDictionaryRef theAttachments, CVAttachmentMode attachmentMode) {
    (void)buffer;
    (void)theAttachments;
    (void)attachmentMode;
}

__attribute__((visibility("default")))
void CVBufferRemoveAttachment(CVBufferRef buffer, CFStringRef key) {
    (void)buffer;
    (void)key;
}

__attribute__((visibility("default")))
void CVBufferRemoveAllAttachments(CVBufferRef buffer) {
    (void)buffer;
}

__attribute__((visibility("default")))
void CVBufferPropagateAttachments(CVBufferRef sourceBuffer, CVBufferRef destinationBuffer) {
    (void)sourceBuffer;
    (void)destinationBuffer;
}
