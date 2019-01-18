//
//  ViewController.m
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/29.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#import "ViewController.h"
#import "IVSort.hpp"
#import "IVMath.hpp"
#import "IVString.hpp"

#import "IVArray.hpp"
#import "IVTree.hpp"
#import "IVLinkList.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self interview_sort];
    [self interview_math];
    [self interview_string];
    [self interview_array];
    [self interview_linkList];
    [self interview_tree];
}

- (void)interview_sort {
    int a[] = {6, 4, 3, 1, 2, 0, 5};
    
    IVSort sort;
//    IVSort *sort = new IVSort; // malloc from heap
    sort.bubbleSort(a, 7);
    sort.selectSort(a, 7);
    sort.insertSort(a, 7);
    sort.quickSort(a, 7);
    
}

- (void)interview_math {
    IVMath math;
    long sum = math.fibonacciSequence(5);
    int primeCount = math.countOfPrime(10);
    int a[] = {6, 4, 3, 1, 2, 0, 5};
    bool isExist = math.binarySearch(a, 7, 1);
    bool isUgly = math.isUgly(7);
    bool isPower = math.isPower(8);
}

- (void)interview_string {
    IVString string;
    char str[15] = "www/google/com";
    string.reverseString(str);
    
    char replaceStr[15] = "www.google.com";
    char withStr[6] = "/////";
    string.replaceString(replaceStr, '.', withStr);
    
    char numStr[6] = " -352";
    int number = string.convertStringToNumber(numStr);
    NSLog(@"number:%d", number);
}

- (void)interview_array {
    int array1[9] = {8, 5, 7, 2, 5, 3, 1, 4, 6};
    int duplicate = IVArray::anyDuplicateNumFromUnsortArray(array1, 9);
    
    int twoDimension[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    bool isExits = IVArray::twoDimensionArray(*twoDimension, 4, 4, 16);
    
    int minArray[8] = {6, 7, 8, 9, 2, 3, 4, 5}; // 特殊情况 {1, 3, 4, 5, 1, 1};
    int minNum = IVArray::minNumOfReverseArray(minArray, 8);
    
    int array2[10] = {1, 2, 2, 2, 2, 3, 3, 2, 4, 4};
    int value = IVArray::overHalfNumInArray(array2, 10);
    
    int array3[9] = {5, 6, 2, 8, 3, 4, 7, 9, 1};
    int firstKNumber = IVArray::numberOfMaxNumInArray(array3, 9, 5);
    
    int array4[12] = {2, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8, 9};
    int count = IVArray::countOfSortedArray(array4, 12, 5);
    
    int array5[9] = {1, 8, 9, 0, 3, 5, 6, 4, 7};
    IVArray::ajustPosition(array5, 9);
    
}

- (void)interview_linkList {
    
#warning 调试时建议单独调用，并考虑特殊情况下的调用结构，以下测试仅供参考
    LinkNode *head = nullptr;
    LinkNode *nextNode = nullptr;
    for (int i = 0; i < 8; i++) {
        LinkNode *node = new LinkNode();
        node->data = (i + 1) * 10;
        node->next = nullptr;
        if (nextNode) {
            nextNode->next = node;
        }else {
            head = node;
        }
        nextNode = node;
    }
    
    IVLinkList linkList;
    linkList.printNodeValue(head);
    
    LinkNode *headNode = head;
    // 删除某个节点
    bool isDelete = linkList.deleteNode(&headNode, head->next->next);
    
    // 删除重复节点
    linkList.deleteDuplicateNode(&headNode);
    
    // 倒数第4个节点
    LinkNode *targetNode = linkList.numberKNodeOfTail(head, 4);
    
    // 中间节点
    LinkNode *middleNode = linkList.middleNode(head);
    
    // 环的入口节点
//    nextNode->next = head->next->next;
//    LinkNode *entryNode = linkList.entryNodeOfRing(head);
    
    // 翻转链表
//    LinkNode *reverseNode = linkList.reverseLinkList(head);
    
    
    LinkNode *headB = nullptr;
    LinkNode *nextNodeB = nullptr;
    for (int i = 0; i < 5; i++) {
        LinkNode *node = new LinkNode();
        node->data = (i + 1) * 2;
        node->next = nullptr;
        if (nextNodeB) {
            nextNodeB->next = node;
        }else {
            headB = node;
        }
        nextNodeB = node;
    }
    
    // 合并两个链表
    LinkNode *combineHead = linkList.combineTwoLinkList(head, headB);
}

- (void)interview_tree {
#warning 以下测试仅供参考，test case覆盖的还不够全面，调试时可自行修改以覆盖更全面的case
    
    IVTree tree;
    
    int preOrder[9] = {9, 8, 6, 2, 5, 7, 4, 1, 3};
    int inOrder[9] = {2, 6, 8, 5, 9, 4, 1, 7, 3};
    TreeNode *rootA = tree.constructBTByPreOrderAndInOrder(preOrder, inOrder, 9);
    
    int postOrder[9] = {2, 6, 5, 8, 1, 4, 3, 7, 9};
    TreeNode *rootB = tree.constructBTByInOrderAndPostOrder(inOrder, postOrder, 9);
    // 非递归遍历
    tree.preOrderRecursion(rootA);
    tree.inOrderRecursion(rootA);
    tree.postOrderRecursion(rootA);
    // 递归遍历
    tree.preOrderNonRecusion(rootA);
    tree.inOrderNonRecursion(rootA);
    tree.postOrderNonRecursion(rootA);
    // 翻转二叉树
    tree.reverseTreeNode(rootA);
    // 下一个节点
    TreeNode *nextTreeNode = tree.nextTreeNode(rootB->right);
    // 树的深度
    int deep = tree.deepthOfBT(rootB);
    
    
    // BST 二叉搜索树（左小右大）
    // 先构建一个二叉搜索树
    int bstPreOrder[9] = {5, 3, 2, 1, 4, 8, 6, 7, 9};
    int bstInOrder[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    TreeNode *bstRoot = tree.constructBTByPreOrderAndInOrder(bstPreOrder, bstInOrder, 9);
    
    int bstPostOrder[9] = {1, 2, 4, 3, 7, 6, 9, 8, 5};
    bool isBST = tree.isBST(bstPostOrder, 9);
    
    tree.printFromTopToBottom(bstRoot);
}

@end
