//
//  IVSort.hpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/30.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#ifndef IVSort_hpp
#define IVSort_hpp

#include <stdio.h>

class IVSort {
public:
    static void bubbleSort(int *a, int len); // 平均复杂度 O(n^2) 稳定
    static void selectSort(int *a, int len); // 平均复杂度 O(n^2) 稳定
    static void insertSort(int *a, int len); // 平均复杂度 O(n^2) 稳定
    static void quickSort(int *a, int len); // 平均复杂度 O(nlogn) 不稳定
};

#endif /* IVSort_hpp */
