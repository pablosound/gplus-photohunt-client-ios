/*
 *
 * Copyright 2013 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//  HomeViewController.h
//  PhotoHunt

#import "FSHPhotos.h"
#import "FSHProfile.h"
#import "GAITrackedViewController.h"
#import <GooglePlus/GooglePlus.h>
#import "MenuSource.h"
#import <MessageUI/MessageUI.h>
#import "PhotoCardView.h"
#import "TakePhotoView.h"
#import "ThemeManager.h"
#import <UIKit/UIKit.h>
#import "UserManager.h"
#import "StreamSource.h"

// The main view controller mediates most of the interaction between the user
// and PhotoHunt - it displays the stream of photos, provides interaction
// for the user and maintains state.
@interface HomeViewController : GAITrackedViewController <
GPPDeepLinkDelegate,
GPPShareDelegate,
MFMailComposeViewControllerDelegate,
MenuSourceDelegate,
PhotoCardViewDelegate,
StreamSourceDelegate,
TakePhotoViewDelegate,
ThemeManagerDelegate,
UIActionSheetDelegate,
UIAlertViewDelegate,
UIImagePickerControllerDelegate,
UIImagePickerControllerDelegate,
UINavigationControllerDelegate,
UIPickerViewDataSource,
UIPickerViewDelegate,
UserManagerDelegate> {
}

// Controller state.
@property (nonatomic, strong) ThemeManager *themeManager;
@property (nonatomic, strong) FSHPhotos *curThemeImages;
@property (nonatomic, strong) FSHPhotos *curThemeImagesAllUsers;
@property (nonatomic, strong) FSHTheme *curTheme;
@property (nonatomic, strong) FSHProfile *curUser;
@property (nonatomic, assign) BOOL canTake;
@property (nonatomic, assign) NSInteger loadOps;

// UI components.
@property (nonatomic, strong) IBOutlet UITableView *table;
@property (nonatomic, strong) IBOutlet UITableView *menu;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *spinner;
@property (nonatomic, strong) IBOutlet UILabel *updateMessage;

// Parameters from deeplinking
@property (nonatomic, copy) NSString *deepLinkPhotoID;
@property (nonatomic, copy) NSString *deepLinkVerb;

// Signal that the application has come to the foreground, allows signalling
// an update should occur.
- (void)comeToForeground;

@end
