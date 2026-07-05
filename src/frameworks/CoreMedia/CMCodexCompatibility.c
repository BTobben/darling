#include <CoreFoundation/CoreFoundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreMedia/CoreMediaIO shims for Chromium/Electron.
 * These only satisfy dynamic linking/basic key usage.
 */

#define CM_COMPAT_EXPORT __attribute__((visibility("default")))

typedef UInt32 CMIOObjectID;
typedef UInt32 CMIOObjectPropertySelector;
typedef UInt32 CMIOObjectPropertyScope;
typedef UInt32 CMIOObjectPropertyElement;
typedef struct CMIOObjectPropertyAddress {
    CMIOObjectPropertySelector mSelector;
    CMIOObjectPropertyScope mScope;
    CMIOObjectPropertyElement mElement;
} CMIOObjectPropertyAddress;

#ifndef noErr
#define noErr 0
#endif

CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionColorPrimaries_DCI_P3 = CFSTR("kCMFormatDescriptionColorPrimaries_DCI_P3");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionColorPrimaries_ITU_R_2020 = CFSTR("kCMFormatDescriptionColorPrimaries_ITU_R_2020");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionColorPrimaries_P3_D65 = CFSTR("kCMFormatDescriptionColorPrimaries_P3_D65");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionExtension_Depth = CFSTR("kCMFormatDescriptionExtension_Depth");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionExtension_FormatName = CFSTR("kCMFormatDescriptionExtension_FormatName");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionExtension_FullRangeVideo = CFSTR("kCMFormatDescriptionExtension_FullRangeVideo");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_ITU_R_2020 = CFSTR("kCMFormatDescriptionTransferFunction_ITU_R_2020");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_ITU_R_2100_HLG = CFSTR("kCMFormatDescriptionTransferFunction_ITU_R_2100_HLG");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_Linear = CFSTR("kCMFormatDescriptionTransferFunction_Linear");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_SMPTE_ST_2084_PQ = CFSTR("kCMFormatDescriptionTransferFunction_SMPTE_ST_2084_PQ");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_SMPTE_ST_428_1 = CFSTR("kCMFormatDescriptionTransferFunction_SMPTE_ST_428_1");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionTransferFunction_sRGB = CFSTR("kCMFormatDescriptionTransferFunction_sRGB");
CM_COMPAT_EXPORT const CFStringRef kCMFormatDescriptionYCbCrMatrix_ITU_R_2020 = CFSTR("kCMFormatDescriptionYCbCrMatrix_ITU_R_2020");
CM_COMPAT_EXPORT const CFStringRef kCMSampleAttachmentKey_IsDependedOnByOthers = CFSTR("kCMSampleAttachmentKey_IsDependedOnByOthers");
CM_COMPAT_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_ResetDecoderBeforeDecoding = CFSTR("kCMSampleBufferAttachmentKey_ResetDecoderBeforeDecoding");


CM_COMPAT_EXPORT OSStatus CMIOObjectGetPropertyData(
    CMIOObjectID objectID,
    const CMIOObjectPropertyAddress *address,
    UInt32 qualifierDataSize,
    const void *qualifierData,
    UInt32 dataSize,
    UInt32 *dataUsed,
    void *data
) {
    if (dataUsed != NULL) {
        *dataUsed = 0;
    }
    return -1;
}
