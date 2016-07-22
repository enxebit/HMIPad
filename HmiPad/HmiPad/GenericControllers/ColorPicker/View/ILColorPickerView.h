//
//  ILColorPicker.h
//  ILColorPickerExample
//
//  Created by Jon Gilkison on 9/2/11.
//  Copyright 2011 Interfacelab LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILSaturationBrightnessPickerView.h"
#import "ILHuePickerView.h"
#import "ILAlphaPickerView.h"

/**
 * Determines the layout of the color picker
 */
typedef enum {
    
    /// Hue picker is at bottom
    ILColorPickerViewLayoutBottom  =   0,
    
    // Hue picker is at right
    ILColorPickerViewLayoutRight   =   1,
    
} ILColorPickerViewLayout;

@class ILColorPickerView;

/**
 * Delegate for the color picker
 */
@protocol ILColorPickerViewDelegate

/**
 * Called when the user has chosen a new color
 *
 * @param color The new color
 * @param picker The calling picker
 */
- (void)colorPicked:(UIColor *)color forPicker:(ILColorPickerView *)picker pickingFinished:(BOOL)flag;
@end

/**
 * Wraps an ILSaturationBrightnessPicker and ILHuePicker into a single
 * convenient control
 */
@interface ILColorPickerView : ILView<ILSaturationBrightnessPickerViewDelegate, ILAlphaPickerViewDelegate> 
{    
    ILSaturationBrightnessPickerView *_satPicker;
    ILHuePickerView *_huePicker;
    ILAlphaPickerView *_alphaPicker;
}

/**
 * Delegate
 */
@property (weak,nonatomic) IBOutlet id<ILColorPickerViewDelegate> delegate;

/**
 * The layout of the controls
 */
@property (assign,nonatomic) ILColorPickerViewLayout pickerLayout;

/**
 * Gets/sets the current color
 */
@property (strong,nonatomic) UIColor *color;

@end
