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
set(ImageKit_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/Quartz/ImageKit/ImageKit)
set(QuartzComposer_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/Quartz/QuartzComposer/QuartzComposer)
set(QuartzFilters_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/Quartz/QuartzFilters/QuartzFilters)
set(PDFKit_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/PDFKit/PDFKit)
if (COMPONENT_gui)
    set(QuartzCore_BUILD ${CMAKE_BINARY_DIR}/src/external/cocotron/QuartzCore/QuartzCore)
else()
    set(QuartzCore_BUILD ${CMAKE_BINARY_DIR}/src/frameworks/dev-stubs/QuartzCore/QuartzCore)
endif()

set(_QuickLookUI_dylib_file_mappings
    "/System/Library/Frameworks/QuickLook.framework/Versions/A/QuickLook" "${QuickLook_BUILD}"
    "/System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/ImageKit.framework/Versions/A/ImageKit" "${ImageKit_BUILD}"
    "/System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/QuartzComposer.framework/Versions/A/QuartzComposer" "${QuartzComposer_BUILD}"
    "/System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/QuartzFilters.framework/Versions/A/QuartzFilters" "${QuartzFilters_BUILD}"
    "/System/Library/Frameworks/PDFKit.framework/Versions/A/PDFKit" "${PDFKit_BUILD}"
    "/System/Library/Frameworks/QuartzCore.framework/Versions/A/QuartzCore" "${QuartzCore_BUILD}"
)

set(_QuickLookUI_link_flags "")
while (_QuickLookUI_dylib_file_mappings)
    list(GET _QuickLookUI_dylib_file_mappings 0 _QuickLookUI_install_name)
    list(GET _QuickLookUI_dylib_file_mappings 1 _QuickLookUI_build_artifact)
    string(APPEND _QuickLookUI_link_flags
        " -Wl,-dylib_file,${_QuickLookUI_install_name}:${_QuickLookUI_build_artifact}")
    list(REMOVE_AT _QuickLookUI_dylib_file_mappings 0 1)
endwhile ()

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
