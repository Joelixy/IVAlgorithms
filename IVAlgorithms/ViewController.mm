//
//  ViewController.m
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/29.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#import "ViewController.h"
#import "IVSort.hpp"
#import "IVMath.hpp"
#import "IVString.hpp"

#import "IVArray.hpp"
//#import "IVTree.hpp"
//#import "IVLinkList.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self interview_sort];
    [self interview_math];
    
    [self interview_string];
    
    [self interview_array];
}

- (void)interview_sort {
    int a[] = {6, 4, 3, 1, 2, 0, 5};
    
    IVSort sort;
//    IVSort *sort = new IVSort; // malloc from heap
    sort.bubbleSort(a, 7);
    sort.selectSort(a, 7);
    sort.insertSort(a, 7);
    sort.quickSort(a, 7);
    
}

- (void)interview_math {
    IVMath math;
    long sum = math.fibonacciSequence(5);
    int primeCount = math.countOfPrime(10);
    int a[] = {6, 4, 3, 1, 2, 0, 5};
    bool isExist = math.binarySearch(a, 7, 1);
    bool isUgly = math.isUgly(7);
    bool isPower = math.isPower(8);
}

- (void)interview_string {
    IVString string;
    char str[15] = "www/google/com";
    string.reverseString(str);
    
    char replaceStr[15] = "www.google.com";
    char withStr[6] = "/////";
    string.replaceString(replaceStr, '.', withStr);
    
    char numStr[6] = " -352";
    int number = string.convertStringToNumber(numStr);
    NSLog(@"number:%d", number);
}

- (void)interview_array {
    int array1[9] = {8, 5, 7, 2, 5, 3, 1, 4, 6};
    int duplicate = IVArray::anyDuplicateNumFromUnsortArray(array1, 9);
    
    int twoDimension[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    bool isExits = IVArray::twoDimensionArray(*twoDimension, 4, 4, 16);
    
    int minArray[8] = {6, 7, 8, 9, 2, 3, 4, 5}; // 特殊情况 {1, 3, 4, 5, 1, 1};
    int minNum = IVArray::minNumOfReverseArray(minArray, 8);
    
    int array2[10] = {1, 2, 2, 2, 2, 3, 3, 2, 4, 4};
    int value = IVArray::overHalfNumInArray(array2, 10);
    
    int array3[9] = {5, 6, 2, 8, 3, 4, 7, 9, 1};
    int firstKNumber = IVArray::numberOfMaxNumInArray(array3, 9, 5);
    
    int array4[12] = {2, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8, 9};
    int count = IVArray::countOfSortedArray(array4, 12, 5);
    
    int array5[9] = {1, 8, 9, 0, 3, 5, 6, 4, 7};
    IVArray::ajustPosition(array5, 9);
}

- (void)interview_linkList {
    
}

- (void)interview_tree {
    
}

@end
