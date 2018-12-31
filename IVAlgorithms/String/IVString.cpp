//
//  IVString.cpp
//  IVAlgorithms
//
//  Created by 李向阳 on 2018/12/31.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#include "IVString.hpp"


void swapStr(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

// calculate the length of string
int strLength(char *s) {
    if (s == nullptr) {
        return 0;
    }
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void reverseStringCore(char *str, int start, int end) {
    while (start < end) {
        swapStr(str[start], str[end]);
        start++;
        end--;
    }
}

#pragma mark reverse string 翻转字符串
void IVString::reverseString(char *str) {
    if (str == nullptr) {
        return;
    }
    int len = strLength(str);
    reverseStringCore(str, 0, len-1);
    
    int start = 0;
    for (int i = start; i < len; i++) {
        if (str[i+1] == '/' || i == len-1) { // '/' Can also be anyother string;
            reverseStringCore(str, start, i);
            start = i + 2;
        }
    }
    
    printf("\n<stringRever>\n");
    while (*str != '\0') {
        printf("%c", *str);
        ++str;
    }
}

#pragma mark replace string 替换单个字符
void IVString::replaceString(char *str, char targetStr, char *withStr) {
    if (str == nullptr || withStr == nullptr) {
        return;
    }

    int withStrLen = strLength(withStr);
    int countOfTargetStr = 0;
    int strLen = 0;
    
    while (str[strLen] != '\0') {
        if (str[strLen] == targetStr) {
            countOfTargetStr++;
        }
        strLen++;
    }
    
    int totalLen = strLen + countOfTargetStr * (withStrLen-1);
    
    for (int i = strLen; i >= 0; i--) {
        if (str[i] == '.') {
            for (int j = withStrLen-1; j >= 0; j--) {
                str[totalLen--] = withStr[j];
            }
        }else {
            str[totalLen--] = str[i];
        }
    }
    
    printf("\n<ReplaceString>\n");
    while (*str != '\0') {
        printf("%c", *str);
        ++str;
    }
}

