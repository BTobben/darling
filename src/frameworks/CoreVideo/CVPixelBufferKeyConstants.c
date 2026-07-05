#include <CoreFoundation/CoreFoundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreVideo CFString key constants.
 * These do not implement real CoreVideo behavior.
 */

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferAmbientViewingEnvironmentKey = CFSTR("kCVImageBufferAmbientViewingEnvironmentKey");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferColorPrimaries_DCI_P3 = CFSTR("kCVImageBufferColorPrimaries_DCI_P3");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferColorPrimaries_ITU_R_2020 = CFSTR("kCVImageBufferColorPrimaries_ITU_R_2020");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferColorPrimaries_P3_D65 = CFSTR("kCVImageBufferColorPrimaries_P3_D65");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferContentLightLevelInfoKey = CFSTR("kCVImageBufferContentLightLevelInfoKey");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferMasteringDisplayColorVolumeKey = CFSTR("kCVImageBufferMasteringDisplayColorVolumeKey");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_ITU_R_2020 = CFSTR("kCVImageBufferTransferFunction_ITU_R_2020");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_ITU_R_2100_HLG = CFSTR("kCVImageBufferTransferFunction_ITU_R_2100_HLG");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_Linear = CFSTR("kCVImageBufferTransferFunction_Linear");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_SMPTE_ST_2084_PQ = CFSTR("kCVImageBufferTransferFunction_SMPTE_ST_2084_PQ");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_SMPTE_ST_428_1 = CFSTR("kCVImageBufferTransferFunction_SMPTE_ST_428_1");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferTransferFunction_sRGB = CFSTR("kCVImageBufferTransferFunction_sRGB");

__attribute__((visibility("default"), used))
const CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_2020 = CFSTR("kCVImageBufferYCbCrMatrix_ITU_R_2020");

__attribute__((visibility("default"), used))
const CFStringRef kCVPixelBufferPoolAllocationThresholdKey = CFSTR("kCVPixelBufferPoolAllocationThresholdKey");

