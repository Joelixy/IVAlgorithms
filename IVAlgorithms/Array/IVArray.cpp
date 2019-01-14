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

#pragma mark 数组中出现超过一半的数字 累加法
int IVArray::overHalfNumInArray(int *a, int len) {
    if (a == nullptr || len < 1) {
        return -1;
    }
#warning  此处可检查数组的有效性 略写
    int target = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (count == 0) {
            target = a[i];
            count = 1;
        }else {
            if (a[i] == target) {
                count++;
            }else {
                count--;
            }
        }
    }
#warning  此处应检查是否超过一半 略写
    return target;
}

#pragma mark 无序数组中第K大的数（最大的K个数，最小的K个数）快速排序 小的在前，大的在后
int IVArray::numberOfMaxNumInArray(int *a, int len, int k) {
    if (a == nullptr || len < 1 || k < 1) {
        return 0;
    }
    int start = 0;
    int end = len-1;
    int index = firstK(a, start, end);
    
    while (index != len-k) {
        if (index > len-k) {
            end = index - 1;
            index = firstK(a, start, end);
        }else {
            start = index + 1;
            index = firstK(a, start, end);
        }
    }
    return a[index];
}

int IVArray::firstK(int *a, int start, int end) {
    
    int index = start+1;
    for (int i = index; i <= end; i++) {
        if (a[start] > a[i]) {
            if (i != index) {
                swap(a[i], a[index]);
            }
            ++index;
        }
    }
    --index;
    swap(a[index], a[start]);
    return index;
}

#pragma mark 有序数组中某个数出现的次数 二分法->双指针
int IVArray::countOfSortedArray(int *a, int len, int target) {
    if (a == nullptr || len < 1) {
        return 0;
    }
    int number = 0;
    int left = 0;
    int right = len-1;
    int mid = 0;
    while (left <= right) {
        mid = (right-left)/2 + left;
        if (a[mid] > target) {
            right = mid - 1;
        }else if (a[mid] < target) {
            left = mid + 1;
        }else {
            break;
        }
    }
    if (left > right) {
        return number;
    }
    left = right = mid;
    while (left >= 0 && a[left] == target) {
        --left;
    }
    ++left;
    while (right < len && a[right] == target) {
        ++right;
    }
    --right;
    number = right-left+1;
    
    return number;
}

#pragma mark 调整奇数位 位于偶数位前面 双指针 前后
void IVArray::ajustPosition(int *a, int len) {
    if (a == nullptr || len < 1) {
        return;
    }
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (a[left] % 2 == 0) {
            ++left;
        }else if (a[right] % 2 != 0) {
            --right;
        }else {
            swap(a[left], a[right]);
            ++left;
            --right;
        }
    }
}
