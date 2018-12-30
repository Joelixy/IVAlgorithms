//
//  ViewController.m
//  IVAlgorithms
//
//  Created by 李向阳 on 2018/12/29.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#import "ViewController.h"
#import "IVSort.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self interview_sort];
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

@end
