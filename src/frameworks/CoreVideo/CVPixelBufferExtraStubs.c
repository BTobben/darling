#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CVPixelBuffer/CVPixelBufferPool stubs.
 * These do not implement real pixel-buffer storage.
 *
 * Self-contained on purpose: this Darling tree does not provide
 * CoreVideo/CVPixelBufferPool.h.
 */

typedef int32_t CVReturn;
typedef uint64_t CVOptionFlags;
typedef uint32_t OSType;
typedef unsigned char Boolean;
typedef unsigned long CFTypeID;

typedef const void * CFAllocatorRef;
typedef const void * CFDictionaryRef;

typedef struct __CVPixelBuffer *CVPixelBufferRef;
typedef struct __CVPixelBufferPool *CVPixelBufferPoolRef;
typedef struct __IOSurface *IOSurfaceRef;

#define kCVReturnSuccess 0
#define kCVReturnUnsupported -6663

__attribute__((visibility("default")))
CFTypeID CVPixelBufferGetTypeID(void) {
    return 0;
}

__attribute__((visibility("default")))
CVReturn CVPixelBufferCreateWithIOSurface(CFAllocatorRef allocator,
                                          IOSurfaceRef surface,
                                          CFDictionaryRef pixelBufferAttributes,
                                          CVPixelBufferRef *pixelBufferOut) {
    (void)allocator;
    (void)surface;
    (void)pixelBufferAttributes;
    if (pixelBufferOut) {
        *pixelBufferOut = NULL;
    }
    return kCVReturnUnsupported;
}

__attribute__((visibility("default")))
size_t CVPixelBufferGetBytesPerRow(CVPixelBufferRef pixelBuffer) {
    (void)pixelBuffer;
    return 0;
}

__attribute__((visibility("default")))
size_t CVPixelBufferGetDataSize(CVPixelBufferRef pixelBuffer) {
    (void)pixelBuffer;
    return 0;
}

__attribute__((visibility("default")))
size_t CVPixelBufferGetHeightOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) {
    (void)pixelBuffer;
    (void)planeIndex;
    return 0;
}

__attribute__((visibility("default")))
OSType CVPixelBufferGetPixelFormatType(CVPixelBufferRef pixelBuffer) {
    (void)pixelBuffer;
    return 0;
}

__attribute__((visibility("default")))
Boolean CVPixelBufferIsPlanar(CVPixelBufferRef pixelBuffer) {
    (void)pixelBuffer;
    return 0;
}

__attribute__((visibility("default")))
CVReturn CVPixelBufferPoolCreate(CFAllocatorRef allocator,
                                 CFDictionaryRef poolAttributes,
                                 CFDictionaryRef pixelBufferAttributes,
                                 CVPixelBufferPoolRef *poolOut) {
    (void)allocator;
    (void)poolAttributes;
    (void)pixelBufferAttributes;
    if (poolOut) {
        *poolOut = NULL;
    }
    return kCVReturnUnsupported;
}

__attribute__((visibility("default")))
CVReturn CVPixelBufferPoolCreatePixelBuffer(CFAllocatorRef allocator,
                                            CVPixelBufferPoolRef pixelBufferPool,
                                            CVPixelBufferRef *pixelBufferOut) {
    (void)allocator;
    (void)pixelBufferPool;
    if (pixelBufferOut) {
        *pixelBufferOut = NULL;
    }
    return kCVReturnUnsupported;
}

__attribute__((visibility("default")))
CVReturn CVPixelBufferPoolCreatePixelBufferWithAuxAttributes(CFAllocatorRef allocator,
                                                             CVPixelBufferPoolRef pixelBufferPool,
                                                             CFDictionaryRef auxiliaryAttributes,
                                                             CVPixelBufferRef *pixelBufferOut) {
    (void)allocator;
    (void)pixelBufferPool;
    (void)auxiliaryAttributes;
    if (pixelBufferOut) {
        *pixelBufferOut = NULL;
    }
    return kCVReturnUnsupported;
}

__attribute__((visibility("default")))
void CVPixelBufferPoolFlush(CVPixelBufferPoolRef pool, CVOptionFlags options) {
    (void)pool;
    (void)options;
}
