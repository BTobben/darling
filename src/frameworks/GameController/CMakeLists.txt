project(GameController)

remove_sdk_framework(GameController)

generate_sdk_framework(GameController
    VERSION A
    HEADER "include/GameController"
)

add_framework(GameController
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        GCCodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
