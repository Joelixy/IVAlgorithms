//
//  IVTree.hpp
//  IVAlgorithms
//
//  Created by Joelixy on 2019/1/11.
//  Copyright © 2019 JoeLixy. All rights reserved.
//

#ifndef IVTree_hpp
#define IVTree_hpp

#include <stdio.h>

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

class IVTree {
public:
    static void preOrderRecursion(TreeNode *root);      // 前序遍历 递归
    static void inOrderRecursion(TreeNode *root);       // 中序遍历 递归
    static void postOrderRecursion(TreeNode *root);     // 后序遍历 递归
    
    static void preOrderNonRecusion(TreeNode *root);    // 前序遍历 非递归
    static void inOrderNonRecursion(TreeNode *root);    // 中序遍历 非递归
    static void postOrderNonRecursion(TreeNode *root);  // 后序遍历 非递归
    
    static TreeNode* constructBT(int *preOrder, int *inOrder, int len); // 根据前序遍历序列和中序遍历序列 构建二叉树
    static TreeNode* 
};



#endif /* IVTree_hpp */
