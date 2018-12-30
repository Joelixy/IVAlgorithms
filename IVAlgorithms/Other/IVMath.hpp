//
//  IVMath.hpp
//  IVAlgorithms
//
//  Created by 李向阳 on 2018/12/30.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#ifndef IVMath_hpp
#define IVMath_hpp

#include <stdio.h>

class IVMath {
public:
    static void fibonacciSequence(unsigned n);  // 斐波那契数列
    static int countOfPrime(unsigned n);        // n以内的质数
    static bool isUgly(int n);                  // 丑数判断
    static bool isPower(int n);                 // 幂
    static boo binarySearch(int *a, int target);// 二分查找
};

#endif /* IVMath_hpp */
