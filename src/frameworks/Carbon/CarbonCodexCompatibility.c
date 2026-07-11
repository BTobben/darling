#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible Carbon/Event/TIS shims for Chromium/Electron.
 * Do not define GetApplicationEventTarget here; Darling already exports it.
 */

#define CARBON_COMPAT_EXPORT __attribute__((visibility("default")))

typedef int32_t OSStatus;
typedef uint32_t UInt32;
typedef uint32_t OSType;
typedef uint32_t OptionBits;
typedef intptr_t Size;
typedef unsigned char Boolean;

typedef const void *CFStringRef;
typedef const void *CFDictionaryRef;
typedef const void *CFArrayRef;

typedef void *EventRef;
typedef void *EventTargetRef;
typedef void *EventHandlerRef;
typedef void *EventHandlerCallRef;
typedef void *EventHandlerUPP;
typedef void *EventHotKeyRef;
typedef void *TISInputSourceRef;
typedef void *TSMDocumentID;

typedef struct EventHotKeyID {
    UInt32 signature;
    UInt32 id;
} EventHotKeyID;

typedef struct EventTypeSpec {
    UInt32 eventClass;
    UInt32 eventKind;
} EventTypeSpec;

static char carbon_dummy_ref;

#ifndef noErr
#define noErr 0
#endif

#ifndef paramErr
#define paramErr (-50)
#endif

#ifndef eventLoopTimedOutErr
#define eventLoopTimedOutErr (-9875)
#endif

#ifndef eventNotHandledErr
#define eventNotHandledErr (-9874)
#endif

CARBON_COMPAT_EXPORT const void *kTISPropertyInputSourceID = 0;
CARBON_COMPAT_EXPORT const void *kTISPropertyUnicodeKeyLayoutData = 0;

CARBON_COMPAT_EXPORT UInt32 GetCurrentKeyModifiers(void) {
    return 0;
}

CARBON_COMPAT_EXPORT OSStatus RegisterEventHotKey(
    UInt32 inHotKeyCode,
    UInt32 inHotKeyModifiers,
    EventHotKeyID inHotKeyID,
    EventTargetRef inTarget,
    OptionBits inOptions,
    EventHotKeyRef *outRef
) {
    if (outRef) {
        *outRef = &carbon_dummy_ref;
    }
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus UnregisterEventHotKey(EventHotKeyRef inHotKey) {
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus InstallEventHandler(
    EventTargetRef inTarget,
    EventHandlerUPP inHandler,
    UInt32 inNumTypes,
    const EventTypeSpec *inList,
    void *inUserData,
    EventHandlerRef *outRef
) {
    if (outRef) {
        *outRef = &carbon_dummy_ref;
    }
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus RemoveEventHandler(EventHandlerRef inHandlerRef) {
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus CallNextEventHandler(
    EventHandlerCallRef inCallRef,
    EventRef inEvent
) {
    return eventNotHandledErr;
}

CARBON_COMPAT_EXPORT OSStatus ReceiveNextEvent(
    UInt32 inNumTypes,
    const EventTypeSpec *inList,
    double inTimeout,
    Boolean inPullEvent,
    EventRef *outEvent
) {
    if (outEvent) {
        *outEvent = NULL;
    }
    return eventLoopTimedOutErr;
}

CARBON_COMPAT_EXPORT void ReleaseEvent(EventRef inEvent) {
}

CARBON_COMPAT_EXPORT UInt32 GetEventKind(EventRef inEvent) {
    return 0;
}

CARBON_COMPAT_EXPORT OSStatus GetEventParameter(
    EventRef inEvent,
    UInt32 inName,
    UInt32 inDesiredType,
    UInt32 *outActualType,
    UInt32 inBufferSize,
    UInt32 *outActualSize,
    void *outData
) {
    if (outActualType) {
        *outActualType = 0;
    }
    if (outActualSize) {
        *outActualSize = 0;
    }
    return paramErr;
}

CARBON_COMPAT_EXPORT void EnableSecureEventInput(void) {
}

CARBON_COMPAT_EXPORT void DisableSecureEventInput(void) {
}

CARBON_COMPAT_EXPORT UInt32 LMGetKbdLast(void) {
    return 0;
}

CARBON_COMPAT_EXPORT UInt32 LMGetKbdType(void) {
    return 0;
}

CARBON_COMPAT_EXPORT TISInputSourceRef TISCopyCurrentKeyboardInputSource(void) {
    return NULL;
}

CARBON_COMPAT_EXPORT TISInputSourceRef TISCopyCurrentASCIICapableKeyboardLayoutInputSource(void) {
    return NULL;
}

CARBON_COMPAT_EXPORT TISInputSourceRef TISCopyCurrentKeyboardLayoutInputSource(void) {
    return NULL;
}

CARBON_COMPAT_EXPORT CFArrayRef TISCreateASCIICapableInputSourceList(
    CFDictionaryRef properties,
    Boolean includeAllInstalled
) {
    return NULL;
}

CARBON_COMPAT_EXPORT const void *TISGetInputSourceProperty(
    TISInputSourceRef inputSource,
    CFStringRef propertyKey
) {
    return NULL;
}

CARBON_COMPAT_EXPORT OSStatus TSMSetDocumentProperty(
    TSMDocumentID document,
    OSType propertyTag,
    Size propertySize,
    const void *propertyData
) {
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus TSMRemoveDocumentProperty(
    TSMDocumentID document,
    OSType propertyTag
) {
    return noErr;
}

CARBON_COMPAT_EXPORT OSStatus AEProcessEvent(EventRef event) {
    return eventNotHandledErr;
}
