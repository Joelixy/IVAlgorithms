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
};

#endif /* IVArray_hpp */
