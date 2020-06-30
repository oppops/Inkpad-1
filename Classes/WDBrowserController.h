//
//  WDBrowserController.h
//  Inkpad
//
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
//  Copyright (c) 2011-2013 Steve Sprang
//  Copyright (c) 2020 Ben Burton
//

#import <UIKit/UIKit.h>
#import <MessageUI/MFMailComposeViewController.h>
#import "OCADownloader.h"
#import "WDHelpController.h"
#if 0 // bab: no dropbox
#import "WDImportController.h"
#endif
#import "WDSamplesController.h"

@class WDActivityManager;
@class WDDocument;
@class WDDrawing;
@class WDFontLibraryController;
@class WDPageSizeController;
@class WDThumbnailView;

@class DBRestClient;
@class WDActivityController;
@class WDBlockingView;
@class WDExportController;
@class OCAViewController;

@interface WDBrowserController : UICollectionViewController <UIActionSheetDelegate,
                                                             UIPopoverControllerDelegate,
#if 0 // bab: no dropbox
                                                             DBRestClientDelegate,
#endif
                                                             MFMailComposeViewControllerDelegate,
#if 0 // bab: no dropbox
                                                             WDImportControllerDelegate,
#endif
                                                             WDSamplesControllerDelegate,
                                                             UINavigationControllerDelegate,
                                                             UIImagePickerControllerDelegate,
                                                             OCADownloaderDelegate>
{
    NSMutableArray          *toolbarItems_;
    UIBarButtonItem         *emailItem_;
    UIBarButtonItem         *dropboxExportItem_;
    UIActivityIndicatorView *activityIndicator_;
    UIBarButtonItem         *activityItem_;
    UIBarButtonItem         *deleteItem_;
    UIActionSheet           *deleteSheet_;
    
    NSMutableSet            *selectedDrawings_;
    
    UIPopoverController     *popoverController_;
    WDPageSizeController    *pageSizeController_;
    WDExportController      *exportController_;
#if 0 // bab: no dropbox
	WDImportController		*importController_;
#endif
    UIImagePickerController *pickerController_;
    WDFontLibraryController *fontLibraryController_;
    WDSamplesController     *samplesController_;
    WDActivityController    *activityController_;
    OCAViewController       *openClipArtController_;
    
    DBRestClient            *restClient_;
    NSMutableSet            *filesBeingUploaded_;
    WDActivityManager       *activities_;

    WDBlockingView          *blockingView_;
    WDThumbnailView         *editingThumbnail_;
    
    BOOL                    everLoaded_;
    
    NSMutableSet            *downloaders_; // for downloading open clip art
}

- (void) startEditingDrawing:(WDDocument *)drawing;

@end
