#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible CoreServices AppleEvents shims for Chromium/Electron.
 */

#define CS_AE_COMPAT_EXPORT __attribute__((visibility("default")))

typedef int32_t OSStatus;
typedef uint32_t AEEventClass;
typedef uint32_t AEEventID;
typedef uint32_t DescType;
typedef uint32_t OSType;
typedef uint32_t AEKeyword;
typedef uint32_t AESendMode;
typedef int32_t AESendPriority;
typedef int32_t SInt32;
typedef int32_t AEReturnID;
typedef int32_t AETransactionID;
typedef int32_t Size;
typedef intptr_t SRefCon;
typedef unsigned char Boolean;

typedef void *AEEventHandlerUPP;

typedef struct AEDesc {
    DescType descriptorType;
    void *dataHandle;
} AEDesc;

typedef AEDesc AppleEvent;
typedef AEDesc AEAddressDesc;
typedef AEDesc AERecord;
typedef AEDesc AEDescList;

#ifndef noErr
#define noErr 0
#endif

#ifndef paramErr
#define paramErr (-50)
#endif

#ifndef errAEEventNotHandled
#define errAEEventNotHandled (-1708)
#endif

#ifndef errAEDescNotFound
#define errAEDescNotFound (-1701)
#endif

static void codex_clear_desc(AEDesc *desc) {
    if (desc) {
        desc->descriptorType = 0;
        desc->dataHandle = NULL;
    }
}

CS_AE_COMPAT_EXPORT OSStatus AECreateDesc(
    DescType typeCode,
    const void *dataPtr,
    Size dataSize,
    AEDesc *result
) {
    if (!result) {
        return paramErr;
    }

    result->descriptorType = typeCode;
    result->dataHandle = NULL;
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AEDisposeDesc(AEDesc *theAEDesc) {
    codex_clear_desc(theAEDesc);
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AECreateAppleEvent(
    AEEventClass theAEEventClass,
    AEEventID theAEEventID,
    const AEAddressDesc *target,
    AEReturnID returnID,
    AETransactionID transactionID,
    AppleEvent *result
) {
    if (!result) {
        return paramErr;
    }

    result->descriptorType = theAEEventClass;
    result->dataHandle = NULL;
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AEPutParamDesc(
    AppleEvent *theAppleEvent,
    AEKeyword theAEKeyword,
    const AEDesc *theAEDesc
) {
    return theAppleEvent ? noErr : paramErr;
}

CS_AE_COMPAT_EXPORT OSStatus AEGetParamDesc(
    const AppleEvent *theAppleEvent,
    AEKeyword theAEKeyword,
    DescType desiredType,
    AEDesc *result
) {
    codex_clear_desc(result);
    return errAEDescNotFound;
}

CS_AE_COMPAT_EXPORT OSStatus AESendMessage(
    const AppleEvent *event,
    AppleEvent *reply,
    AESendMode sendMode,
    SInt32 timeOutInTicks
) {
    codex_clear_desc(reply);
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AEInstallEventHandler(
    AEEventClass theAEEventClass,
    AEEventID theAEEventID,
    AEEventHandlerUPP handler,
    SRefCon handlerRefcon,
    Boolean isSysHandler
) {
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AERemoveEventHandler(
    AEEventClass theAEEventClass,
    AEEventID theAEEventID,
    AEEventHandlerUPP handler,
    Boolean isSysHandler
) {
    return noErr;
}

CS_AE_COMPAT_EXPORT OSStatus AEGetEventHandler(
    AEEventClass theAEEventClass,
    AEEventID theAEEventID,
    AEEventHandlerUPP *handler,
    SRefCon *handlerRefcon,
    Boolean isSysHandler
) {
    if (handler) {
        *handler = NULL;
    }
    if (handlerRefcon) {
        *handlerRefcon = 0;
    }
    return errAEEventNotHandled;
}
