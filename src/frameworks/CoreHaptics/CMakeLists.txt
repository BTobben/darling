project(CoreHaptics)

remove_sdk_framework(CoreHaptics)

generate_sdk_framework(CoreHaptics
    VERSION A
    HEADER "include/CoreHaptics"
)

add_framework(CoreHaptics
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        CHCodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
