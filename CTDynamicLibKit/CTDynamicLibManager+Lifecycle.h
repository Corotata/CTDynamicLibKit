//
//  CTDynamicLibManager+Lifecycle.h
//  CTDynamicLibKit
//
//  Created by casa on 6/30/15.
//  Copyright (c) 2015 casa. All rights reserved.
//

#import "CTDynamicLibManager.h"

@protocol CTDynamicLibManagerLifeCycleDataSource;
@protocol CTDynamicLibManagerLifeCycleDelegate;

@interface CTDynamicLibManager (Lifecycle)

@property (nonatomic, assign) id<CTDynamicLibManagerLifeCycleDataSource> lifeCycleDataSource;
@property (nonatomic, assign) id<CTDynamicLibManagerLifeCycleDelegate> lifeCycleDelegate;

- (void)loadDefaultDynamicLibs;

// path of downloaded and extracted framework, but has not moved from temp yet.
- (void)updateDynamicLibWithTmpPath:(NSString *)path;

@end

@protocol CTDynamicLibManagerLifeCycleDataSource <NSObject>

// return array of core dynamic libraries' file name. such as "CoreView.framework", just give the name "CoreView" will do.
- (NSArray *)coreDynamicLibsForDynamicLibMananger:(CTDynamicLibManager *)dynamicLibMananger;

@end

@protocol CTDynamicLibManagerLifeCycleDelegate <NSObject>

- (void)dynamicLibMananger:(CTDynamicLibManager *)dynamicLibMananger didSuccessedLoadBundle:(NSBundle *)bundle;
- (void)dynamicLibMananger:(CTDynamicLibManager *)dynamicLibMananger didFailedLoadBundle:(NSBundle *)bundle;

@end