project(QuickLookUI)

remove_sdk_framework(QuickLookUI)

set(DYLIB_COMPAT_VERSION "1.0.0")
set(DYLIB_CURRENT_VERSION "1.0.0")

set(FRAMEWORK_VERSION "A")

generate_sdk_framework(QuickLookUI
    VERSION ${FRAMEWORK_VERSION}
    HEADER "include/QuickLookUI"
)

add_framework(QuickLookUI
    FAT
    CURRENT_VERSION
    VERSION ${FRAMEWORK_VERSION}

    SOURCES
        src/QuickLookUICompatibility.c

    DEPENDENCIES
        system
        objc
        Foundation
        Quartz
        QuickLook
)

set(QuickLook_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/QuickLook/QuickLook)
set(_QuickLookUI_link_flags
    " -Wl,-dylib_file,/System/Library/Frameworks/QuickLook.framework/Versions/A/QuickLook:${QuickLook_BUILD}")
set(_QuickLookUI_reexport_link_flags "")
if (TARGET_x86_64)
    string(APPEND _QuickLookUI_reexport_link_flags
        " -Xarch_x86_64 -Wl,-reexported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/reexport-x86_64.exp")
endif (TARGET_x86_64)
if (TARGET_i386)
    string(APPEND _QuickLookUI_reexport_link_flags
        " -Xarch_i386 -Wl,-reexported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/reexport-i386.exp")
endif (TARGET_i386)
set_property(TARGET QuickLookUI APPEND_STRING PROPERTY
    LINK_FLAGS " ${_QuickLookUI_link_flags} ${_QuickLookUI_reexport_link_flags}")
