project(SafariServices)

remove_sdk_framework(SafariServices)

generate_sdk_framework(SafariServices
    VERSION "A"
    HEADER "include/SafariServices"
)

add_framework(SafariServices
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        SFCodexCompatibility.m
    DEPENDENCIES
        system
)

target_link_libraries(SafariServices PRIVATE objc Foundation)
