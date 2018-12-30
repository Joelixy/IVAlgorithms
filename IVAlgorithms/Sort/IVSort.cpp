//
//  IVSort.cpp
//  IVAlgorithms
//
//  Created by 李向阳 on 2018/12/30.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#include "IVSort.hpp"

/*
 * 严格来说 需要对数组长度和len进行匹配性校验，此处忽略
 * 默认len的长度都是在未溢出范围的
 *
 */


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

#pragma mark bubble sort / 冒泡排序
void IVSort::bubbleSort(int *a, int len) {
    if (a == nullptr || len < 1) {
        return;
    }
    
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1-i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
    printf("bubbleSort Start ===>>\n");
    for (int i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    printf("\nbubbleSort End <<===\n");
}

#pragma mark select sort / 选择排序
void IVSort::selectSort(int *a, int len) {
    if (a == nullptr || len < 1) {
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = i+1; j < len; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    printf("selectSort Start ===>>\n");
    for (int i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    printf("\nselectSort End <<===\n");
}

#pragma mark insert sort / 插入排序
void IVSort::insertSort(int *a, int len) {
    if (a == nullptr || len < 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j > 0; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
            }
        }
    }
    
    printf("insertSort Start ===>>\n");
    for (int i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    printf("\ninsertSort End <<===\n");
}

int quickSortImpCore(int *a, int start, int end) {
    int index = start + 1;
    // 默认选第一个作为基本值，大于基本值的放右边，小于基本值的放左边
    for (int i = index; i <= end; i++) {
        if (a[start] > a[i]) {
            if (index != i) {
                swap(a[index], a[i]);
            }
            ++index;
        }
    }
    --index;
    swap(a[start], a[index]);
    return index;
}

void quickSortImp(int *a, int start, int end) {
    if (start >= end) {
        return;
    }
    // 递归排序
    int index = quickSortImpCore(a, start, end);
    if (index > start) {
        end = index-1;
        quickSortImp(a, start, end);
    }
    if (index < end) {
        start = index+1;
        quickSortImp(a, start, end);
    }
}

#pragma mark quick sort / 快速排序
void IVSort::quickSort(int *a, int len) {
    if (a == nullptr || len < 1) {
        return;
    }
    quickSortImp(a, 0, len-1);
    
    printf("quickSort Start ===>>\n");
    for (int i = 0; i < len; i++) {
        printf("%d, ", a[i]);
    }
    printf("\nquickSort End <<===");
}


