//
//  IVArray.hpp
//  IVAlgorithms
//
//  Created by Joelixy on 2019/1/13.
//  Copyright © 2019 JoeLixy. All rights reserved.
//

#ifndef IVArray_hpp
#define IVArray_hpp

#include <stdio.h>

class IVArray {
public:
    // 在0~n长度的序列中找出任意重复的数，且元素大小都在n以内
    static int anyDuplicateNumFromUnsortArray(int *a, int len);
    
    // 二维数组的查找
    static bool twoDimensionArray(int *a, int row, int column, int target);
    
    // 递增数组 旋转数组中最小的数
    static int minNumOfReverseArray(int *a, int len);
    static int minInOrder(int *a, int left, int right);
    
    // 数组中出现超过一半的数字
    static int overHalfNumInArray(int *a, int len);
    
    // 数组中第K大的数（最大的K个数，最小的K个数）利用快速排序
    static int numberOfMaxNumInArray(int *a, int len, int k);
    static int firstK(int *a, int start, int end);
    
    // 有序数组中某个数出现的次数 二分法->双指针
    static int countOfSortedArray(int *a, int len, int target);
    
    // 调整奇数位 位于偶数位前面
    static void ajustPosition(int *a, int len);
};

#endif /* IVArray_hpp */
