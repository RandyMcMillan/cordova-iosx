//  Created by Jesse MacFadyen on 10-05-29.
//  Copyright 2010 Nitobi. All rights reserved.
//
//  ___FILEBASENAME___ Template Created Jan 7 2013
//  Copyright 2013 @RandyMcMillan

//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___ORGANIZATIONNAME___ ___YEAR___. All rights reserved.

#import <Cocoa/Cocoa.h>
#import <Cordova/CDVViewController.h>
#import <Cordova/CDVCommandDelegateImpl.h>
#import <Cordova/CDVCommandQueue.h>

@protocol ___FILEBASENAME___Delegate <NSObject>

/*
 *  onChildLocationChanging:newLoc
 *
 *  Discussion:
 *    Invoked when a new page has loaded
 */
- (void)onChildLocationChange:(NSString *)newLoc;
- (void)onOpenInSafari;
- (void)onClose;

@end

@protocol CDVOrientationDelegate <NSObject>

- (NSUInteger)supportedInterfaceOrientations;
//- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (BOOL)shouldAutorotate;

@end

//@interface ___FILEBASENAME___ViewController : CDVViewController <UIWebViewDelegate>{}
@interface ___FILEBASENAME___ViewController : CDVViewController{}

@property (nonatomic, strong) IBOutlet WebView				*webView;
@property (nonatomic, strong) IBOutlet NSButton			*closeBtn;
@property (nonatomic, strong) IBOutlet NSButton			*refreshBtn;
@property (nonatomic, strong) IBOutlet NSTextField		*addressLabel;
@property (nonatomic, strong) IBOutlet NSButton			*backBtn;
@property (nonatomic, strong) IBOutlet NSButton			*fwdBtn;
@property (nonatomic, strong) IBOutlet NSButton			*safariBtn;
//@property (nonatomic, strong) IBOutlet UIActivityIndicatorView	*spinner;

// unsafe_unretained is equivalent to assign - used to prevent retain cycles in the two properties below
@property (nonatomic, unsafe_unretained) id <___FILEBASENAME___Delegate>	delegate;
@property (nonatomic, unsafe_unretained) id									orientationDelegate;

@property (copy) NSString	*imageURL;
@property (assign) BOOL		isImage;
@property (assign) BOOL		scaleEnabled;

- (___FILEBASENAME___ViewController *)initWithScale:(BOOL)enabled;
- (IBAction)onDoneButtonPress:(id)sender;
- (IBAction)onSafariButtonPress:(id)sender;
- (void)loadURL:(NSString *)url;
- (void)closeBrowser;

@end
