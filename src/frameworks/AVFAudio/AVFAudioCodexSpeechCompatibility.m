#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal ABI-compatible AVFAudio speech shims for Chromium/Electron.
 * These do not implement real speech synthesis.
 */

float AVSpeechUtteranceMinimumSpeechRate __attribute__((visibility("default"))) = 0.0f;
float AVSpeechUtteranceDefaultSpeechRate __attribute__((visibility("default"))) = 0.5f;
float AVSpeechUtteranceMaximumSpeechRate __attribute__((visibility("default"))) = 1.0f;

typedef NSInteger AVSpeechBoundary;

@class AVSpeechSynthesisVoice;

@interface AVSpeechUtterance : NSObject {
    NSString *_speechString;
    AVSpeechSynthesisVoice *_voice;
    float _rate;
    float _pitchMultiplier;
    float _volume;
}
+ (instancetype)speechUtteranceWithString:(NSString *)string;
- (instancetype)initWithString:(NSString *)string;
- (NSString *)speechString;
- (void)setVoice:(AVSpeechSynthesisVoice *)voice;
- (AVSpeechSynthesisVoice *)voice;
- (void)setRate:(float)rate;
- (float)rate;
- (void)setPitchMultiplier:(float)pitchMultiplier;
- (float)pitchMultiplier;
- (void)setVolume:(float)volume;
- (float)volume;
@end

@interface AVSpeechSynthesisVoice : NSObject {
    NSString *_language;
}
+ (instancetype)voiceWithLanguage:(NSString *)language;
+ (NSString *)currentLanguageCode;
+ (NSArray *)speechVoices;
- (instancetype)initWithLanguage:(NSString *)language;
- (NSString *)language;
- (NSString *)name;
- (NSString *)identifier;
@end

@interface AVSpeechSynthesizer : NSObject {
    id _delegate;
}
- (void)setDelegate:(id)delegate;
- (id)delegate;
- (BOOL)isSpeaking;
- (BOOL)isPaused;
- (BOOL)speakUtterance:(AVSpeechUtterance *)utterance;
- (BOOL)stopSpeakingAtBoundary:(AVSpeechBoundary)boundary;
- (BOOL)pauseSpeakingAtBoundary:(AVSpeechBoundary)boundary;
- (BOOL)continueSpeaking;
@end

@implementation AVSpeechUtterance

+ (instancetype)speechUtteranceWithString:(NSString *)string {
    return [[[self alloc] initWithString:string] autorelease];
}

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        _speechString = [string copy];
        _rate = AVSpeechUtteranceDefaultSpeechRate;
        _pitchMultiplier = 1.0f;
        _volume = 1.0f;
    }
    return self;
}

- (void)dealloc {
    [_speechString release];
    [_voice release];
    [super dealloc];
}

- (NSString *)speechString { return _speechString; }

- (void)setVoice:(AVSpeechSynthesisVoice *)voice {
    if (_voice != voice) {
        [_voice release];
        _voice = [voice retain];
    }
}
- (AVSpeechSynthesisVoice *)voice { return _voice; }

- (void)setRate:(float)rate { _rate = rate; }
- (float)rate { return _rate; }

- (void)setPitchMultiplier:(float)pitchMultiplier { _pitchMultiplier = pitchMultiplier; }
- (float)pitchMultiplier { return _pitchMultiplier; }

- (void)setVolume:(float)volume { _volume = volume; }
- (float)volume { return _volume; }

@end

@implementation AVSpeechSynthesisVoice

+ (instancetype)voiceWithLanguage:(NSString *)language {
    return [[[self alloc] initWithLanguage:language] autorelease];
}

+ (NSString *)currentLanguageCode {
    return @"en-US";
}

+ (NSArray *)speechVoices {
    return [NSArray array];
}

- (instancetype)initWithLanguage:(NSString *)language {
    self = [super init];
    if (self) {
        _language = [(language ?: @"en-US") copy];
    }
    return self;
}

- (void)dealloc {
    [_language release];
    [super dealloc];
}

- (NSString *)language { return _language; }
- (NSString *)name { return @"Darling Stub Voice"; }
- (NSString *)identifier { return @"com.darling.stub.voice"; }

@end

@implementation AVSpeechSynthesizer

- (void)setDelegate:(id)delegate { _delegate = delegate; }
- (id)delegate { return _delegate; }
- (BOOL)isSpeaking { return NO; }
- (BOOL)isPaused { return NO; }
- (BOOL)speakUtterance:(AVSpeechUtterance *)utterance { return NO; }
- (BOOL)stopSpeakingAtBoundary:(AVSpeechBoundary)boundary { return YES; }
- (BOOL)pauseSpeakingAtBoundary:(AVSpeechBoundary)boundary { return NO; }
- (BOOL)continueSpeaking { return NO; }

@end
