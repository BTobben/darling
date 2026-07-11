project(CoreML)

remove_sdk_framework(CoreML)

generate_sdk_framework(CoreML
    VERSION A
    HEADER "include/CoreML"
)

add_framework(CoreML
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        CoreMLCodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
