//
//  AddEmpRecordVC.m
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

#import "AddEmpRecordVC.h"

@interface AddEmpRecordVC ()

@end

@implementation AddEmpRecordVC

@synthesize txtempdept;
@synthesize txtempName;
@synthesize empimgv;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    objDBHelper = [[DatabaseHelper alloc]init];
    self.title = @"Add Employee Record";
    [self addTapGestureToImageView];
}
- (void)addTapGestureToImageView
{
    UITapGestureRecognizer *tpGesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(showImageGallery:)];
    tpGesture.numberOfTapsRequired = 1;
    self.empimgv.userInteractionEnabled = YES;
    [self.empimgv addGestureRecognizer:tpGesture];
}

- (void)showImageGallery:(UIGestureRecognizer*)sender
{
    UIImagePickerController *objImagePicker = [[UIImagePickerController alloc]init];
    objImagePicker.allowsEditing = YES;
    objImagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    objImagePicker.delegate = self;
    [self presentViewController:objImagePicker animated:YES completion:nil];
}


- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

#pragma mark Image picker controller delegate
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    self.empimgv.image = [info valueForKey:@"UIImagePickerControllerOriginalImage"];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)showpopUp:(NSString*)popUpMessage
{
    UIAlertView *objalert = [[UIAlertView alloc]initWithTitle:@"Alert" message:popUpMessage delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [objalert show];
}

- (IBAction)insertEmpRecord:(id)sender
{
 
  if ([objDBHelper insertEmployeeRecordWithEmployeeName:txtempName.text andEmployeeDepartment:txtempdept.text andEmployeeImage:self.empimgv.image])
  {
      [self showpopUp:@"Record inserted Successfully"];
      [self clearControls:self];
  }
  else
  {
       [self showpopUp:@"Record insertion failed"];
  }
    
}
- (IBAction)clearControls:(id)sender
{
    self.txtempdept.text = @"";
    self.txtempName.text = @"";
    self.empimgv.image = [UIImage imageNamed:@"image1"];
}
- (IBAction)displayallEmployeeRecords:(id)sender
{
    EmployeeListTableVC *objempListVC = [[EmployeeListTableVC alloc]initWithStyle:UITableViewStyleGrouped];
    [self.navigationController pushViewController:objempListVC animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
