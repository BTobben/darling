#include <CoreFoundation/CoreFoundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible VideoToolbox shims for Chromium/Electron.
 * These only satisfy dynamic linking/basic key usage.
 */

#define VT_COMPAT_EXPORT __attribute__((visibility("default")))

#ifndef noErr
#define noErr 0
#endif

VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_BaseLayerFrameRateFraction = CFSTR("kVTCompressionPropertyKey_BaseLayerFrameRateFraction");
VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_ColorPrimaries = CFSTR("kVTCompressionPropertyKey_ColorPrimaries");
VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_EncoderID = CFSTR("kVTCompressionPropertyKey_EncoderID");
VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_ReferenceBufferCount = CFSTR("kVTCompressionPropertyKey_ReferenceBufferCount");
VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_TransferFunction = CFSTR("kVTCompressionPropertyKey_TransferFunction");
VT_COMPAT_EXPORT const CFStringRef kVTCompressionPropertyKey_YCbCrMatrix = CFSTR("kVTCompressionPropertyKey_YCbCrMatrix");
VT_COMPAT_EXPORT const CFStringRef kVTEncodeFrameOptionKey_BaseFrameQP = CFSTR("kVTEncodeFrameOptionKey_BaseFrameQP");
VT_COMPAT_EXPORT const CFStringRef kVTProfileLevel_HEVC_Main_AutoLevel = CFSTR("kVTProfileLevel_HEVC_Main_AutoLevel");
VT_COMPAT_EXPORT const CFStringRef kVTVideoDecoderSpecification_RequireHardwareAcceleratedVideoDecoder = CFSTR("kVTVideoDecoderSpecification_RequireHardwareAcceleratedVideoDecoder");
VT_COMPAT_EXPORT const CFStringRef kVTVideoEncoderSpecification_EnableLowLatencyRateControl = CFSTR("kVTVideoEncoderSpecification_EnableLowLatencyRateControl");

VT_COMPAT_EXPORT OSStatus VTRegisterSupplementalVideoDecoderIfAvailable(void) {
    return noErr;
}
