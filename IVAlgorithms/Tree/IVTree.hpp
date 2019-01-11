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
    TreeNode *parent;
};

class IVTree {
public:
    static void preOrderRecursion(TreeNode *root);      // 前序遍历 递归
    static void inOrderRecursion(TreeNode *root);       // 中序遍历 递归
    static void postOrderRecursion(TreeNode *root);     // 后序遍历 递归
    
    static void preOrderNonRecusion(TreeNode *root);    // 前序遍历 非递归
    static void inOrderNonRecursion(TreeNode *root);    // 中序遍历 非递归
    static void postOrderNonRecursion(TreeNode *root);  // 后序遍历 非递归
    
    // 根据前序遍历序列和中序遍历序列 构建二叉树
    static TreeNode* constructBTByPreOrderAndInOrder(int *preOrder, int *inOrder, int len);
    static TreeNode* constructBTByPreOrderAndInOrderImp(int *preOrderStart, int *preOrderEnd, int *inOrderStart, int *inOrderEnd);
    
    // 根据中序遍历序列和后序遍历序列 构建二叉树
    static TreeNode* constructBTByInOrderAndPostOrder(int *inOrder, int *postOrder, int len);
    static TreeNode* constructBTByInOrderAndPostOrderImp(int *inOrderStart, int *inOrderEnd, int *postOrderStart, int *postOrderEnd);
    
    // 中序遍历的下一个节点
    static TreeNode* nextTreeNode(TreeNode *node);
    
    // 翻转二叉树
    static void reverseTreeNode(TreeNode *root);
    
    // 树的深度
    static int deepthOfBT(TreeNode *root);
    
    // BST 根据后序遍历序列 判断是否是二叉搜索树
    static bool isBST(int *postOrder, int len);
    
    // 从上到下 打印二叉树
    static void printFromTopToBottom(TreeNode *root);
};



#endif /* IVTree_hpp */
