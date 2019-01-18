//
//  IVLinkList.cpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/31.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#include "IVLinkList.hpp"

#pragma mark 遍历节点
void IVLinkList::printNodeValue(LinkNode *head) {
    if (head == nullptr) {
        return;
    }
    LinkNode *node = head;
    while (node != nullptr) {
        printf("%d,", node->data);
        node = node->next;
    }
}

#pragma mark delete a node 删除某个节点（判断节点是否存在）
bool IVLinkList::deleteNode(LinkNode **head, LinkNode *deletedNode) {
    if (*head == nullptr || deletedNode == nullptr) {
        return false;
    }
    // to be delete node is head node.
    if (*head == deletedNode) {
        delete deletedNode;
        deletedNode = nullptr;
        *head = deletedNode;
        return true;
    }
    // detemine if a node exits
    LinkNode *node = *head;
    while (node->next != deletedNode) {
        node = node->next;
    }
    if (node->next == nullptr) {
        return false;
    }
    LinkNode *delNode = node->next;
    if (delNode->next != nullptr) {
        LinkNode *nextNode = delNode->next;
        delNode->data = nextNode->data;
        delNode->next = nextNode->next;
        delete nextNode;
        nextNode = nullptr;
    }else {
        node->next = nullptr;
        delete deletedNode;
        deletedNode = nullptr;
    }
    return true;
}


#pragma mark delete duplicate node 删除重复节点
void IVLinkList::deleteDuplicateNode(LinkNode **head) {
    if (*head == nullptr) {
        return;
    }
    LinkNode *preNode = nullptr;
    LinkNode *node = *head;
    while (node != nullptr) {
        LinkNode *nextNode = node->next;
        bool isNeedDel = false;
        if (nextNode != nullptr && node->data == nextNode->data) {
            isNeedDel = true;
        }
        if (!isNeedDel) {
            preNode = node;
            node = node->next;
        }else {
            LinkNode *toBeDelNode = node;
            int tmpData = node->data;
            while (toBeDelNode != nullptr && toBeDelNode->data == tmpData) {
                nextNode = toBeDelNode->next;
                delete toBeDelNode;
                toBeDelNode = nullptr;
                toBeDelNode = nextNode;
            }
            if (*head == nullptr) {
                *head = nextNode;
            }else {
                preNode->next = nextNode;
            }
            node = nextNode;
        }
    }
}

#pragma mark 倒数第K个节点
LinkNode* IVLinkList::numberKNodeOfTail(LinkNode *head, int k) {
    if (head == nullptr || k <= 0) {
        return nullptr;
    }
    LinkNode *fastNode = head;
    LinkNode *slowNode = head;
    for (int i = k-1; i > 0; i--) {
        if (fastNode->next) {
            fastNode = fastNode->next;
        }
    }
    while (fastNode->next != nullptr) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    return slowNode;
}

#pragma mark 链表中间节点
LinkNode* IVLinkList::middleNode(LinkNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    LinkNode *slowNode = head;
    LinkNode *fastNode = nullptr;
    if (slowNode->next) {
        fastNode = slowNode->next;
    }
    while (fastNode && fastNode->next != nullptr) {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
        if (fastNode) {
            fastNode = fastNode->next;
        }
    }
    return slowNode;
}

#pragma mark 判断链表是否有环
LinkNode* meetingNodeOfRing(LinkNode *head) {
    if (head) {
        LinkNode *slowNode = head;
        LinkNode *fastNode = nullptr;
        if (slowNode->next) {
            fastNode = slowNode->next;
        }
        while (slowNode != fastNode && fastNode != nullptr) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (fastNode) {
                fastNode = fastNode->next;
            }
        }
        if (slowNode == fastNode) {
            return slowNode;
        }
    }
    return nullptr;
}

#pragma mark 环的入口节点
LinkNode* IVLinkList::entryNodeOfRing(LinkNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    LinkNode *meetingNode = meetingNodeOfRing(head);
    if (!meetingNode) {
        return nullptr;
    }
    int lengthOfRing = 1;
    LinkNode *nextNode = meetingNode->next;
    while (nextNode != meetingNode) {
        nextNode = nextNode->next;
        lengthOfRing++;
    }
    
    nextNode = head;
    while (lengthOfRing > 0) {
        lengthOfRing--;
        nextNode = nextNode->next;
    }
    LinkNode *slowNode = head;
    while (slowNode != nextNode) {
        slowNode = slowNode->next;
        nextNode = nextNode->next;
    }
    return slowNode;
}

#pragma mark 翻转链表
LinkNode* IVLinkList::reverseLinkList(LinkNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    LinkNode *reverseHead = nullptr;
    LinkNode *preNode = nullptr;
    LinkNode *node = head;
    
    while (node) {
        LinkNode *nextNode = node->next;
        if (nextNode == nullptr) {
            reverseHead = node;
        }
        node->next = preNode;
        preNode = node;
        node = nextNode;
    }
    return reverseHead;
}

#pragma mark 合并两个有序链表
LinkNode* IVLinkList::combineTwoLinkList(LinkNode *headA, LinkNode *headB) {
    if (headA == nullptr || headB == nullptr) {
        return headA ? headA : headB;
    }
    LinkNode *nodeA = headA;
    LinkNode *nodeB = headB;
    LinkNode *combinedHead = nullptr;
    LinkNode *preNode = nullptr;
    
    while (nodeA || nodeB) {
        LinkNode *tmpNode = nullptr;
        if (nodeA && nodeB) {
            if (nodeA->data > nodeB->data) {
                tmpNode = nodeB;
                nodeB = nodeB->next;
            }else if (nodeA->data < nodeB->data) {
                tmpNode = nodeA;
                nodeA = nodeA->next;
            }else {
                tmpNode = nodeB;
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
        }else if (nodeA) {
            tmpNode = nodeA;
            nodeA = nodeA->next;
        }else {
            tmpNode = nodeB;
            nodeB = nodeB->next;
        }
        
        if (preNode == nullptr) {
            combinedHead = tmpNode;
        }else {
            preNode->next = tmpNode;
        }
        preNode = tmpNode;
    }
    return combinedHead;
}
