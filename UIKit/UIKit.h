#import "../Types.h"
#import "Types.h"

UIEdgeInsets UIEdgeInsetsFromString(NSString *str);

UIOffset UIOffsetFromString(NSString *str);

NSData* UIImagePNGRepresentation(UIImage* image);
NSData* UIImageJPEGRepresentation(UIImage* image, CGFloat compressionQuality);

UIImage* UIGraphicsGetImageFromCurrentImageContext(void);

CGRect UIRectCenteredAboutPoint(CGRect, CGPoint, CGFloat, CGFloat);
CGRect UIRectCenteredAboutPointScale(CGRect, CGPoint);
CGRect UIRectInset(CGRect, CGFloat, CGFloat, CGFloat, CGFloat);
CGRect CGRectFromString(NSString *str);

CGSize CGSizeFromString(NSString *str);

CGPoint UIRectGetCenter(CGRect rect);
CGPoint CGPointFromString(NSString *str);

CGFloat UIRoundToScale(CGFloat, CGFloat);
CGFloat UIFloorToScale(CGFloat, CGFloat);
CGFloat UICeilToScale(CGFloat, CGFloat);
CGFloat UIFloorToViewScale(CGFloat);
CGFloat UIRoundToViewScale(CGFloat);
CGFloat UICeilToViewScale(CGFloat);
CGFloat UIFloorToScreenScale(CGFloat);
CGFloat UIRoundToScreenScale(CGFloat);
CGFloat UICeilToScreenScale(CGFloat);
CGFloat UIAnimationDragCoefficient(void);

CGAffineTransform UIIntegralTransform(CGAffineTransform t);

CGContextRef UIGraphicsGetCurrentContext(void);

void UIRectFill(CGRect rect);
void UIRectFillUsingBlendMode(CGRect rect, CGBlendMode blendMode);
void UIRectClip(CGRect rect);
void UIGraphicsPushContext(CGContextRef context);
void UIGraphicsPopContext(void);
void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale);
void UIGraphicsBeginImageContext(CGSize size);
void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale);
void UIGraphicsEndImageContext(void);
void _UIApplicationLoadWebKit(void);

int UIApplicationMain(int argc, char** argv, NSString* principalClassName, NSString* delegateClassName);

BOOL _UIApplicationIsExtension(void);
BOOL _UIApplicationUsesLegacyUI(void);
BOOL UIContentSizeCategoryIsAccessibilityCategory(UIContentSizeCategory category);

bool UIRectIsDiscrete(CGRect rect);
bool __UIApplicationLinkedOnOrAfter(NSInteger);
