#import <Foundation/Foundation.h>

/*
 * Temporary Darling/Codex experiment.
 * Add only symbols missing from Darling's existing AuthenticationServices.
 * Do not redefine existing classes such as ASAuthorizationController.
 */

NSString * const ASAuthorizationErrorDomain
    __attribute__((visibility("default"))) =
    @"ASAuthorizationErrorDomain";

NSString * const ASAuthorizationPublicKeyCredentialAttestationKindNone
    __attribute__((visibility("default"))) =
    @"none";

NSString * const ASAuthorizationPublicKeyCredentialUserVerificationPreferenceDiscouraged
    __attribute__((visibility("default"))) =
    @"discouraged";

NSString * const ASAuthorizationPublicKeyCredentialUserVerificationPreferencePreferred
    __attribute__((visibility("default"))) =
    @"preferred";

NSString * const ASAuthorizationPublicKeyCredentialUserVerificationPreferenceRequired
    __attribute__((visibility("default"))) =
    @"required";

NSString * const ASWebAuthenticationSessionErrorDomain
    __attribute__((visibility("default"))) =
    @"ASWebAuthenticationSessionErrorDomain";


@interface ASAuthorizationPublicKeyCredentialLargeBlobAssertionInput : NSObject
@end
@implementation ASAuthorizationPublicKeyCredentialLargeBlobAssertionInput
@end

@interface ASAuthorizationPublicKeyCredentialLargeBlobRegistrationInput : NSObject
@end
@implementation ASAuthorizationPublicKeyCredentialLargeBlobRegistrationInput
@end

@interface ASAuthorizationPublicKeyCredentialPRFAssertionInput : NSObject
@end
@implementation ASAuthorizationPublicKeyCredentialPRFAssertionInput
@end

@interface ASAuthorizationPublicKeyCredentialPRFAssertionInputValues : NSObject
@end
@implementation ASAuthorizationPublicKeyCredentialPRFAssertionInputValues
@end

@interface ASAuthorizationPublicKeyCredentialPRFRegistrationInput : NSObject
@end
@implementation ASAuthorizationPublicKeyCredentialPRFRegistrationInput
@end

@interface ASAuthorizationWebBrowserPublicKeyCredentialManager : NSObject
+ (instancetype)sharedManager;
@end
@implementation ASAuthorizationWebBrowserPublicKeyCredentialManager
+ (instancetype)sharedManager {
    static ASAuthorizationWebBrowserPublicKeyCredentialManager *manager = nil;
    if (!manager) {
        manager = [[self alloc] init];
    }
    return manager;
}
@end
