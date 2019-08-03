#import "../Types.h"
#import "Types.h"

bool SecTrustSetExceptions(SecTrustRef trust, CFDataRef exceptions);

CFTypeID SecTrustGetTypeID(void);
CFTypeID SecCertificateGetTypeID(void);
CFTypeID SecAccessControlGetTypeID(void);

CFStringRef SecCopyErrorMessageString(OSStatus status, void *reserved);
CFStringRef SecCertificateCopySubjectSummary(SecCertificateRef certificate);

CFAbsoluteTime SecTrustGetVerifyTime(SecTrustRef trust);

CFIndex SecTrustGetCertificateCount(SecTrustRef trust);

CFDataRef SecTrustCopyExceptions(SecTrustRef trust);
CFDataRef SecCertificateCopyData(SecCertificateRef certificate);
CFDataRef SecCertificateCopyNormalizedIssuerSequence(SecCertificateRef certificate);
CFDataRef SecCertificateCopyNormalizedSubjectSequence(SecCertificateRef certificate);
CFDataRef SecCertificateCopySerialNumberData(SecCertificateRef certificate, CFErrorRef *error);
CFDataRef SecCertificateCopySerialNumber(SecCertificateRef certificate);
CFDataRef SecCertificateCopySerialNumber(SecCertificateRef certificate, CFErrorRef *error);

CFArrayRef SecTrustCopyProperties(SecTrustRef trust);

CFDictionaryRef SecTrustCopyResult(SecTrustRef trust);

OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType *result);
OSStatus SecTrustEvaluateAsync(SecTrustRef trust, dispatch_queue_t queue, SecTrustCallback result);
OSStatus SecTrustEvaluateWithError(SecTrustRef trust, CFErrorRef *error);
OSStatus SecTrustCreateWithCertificates(CFTypeRef certificates, CFTypeRef policies, SecTrustRef *trust);
OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies);
OSStatus SecTrustCopyPolicies(SecTrustRef trust, CFArrayRef *policies);
OSStatus SecTrustSetNetworkFetchAllowed(SecTrustRef trust, Boolean allowFetch);
OSStatus SecTrustGetNetworkFetchAllowed(SecTrustRef trust, Boolean *allowFetch);
OSStatus SecTrustSetAnchorCertificates(SecTrustRef trust, CFArrayRef anchorCertificates);
OSStatus SecTrustSetAnchorCertificatesOnly(SecTrustRef trust, Boolean anchorCertificatesOnly);
OSStatus SecTrustCopyCustomAnchorCertificates(SecTrustRef trust, CFArrayRef *anchors);
OSStatus SecTrustSetVerifyDate(SecTrustRef trust, CFDateRef verifyDate);
OSStatus SecTrustGetTrustResult(SecTrustRef trust, SecTrustResultType *result);
OSStatus SecTrustSetOCSPResponse(SecTrustRef trust, CFTypeRef responseData);
OSStatus SecTrustSetSignedCertificateTimestamps(SecTrustRef trust, CFArrayRef sctArray);
OSStatus SecTrustSetOptions(SecTrustRef trustRef, SecTrustOptionFlags options);
OSStatus SecTrustSetParameters(SecTrustRef trustRef, CSSM_TP_ACTION action, CFDataRef actionData);
OSStatus SecTrustSetKeychains(SecTrustRef trust, CFTypeRef keychainOrArray);
OSStatus SecTrustGetResult(SecTrustRef trustRef, SecTrustResultType *result, CFArrayRef *certChain, CSSM_TP_APPLE_EVIDENCE_INFO **statusChain);
OSStatus SecTrustGetCssmResult(SecTrustRef trust, CSSM_TP_VERIFY_CONTEXT_RESULT_PTR *result);
OSStatus SecTrustGetCssmResultCode(SecTrustRef trust, OSStatus *resultCode);
OSStatus SecTrustGetTPHandle(SecTrustRef trust, CSSM_TP_HANDLE *handle);
OSStatus SecTrustCopyAnchorCertificates(CFArrayRef *anchors);
OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef *result);
OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef *result);
OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate);
OSStatus SecItemDelete(CFDictionaryRef query);
OSStatus SecCertificateCopyCommonName(SecCertificateRef certificate, CFStringRef *commonName);
OSStatus SecCertificateCopyEmailAddresses(SecCertificateRef certificate, CFArrayRef *emailAddresses);
OSStatus SecCertificateCopyPublicKey(SecCertificateRef certificate, SecKeyRef *key);
OSStatus SecCertificateAddToKeychain(SecCertificateRef certificate, SecKeychainRef keychain);
OSStatus SecCertificateGetData(SecCertificateRef certificate, CSSM_DATA_PTR data);

SecKeyRef SecTrustCopyPublicKey(SecTrustRef trust);
SecKeyRef SecCertificateCopyKey(SecCertificateRef certificate);
SecKeyRef SecCertificateCopyPublicKey(SecCertificateRef certificate);

SecCertificateRef SecTrustGetCertificateAtIndex(SecTrustRef trust, CFIndex ix);
SecCertificateRef SecCertificateCreateWithData(CFAllocatorRef allocator, CFDataRef data);

SecAccessControlRef SecAccessControlCreateWithFlags(CFAllocatorRef allocator, CFTypeRef protection, SecAccessControlCreateFlags flags, CFErrorRef *error);
