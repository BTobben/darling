#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal loader-only CoreML.framework ABI shims for Chromium/Electron.
 */

#define ML_COMPAT_EXPORT __attribute__((visibility("default")))

@interface MLCPUComputeDevice : NSObject
@end
@implementation MLCPUComputeDevice
@end

@interface MLGPUComputeDevice : NSObject
@end
@implementation MLGPUComputeDevice
@end

@interface MLNeuralEngineComputeDevice : NSObject
@end
@implementation MLNeuralEngineComputeDevice
@end

@interface MLComputePlan : NSObject
@end
@implementation MLComputePlan
@end

@interface MLModelConfiguration : NSObject {
    NSInteger _computeUnits;
    BOOL _allowLowPrecisionAccumulationOnGPU;
    id _parameters;
}
- (NSInteger)computeUnits;
- (void)setComputeUnits:(NSInteger)computeUnits;
- (BOOL)allowLowPrecisionAccumulationOnGPU;
- (void)setAllowLowPrecisionAccumulationOnGPU:(BOOL)value;
- (id)parameters;
- (void)setParameters:(id)parameters;
@end

@implementation MLModelConfiguration
- (NSInteger)computeUnits { return _computeUnits; }
- (void)setComputeUnits:(NSInteger)computeUnits { _computeUnits = computeUnits; }
- (BOOL)allowLowPrecisionAccumulationOnGPU { return _allowLowPrecisionAccumulationOnGPU; }
- (void)setAllowLowPrecisionAccumulationOnGPU:(BOOL)value { _allowLowPrecisionAccumulationOnGPU = value; }
- (id)parameters { return _parameters; }
- (void)setParameters:(id)parameters { _parameters = parameters; }
@end

@interface MLPredictionOptions : NSObject {
    BOOL _usesCPUOnly;
}
- (BOOL)usesCPUOnly;
- (void)setUsesCPUOnly:(BOOL)value;
@end

@implementation MLPredictionOptions
- (BOOL)usesCPUOnly { return _usesCPUOnly; }
- (void)setUsesCPUOnly:(BOOL)value { _usesCPUOnly = value; }
@end

@interface MLModel : NSObject
+ (id)modelWithContentsOfURL:(id)url error:(id *)error;
+ (id)modelWithContentsOfURL:(id)url configuration:(id)configuration error:(id *)error;
+ (id)compileModelAtURL:(id)url error:(id *)error;
- (id)modelDescription;
- (id)configuration;
- (id)predictionFromFeatures:(id)input error:(id *)error;
- (id)predictionFromFeatures:(id)input options:(id)options error:(id *)error;
- (id)predictionsFromBatch:(id)inputBatch error:(id *)error;
- (id)predictionsFromBatch:(id)inputBatch options:(id)options error:(id *)error;
- (id)parameterValueForKey:(id)key error:(id *)error;
@end

@implementation MLModel
+ (id)modelWithContentsOfURL:(id)url error:(id *)error {
    if (error) *error = nil;
    return nil;
}
+ (id)modelWithContentsOfURL:(id)url configuration:(id)configuration error:(id *)error {
    if (error) *error = nil;
    return nil;
}
+ (id)compileModelAtURL:(id)url error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (id)modelDescription { return nil; }
- (id)configuration { return nil; }
- (id)predictionFromFeatures:(id)input error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (id)predictionFromFeatures:(id)input options:(id)options error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (id)predictionsFromBatch:(id)inputBatch error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (id)predictionsFromBatch:(id)inputBatch options:(id)options error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (id)parameterValueForKey:(id)key error:(id *)error {
    if (error) *error = nil;
    return nil;
}
@end

@interface MLFeatureValue : NSObject
+ (id)featureValueWithString:(id)value;
+ (id)featureValueWithInt64:(long long)value;
+ (id)featureValueWithDouble:(double)value;
+ (id)featureValueWithMultiArray:(id)value;
+ (id)featureValueWithDictionary:(id)value error:(id *)error;
- (NSInteger)type;
- (BOOL)isUndefined;
- (id)stringValue;
- (long long)int64Value;
- (double)doubleValue;
- (id)multiArrayValue;
- (id)dictionaryValue;
- (void *)imageBufferValue;
@end

@implementation MLFeatureValue
+ (id)featureValueWithString:(id)value { return nil; }
+ (id)featureValueWithInt64:(long long)value { return nil; }
+ (id)featureValueWithDouble:(double)value { return nil; }
+ (id)featureValueWithMultiArray:(id)value { return nil; }
+ (id)featureValueWithDictionary:(id)value error:(id *)error {
    if (error) *error = nil;
    return nil;
}
- (NSInteger)type { return 0; }
- (BOOL)isUndefined { return NO; }
- (id)stringValue { return nil; }
- (long long)int64Value { return 0; }
- (double)doubleValue { return 0.0; }
- (id)multiArrayValue { return nil; }
- (id)dictionaryValue { return nil; }
- (void *)imageBufferValue { return 0; }
@end

@interface MLMultiArray : NSObject
- (id)initWithShape:(id)shape dataType:(NSInteger)dataType error:(id *)error;
- (id)shape;
- (NSInteger)dataType;
- (NSInteger)count;
- (void *)dataPointer;
- (id)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
@end

@implementation MLMultiArray
- (id)initWithShape:(id)shape dataType:(NSInteger)dataType error:(id *)error {
    if (error) *error = nil;
    return self;
}
- (id)shape { return nil; }
- (NSInteger)dataType { return 0; }
- (NSInteger)count { return 0; }
- (void *)dataPointer { return 0; }
- (id)objectAtIndexedSubscript:(NSUInteger)idx { return nil; }
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx {}
@end
