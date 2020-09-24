//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Licensed under the MIT License.
//

#import <UIKit/UIKit.h>

@class UITraitCollection, DMEnvironmentConfiguration;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DMUserInterfaceStyle) {
  DMUserInterfaceStyleUnspecified,
  DMUserInterfaceStyleLight,
  DMUserInterfaceStyleDark,
};

@interface DMTraitCollection : NSObject

@property (class, nonatomic, readonly) DMTraitCollection *currentTraitCollection API_DEPRECATED("Use overrideTraitCollection instead.", ios(9.0, 11.0));
@property (class, nonatomic, readonly) DMTraitCollection *overrideTraitCollection;

+ (DMTraitCollection *)traitCollectionWithUserInterfaceStyle:(DMUserInterfaceStyle)userInterfaceStyle;
+ (DMTraitCollection *)traitCollectionWithUITraitCollection:(UITraitCollection *)traitCollection API_AVAILABLE(ios(13.0));

@property (nonatomic, readonly) DMUserInterfaceStyle userInterfaceStyle;
@property (nonatomic, readonly) UITraitCollection *uiTraitCollection API_AVAILABLE(ios(13.0));

- (instancetype)init NS_DESIGNATED_INITIALIZER;

+ (void)setOverrideTraitCollection:(DMTraitCollection *)overrideTraitCollection animated:(BOOL)animated;

// MARK: - Observer Registration
+ (void)registerWithApplication:(UIApplication *)application syncImmediately:(BOOL)syncImmediately animated:(BOOL)animated;
+ (void)registerWithViewController:(UIViewController *)viewController syncImmediately:(BOOL)syncImmediately animated:(BOOL)animated;
+ (void)unregister;

// MARK: - Setup
// TODO: Move to private header
+ (void)setupEnvironmentWithConfiguration:(DMEnvironmentConfiguration *)configuration;

@end

#pragma mark - DMTraitEnvironment

@protocol DMTraitEnvironment <NSObject>

@property (readonly) DMTraitCollection *dmTraitCollection;

- (void)dmTraitCollectionDidChange:(nullable DMTraitCollection *)previousTraitCollection;

@end

NS_ASSUME_NONNULL_END
