//
//  ALSequentialBaseLabel.h
//  AnimationLabel
//
//  Created by WavingColor on 2017/12/5.
//  Copyright © 2017年 Hacky. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ALLayoutMaker.h"
#import "ZCEasingUtil.h"

typedef NS_ENUM(NSInteger, ALSequentialLabelAppearDirection)
{
    ALSequentialLabelAppearDirectionFromBottom,
    ALSequentialLabelAppearDirectionFromCenter,
    ALSequentialLabelAppearDirectionFromTop,
    ALSequentialLabelAppearDirectionFromTopLeft,
};

@interface ALSequentialBaseLabel : UIView

/**
 * time for one text attribute to do completion animation
 */
@property (nonatomic, assign) CGFloat animationDuration;


/**
 * start time offset for each group
 */
@property (nonatomic, assign) CGFloat animationDelay;

/**
 * duration for the label to finish animation on screen
 */
@property (nonatomic, readonly) CGFloat totoalAnimationDuration;

@property (nonatomic, readonly) CGFloat animationProgress;

/**
 * font, text, textColor, attributedString
 * similar to how it works in UILabel
 */
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, retain) UIColor *textColor;
@property (nonatomic, strong) NSAttributedString *attributedString;

/**
 * If YES, eash text info will be CALayer instead of redraw
 * default to NO
 */
@property (nonatomic, assign) BOOL layerBased;


/**
 * If NO, disappear animation will start with the head of string
 * default NO
 */
@property (nonatomic, assign) BOOL disappearTail;

/**
 * If set to YES, will use a new random background color for each redraw
 */
@property (nonatomic, assign) BOOL debugRedraw;

/**
 * If set to YES, will show bounds of each TextBlock
 */
@property (nonatomic, assign) BOOL debugTextInfoBounds;

/**
 * If set to NO, whole rect will be redrawn on each displayLink tick
 * default to YES
 */
@property (nonatomic, assign) BOOL onlyDrawDirtyArea;

/**
 * Appear direction only works in default implemention
 * add your own option in subclass implemention
 */
@property (nonatomic, assign) ALSequentialLabelAppearDirection appearDirection;
@property (nonatomic, readonly) ALLayoutMaker *layoutTool;

/**
 * animatingAppear = NO means it's in animate disappear mode
 */
@property (nonatomic, readonly) BOOL animatingAppear;


/**
 * preferedMaxLayoutWidth
 */

@property (nonatomic, assign) CGFloat preferredMaxLayoutWidth;


- (void) sizeToFit;

- (void) startAppearAnimation;

- (void) startDisappearAnimation;

- (void) stopAnimation;

- (void) revertAnimation;

- (void)animationWithTimestamp:(CFTimeInterval)timeInterval;

- (void)animationCompleteAction;

/**
 * One time init after the layout is done, use customValue to retain custom attributes
 */
- (void) textBlockAttributesInit: (ALTextInfo *) textInfo;


/**
 * Custom drawing methods for appear animation
 * Only used when layerBased is set to NO
 *
 * @param rect The area of redraw
 * @param textInfo The text block object needed to do custom drawing
 */
- (void) appearStateDrawingForRect: (CGRect) rect textInfo: (ALTextInfo *) textInfo;

- (void) disappearStateDrawingForRect: (CGRect) rect textInfo: (ALTextInfo *) textInfo;

/**
 * Override this to decide which part of the rect needs redraw,
 * Only used when layerBased is set to NO
 * @return custom area that should be redrawn
 */
- (CGRect) redrawAreaForRect: (CGRect) rect textInfo: (ALTextInfo *) textInfo;


/**
 * Custom changes to the layer of each TextBlock
 * Only used when layerBased is set to YES
 */
- (void) appearStateLayerChangesForTextInfo: (ALTextInfo *) textInfo;

- (void) disappearLayerStateChangesForTextInfo: (ALTextInfo *) textInfo;



@end
