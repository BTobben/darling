#include <CoreFoundation/CoreFoundation.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

/*
 * Temporary Darling/Codex experiment.
 * Remaining CoreServices ABI shims for Chromium/Electron.
 */

#define CS_COMPAT_EXPORT __attribute__((visibility("default")))

typedef int32_t CSCompatStatus;
typedef uint32_t CSCompatFourCharCode;

typedef struct {
    CSCompatFourCharCode descriptorType;
    void *dataHandle;
} CSCompatAEDesc;

static void cs_zero_desc(void *desc) {
    if (desc) {
        memset(desc, 0, sizeof(CSCompatAEDesc));
    }
}

CS_COMPAT_EXPORT const CFStringRef kMDItemWhereFroms = CFSTR("kMDItemWhereFroms");


CS_COMPAT_EXPORT void *MDItemCreate(CFAllocatorRef allocator, CFStringRef path) {
    return NULL;
}

CS_COMPAT_EXPORT unsigned char MDItemSetAttribute(void *item, CFStringRef name, CFTypeRef value) {
    return 0;
}

CS_COMPAT_EXPORT CSCompatStatus UCKeyTranslate(const void *keyLayoutPtr, uint16_t virtualKeyCode, uint16_t keyAction, uint32_t modifierKeyState, uint32_t keyboardType, uint32_t keyTranslateOptions, uint32_t *deadKeyState, long maxStringLength, long *actualStringLength, uint16_t *unicodeString) {
    if (actualStringLength) *actualStringLength = 0;
    if (deadKeyState) *deadKeyState = 0;
    return 0;
}

CS_COMPAT_EXPORT int _CSCheckFixDisable(const char *name) {
    return 0;
}

CS_COMPAT_EXPORT int _LSSetApplicationLaunchServicesServerConnectionStatus(int status) {
    return 0;
}
