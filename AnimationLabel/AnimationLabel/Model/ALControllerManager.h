//
//  ALControllerManager.h
//  AnimationLabel
//
//  Created by QD-ZC on 2017/12/1.
//  Copyright © 2017年 Hacky. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface ALControllerManager : NSObject

+ (instancetype)sharedInstance;

- (void)controller:(UIViewController *)controller pushto:(NSString *)title;

@end
