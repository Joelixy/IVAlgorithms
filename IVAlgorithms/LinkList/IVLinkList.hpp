//
//  IVLinkList.hpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/31.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#ifndef IVLinkList_hpp
#define IVLinkList_hpp

#include <stdio.h>

struct LinkNode {
    int data;
    LinkNode *next;
};

class IVLinkList {
public:
    // 打印链表
    static void printNodeValue(LinkNode *head);
    
    // 删除给定的节点
    static bool deleteNode(LinkNode **head, LinkNode *deletedNode);
    
    // 删除重复节点
    static void deleteDuplicateNode(LinkNode **head);
    
    // 倒数第K个节点
    static LinkNode* numberKNodeOfTail(LinkNode *head, int k);
    // 中间节点
    static LinkNode* middleNode(LinkNode *head);
    // 入口节点
    static LinkNode* entryNodeOfRing(LinkNode *head);
    
    // 翻转链表
    static LinkNode* reverseLinkList(LinkNode *head);
    
    // 合并两个链表
    static LinkNode* combineTwoLinkList(LinkNode *headA, LinkNode *headB);
    
    // 两个链表的第一个公共节点
    static LinkNode* firstPublicNode(LinkNode *headA, LinkNode *headB);
};

#endif /* IVLinkList_hpp */
