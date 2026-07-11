project(MediaPlayer)

remove_sdk_framework(MediaPlayer)

generate_sdk_framework(MediaPlayer
    VERSION A
    HEADER "include/MediaPlayer"
)

add_framework(MediaPlayer
    FAT
    CURRENT_VERSION
    VERSION "A"
    SOURCES
        MPCodexCompatibility.m
    DEPENDENCIES
        objc
        Foundation
)
