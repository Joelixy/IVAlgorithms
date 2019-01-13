//
//  IVArray.cpp
//  IVAlgorithms
//
//  Created by Joelixy on 2019/1/13.
//  Copyright © 2019 JoeLixy. All rights reserved.
//

#include "IVArray.hpp"


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

#pragma mark 未排序 0-n长度内任意重复数字， 下标法
int IVArray::anyDuplicateNumFromUnsortArray(int *a, int len) {
    int target = -1;
    if (a == nullptr || len < 1) {
        return target;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] < 0 || a[i] > len - 1) {
            return target;
        }
    }
    
    for (int i = 0; i < len; i++) {
        while (a[i] != i) {
            if (a[i] != a[a[i]]) {
                swap(a[i], a[a[i]]);
            }else {
                target = a[i];
            }
        }
    }
    return target;
}

#pragma mark 递增序列
bool IVArray::twoDimensionArray(int *a, int row, int column, int target) {
    if (a == nullptr || row < 1 || column < 1) {
        return false;
    }
    int rowIndex = 0;
    int columnIndex = column-1;
    
    while (rowIndex < row && columnIndex >= 0) {
        int value = a[rowIndex * column + columnIndex];
        if (value < target) {
            rowIndex++;
        }else if (value > target) {
            columnIndex--;
        }else {
            return true;
        }
    }
    return false;
}

#pragma mark 旋转数组中的最小数字
int IVArray::minNumOfReverseArray(int *a, int len) {
    if (a == nullptr || len < 1) {
        return -1;
    }
    int left = 0;
    int right = len - 1;
    int mid = left;
    while (a[left] >= a[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
        mid = (left + right)/2;
        
        // 如果三个指向的数相等
        if (a[left] == a[right] && a[left] == a[mid]) {
            return minInOrder(a, left, right);
        }
        
        if (a[mid] >= a[left]) {
            left = mid;
        }else if (a[mid] <= a[right]) {
            right = mid;
        }
    }
    return a[mid];
}

int IVArray::minInOrder(int *a, int left, int right) {
    int result = a[left];
    for (int i = left + 1; i <= right; i++) {
        if (result > a[i]) {
            result = a[i];
        }
    }
    return result;
}
