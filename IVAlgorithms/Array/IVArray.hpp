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
};

#endif /* IVArray_hpp */
