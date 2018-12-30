//
//  IVMath.cpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/30.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#include "IVMath.hpp"






 // 斐波那契数列
long long IVMath::fibonacciSequence(unsigned n) {
    int result[] = {0, 1};
    if (n < 2) {
        return result[n];
    }
    long long firstValue = 0;
    long long secondValue = 1;
    long long sum = 0;
    for (int i = 2; i < n; i++) { // n以内的自然数
        sum = firstValue + secondValue;
        firstValue = secondValue;
        secondValue = sum;
    }
    return sum;
}

bool isPrime(unsigned n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// n以内的质数
int IVMath::countOfPrime(unsigned n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

// 丑数判断 只能被 2、3和5整除的数 1是特殊的丑数
bool IVMath::isUgly(int n) {
    if (n >= 1) {
        while (n % 2 == 0) {
            n = n / 2;
        }
        while (n % 3 == 0) {
            n = n / 3;
        }
        while (n % 5 == 0) {
            n = n / 5;
        }
        if (n == 1) {
            return true;
        }
    }
    return false;
}

//10，11， 100，110


// 幂 是否是2的幂
bool IVMath::isPower(int n) {
    if (n > 0) {
        int value = n;
        while ((value & 1) == 0) {
            value = value >> 1;
        }
        if (value == 1) {
            return true;
        }
    }
    return false;
}



#pragma mark BinarySearch 二分查找
bool IVMath::binarySearch(int *a, int len, int target) {

    if (a != nullptr && len > 0) {
        int start = 0;
        int end = len - 1;
        while (start < end) {
            int mid = (start + end)/2;
            if (a[mid] > target) {
                end = mid-1;
            }else if (a[mid] < target) {
                start = mid + 1;
            }else {
                return true;
            }
        }
    }
    
    return false;
}
