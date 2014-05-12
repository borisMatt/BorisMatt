//
//  DatabaseHelper.h
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

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface DatabaseHelper : NSObject
{
    sqlite3 *databaseReference;
}

- (id)init;

//Copies the database from the Project bundle to the document directory
- (BOOL)copyDatabaseFromBundletoDocumentDirectory;

// gets the location of the database present in the document directory
- (NSString*)documentDirectoryDatabaseLocation;

// creates the database instance
- (void)createDatabaseInstance;

// checks if any previous db connection is open before firing a new query
//and if the connection is open then closes it
- (void)closeanyOpenConnection;


// inserts the new employee record
- (BOOL)insertEmployeeRecordWithEmployeeName:(NSString*)empname andEmployeeDepartment:(NSString*)empdept andEmployeeImage:(UIImage*)empImage;

// gives you the employee name and employee image
- (NSMutableArray*)getAllEmployeeRecord;

// gets the employee record with all the employee details by empname
- (NSMutableArray*)getEmployeeDetailsByEmployeeName:(NSString*)empName;

// Delete the employee record and accepts the record ID as the parameter
- (BOOL)deleteEmployeeWithID:(NSString*)employeeRecordID;


@end
