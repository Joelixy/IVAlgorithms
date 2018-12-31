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

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self interview_sort];
    [self interview_math];
    
    [self interview_string];
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

@end
