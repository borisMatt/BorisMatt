//
//  AddEmpRecordVC.h
//  DatabaseDemo
//
/*
 
 BKSegmentedViewControllers
 
 The MIT License (MIT)
 
 Copyright (c) 2014 Bhavya Kothari
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */


#import <UIKit/UIKit.h>
#import "DatabaseHelper.h"
#import "EmployeeListTableVC.h"

@interface AddEmpRecordVC : UIViewController <UIImagePickerControllerDelegate,UINavigationControllerDelegate,UITextFieldDelegate>
{
    DatabaseHelper *objDBHelper;
}


@property (nonatomic,strong) IBOutlet UITextField *txtempName;
@property (nonatomic,strong) IBOutlet UITextField *txtempdept;
@property (nonatomic,strong) IBOutlet UIImageView *empimgv;

// adds the tap gesture to the image view
- (void)addTapGestureToImageView;

// displays the ios gallery
- (void)showImageGallery:(UIGestureRecognizer*)sender;

// displays the simple alert pop up
- (void)showpopUp:(NSString*)popUpMessage;

// calls the insert query to insert record in sqlite DB
- (IBAction)insertEmpRecord:(id)sender;

// clears the UI control
- (IBAction)clearControls:(id)sender;

// fetches all the records from the database and displays them in table view
- (IBAction)displayallEmployeeRecords:(id)sender;


@end
