project(CoreLocation)

remove_sdk_framework(CoreLocation)

generate_sdk_framework(CoreLocation
    VERSION A
    HEADER "include/CoreLocation"
)

add_framework(CoreLocation
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        CLCodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
