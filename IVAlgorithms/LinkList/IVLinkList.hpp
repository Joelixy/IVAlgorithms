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
    static void printNodeValue(LinkNode *head);
    static bool deleteNode(LinkNode **head, LinkNode *deletedNode); // 删除给定的节点
    static void deleteDuplicateNode(LinkNode **head); // 删除重复节点
    static LinkNode* numberOfKNodeForTail(LinkNode *head, int k);
    static LinkNode* middleNode(LinkNode *head);
    static LinkNode* entryNodeOfRing(LinkNode *head);
};

#endif /* IVLinkList_hpp */
