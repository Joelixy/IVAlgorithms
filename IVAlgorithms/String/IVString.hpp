//
//  IVString.hpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/31.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#ifndef IVString_hpp
#define IVString_hpp

#include <stdio.h>

class IVString {
public:
    // before:www/google/com after:com/google/www
    static void reverseString(char *str);
    
    // before:www.googl.com, after:www%20google%20com, withStr is %20
    static void replaceString(char *str, char targetStr, char *withStr);
    
    // 字符串转数字（整形）
    static int convertStringToNumber(char *str);
};

#endif /* IVString_hpp */
