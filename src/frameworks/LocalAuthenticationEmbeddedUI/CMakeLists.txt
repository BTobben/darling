project(LocalAuthenticationEmbeddedUI)

remove_sdk_framework(LocalAuthenticationEmbeddedUI)

generate_sdk_framework(LocalAuthenticationEmbeddedUI
    VERSION A
    HEADER "include/LocalAuthenticationEmbeddedUI"
)

add_framework(LocalAuthenticationEmbeddedUI
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        LAEmbeddedUICodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
