#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible MediaAccessibility constant for Chromium/Electron.
 * Exported as NULL to avoid requiring CoreFoundation/NSString linkage here.
 */

#define MA_COMPAT_EXPORT __attribute__((visibility("default")))

MA_COMPAT_EXPORT const void *kMACaptionAppearanceSettingsChangedNotification = 0;
