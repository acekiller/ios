//
//  App.h
//  iphone-photopay
//
//  Created by Ja on 11/2/11.
//  Copyright (c) 2011 jcerovec@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Define your macros for accessing localization tables.
 * If you don't have your definitions, our tables will be used 
 * based on [[PPApp instance] language] property
 */

#ifndef _
    #define _(s) NSLocalizedStringFromTable(s,[PPApp instance].language,s)
#endif

#ifndef __
    #define __(s,...) [NSString stringWithFormat:NSLocalizedStringFromTable(s,[PPApp instance].language,s),##__VA_ARGS__]
#endif

/*
 *  System Versioning Preprocessor Macros
 */

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


@interface PPApp : NSObject

@property (nonatomic, copy, setter=setLanguage:) NSString* language;
@property (nonatomic, assign) double animationDuration;

+ (PPApp *)instance;

- (id)init;

- (void)setLanguage:(NSString *)inLanguage;

- (void)setDefaultLanguage;

- (void)pushStatusBarStyle:(UIStatusBarStyle)statusBarStyle;

- (void)popStatusBarStyle;

/** Sets the key that the help was shown to true */
- (void)setHelpShown:(BOOL)value;

/** Returns true if the help was already shown */
- (BOOL)isHelpShown;

@end
