//
//  IVTree.cpp
//  IVAlgorithms
//
//  Created by Joelixy on 2019/1/11.
//  Copyright © 2019 JoeLixy. All rights reserved.
//

#include "IVTree.hpp"
#include "vector"
#include "deque"

#pragma mark 递归遍历
void IVTree::preOrderRecursion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    printf("%d, ", root->data);
    preOrderRecursion(root->left);
    preOrderRecursion(root->right);
}

void IVTree::inOrderRecursion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrderRecursion(root->left);
    printf("%d, ", root->data);
    inOrderRecursion(root->right);
}

void IVTree::postOrderRecursion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    postOrderRecursion(root->left);
    postOrderRecursion(root->right);
    printf("%d, ", root->data);
}

#pragma mark 非递归遍历
void IVTree::preOrderNonRecusion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode *nextNode = root;
    std::vector<TreeNode *> nodes;
    while (nextNode || !nodes.empty()) {
        while (nextNode) {
            nodes.push_back(nextNode);
            printf("%d, ", nextNode->data);
            nextNode = nextNode->left;
        }
        if (!nodes.empty()) {
            nextNode = nodes.back();
            nodes.pop_back();
            nextNode = nextNode->right;
        }
    }
}

void IVTree::inOrderNonRecursion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode *nextNode = root;
    std::vector<TreeNode *> nodes;
    while (nextNode || !nodes.empty()) {
        while (nextNode) {
            nodes.push_back(nextNode);
            nextNode = nextNode->left;
        }
        if (!nodes.empty()) {
            nextNode = nodes.back();
            nodes.pop_back();
            printf("%d, ", nextNode->data);
            nextNode = nextNode->right;
        }
    }
}

#pragma mark 后序遍历 非递归
void IVTree::postOrderNonRecursion(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode *nextNode = root;
    TreeNode *lastAccessNode = nullptr;
    std::vector<TreeNode *> nodes;
    while (nextNode) {
        nodes.push_back(nextNode);
        nextNode = nextNode->left;
    }
    while (!nodes.empty()) {
        nextNode = nodes.back();
        nodes.pop_back();
        if (nextNode->right == nullptr || nextNode->right == lastAccessNode) {
            lastAccessNode = nextNode;
            printf("%d, ", nextNode->data);
        }else {
            nodes.push_back(nextNode);
            TreeNode *node = nextNode->right;
            while (node) {
                nodes.push_back(node);
                node = node->left;
            }
        }
    }
}

#pragma mark 根据前序和中序 构建二叉树
TreeNode* IVTree::constructBTByPreOrderAndInOrder(int *preOrder, int *inOrder, int len) {
    if (preOrder == nullptr || inOrder == nullptr || len < 1) {
        return nullptr;
    }
    return constructBTByPreOrderAndInOrderImp(preOrder, preOrder+len-1, inOrder, inOrder+len-1);
}

TreeNode* IVTree::constructBTByPreOrderAndInOrderImp(int *preOrderStart, int *preOrderEnd, int *inOrderStart, int *inOrderEnd) {
    int rootValue = *preOrderStart;
    TreeNode *rootNode = new TreeNode();
    rootNode->data = rootValue;
    rootNode->left = rootNode->right = nullptr;
    
    if (preOrderStart == preOrderEnd) {
        if (inOrderStart == inOrderEnd && *inOrderStart == *inOrderEnd) {
            return rootNode;
        }else {
            return nullptr; // 此处程序应中断
        }
    }
    int *inOrderRoot = inOrderStart;
    while (inOrderRoot <= inOrderEnd && *inOrderRoot != rootValue) {
        ++inOrderRoot;
    }
    if (inOrderRoot == inOrderEnd && *inOrderRoot != rootValue) {
        return nullptr;     // 此处程序应中断
    }
    int leftTreeLen = (int)(inOrderRoot - inOrderStart);
    int *preOrderLeftEnd = preOrderStart + leftTreeLen;
    if (leftTreeLen > 0) {
        rootNode->left = constructBTByPreOrderAndInOrderImp(preOrderStart+1, preOrderLeftEnd, inOrderStart, inOrderRoot-1);
    }
    if (leftTreeLen < inOrderEnd - inOrderStart) {
        rootNode->right = constructBTByPreOrderAndInOrderImp(preOrderLeftEnd+1, preOrderEnd, inOrderRoot+1, inOrderEnd);
    }
    return rootNode;
}

#pragma mark 中序和后序构建二叉树
TreeNode* IVTree::constructBTByInOrderAndPostOrder(int *inOrder, int *postOrder, int len) {
    if (inOrder == nullptr || postOrder == nullptr || len < 1) {
        return nullptr;
    }
    return constructBTByInOrderAndPostOrderImp(inOrder, inOrder+len-1, postOrder, postOrder+len-1);
}

TreeNode* IVTree::constructBTByInOrderAndPostOrderImp(int *inOrderStart, int *inOrderEnd, int *postOrderStart, int *postOrderEnd) {
    int rootValue = *postOrderEnd;
    TreeNode *rootNode = new TreeNode();
    rootNode->data = rootValue;
    rootNode->left = rootNode->right = nullptr;
    
    if (inOrderStart == inOrderEnd) {
        if (postOrderStart == postOrderEnd && *postOrderStart == *postOrderEnd) {
            return rootNode;
        }else {
            return nullptr; // 此处程序应中断
        }
    }
    int *inOrderRoot = inOrderStart;
    while (inOrderRoot <= inOrderEnd && *inOrderRoot != rootValue) {
        ++inOrderRoot;
    }
    if (inOrderRoot == inOrderEnd && *inOrderRoot != rootValue) {
        return nullptr;     // 此处程序应中断
    }
    int leftTreeLen = (int)(inOrderRoot - inOrderStart);
    int *postOrderLeftEnd = postOrderStart + leftTreeLen - 1;
    if (leftTreeLen > 0) {
        rootNode->left = constructBTByInOrderAndPostOrderImp(inOrderStart, inOrderRoot-1, postOrderStart, postOrderLeftEnd);
    }
    if (leftTreeLen < inOrderEnd - inOrderStart) {
        rootNode->right = constructBTByInOrderAndPostOrderImp(inOrderRoot+1, inOrderEnd, postOrderLeftEnd+1, postOrderEnd-1);
    }
    return rootNode;
}

#pragma mark 中序遍历 二叉树的下一个节点
TreeNode* IVTree::nextTreeNode(TreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    TreeNode *nextNode = nullptr;
    
    if (node->right) {
        nextNode = node->right;
        while (nextNode->left) {
            nextNode = nextNode->left;
        }
    }else if (node->parent != nullptr) {
        TreeNode *parentNode = node->parent;
        while (parentNode && parentNode->right == node) {
            node = parentNode;
            parentNode = parentNode->parent;
        }
        nextNode = parentNode;
    }
    return nextNode;
}

#pragma mark 翻转二叉树
void IVTree::reverseTreeNode(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode *tmpNode = root->left;
    root->left = root->right;
    root->right = tmpNode;
    
    if (root->left) {
        reverseTreeNode(root->left);
    }
    if (root->right) {
        reverseTreeNode(root->right);
    }
}

#pragma mark 树的深度
int IVTree::deepthOfBT(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int left = deepthOfBT(root->left);
    int right = deepthOfBT(root->right);
    return left > right ? (left+1) : (right+1);
}

#pragma mark 是否是二叉搜索树
bool IVTree::isBST(int *postOrder, int len) {
    if (postOrder == nullptr || len < 1) {
        return false;
    }
    int rootValue = postOrder[len-1];
    int i = 0;
    for (; i < len - 1; i++) {
        if (postOrder[i] > rootValue) {
            break;
        }
    }
    
    for (int j = i; j < len - 1; j++) {
        if (postOrder[j] < rootValue) {
            return false;
        }
    }
    bool left = true;
    if (i > 0) {
        left = isBST(postOrder, i);
    }
    bool right = true;
    if (i < len - 1) {
        right = isBST(postOrder + i, len - i - 1);
    }
    return left && right;
}
 
#pragma mark 从上到下打印二叉树
void IVTree::printFromTopToBottom(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    std::deque<TreeNode *> nodes;
    nodes.push_back(root);
    while (nodes.size()) {
        TreeNode *nextNode = nodes.front();
        nodes.pop_front();
        printf("%d, ", nextNode->data);
        if (nextNode->left) {
            nodes.push_back(nextNode->left);
        }
        if (nextNode->right) {
            nodes.push_back(nextNode->right);
        }
    }
}
