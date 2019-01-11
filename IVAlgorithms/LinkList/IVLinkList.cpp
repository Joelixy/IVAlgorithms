//
//  IVLinkList.cpp
//  IVAlgorithms
//
//  Created by Joelixy on 2018/12/31.
//  Copyright © 2018 JoeLixy. All rights reserved.
//

#include "IVLinkList.hpp"

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

#pragma mark delete a node
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


#pragma mark delete duplicate node
void IVLinkList::deleteDuplicateNode(LinkNode **head) {
    if (*head == nullptr) {
        return;
    }
    LinkNode *preNode = nullptr;
    LinkNode *node = *head;
    while (node != nullptr) {
        LinkNode *nextNode = node->next;
        bool isNeedDel = false;
        if (node->data == nextNode->data) {
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

LinkNode* IVLinkList::numberOfKNodeForTail(LinkNode *head, int k) {
    if (head == nullptr || k <= 0) {
        return nullptr;
    }
    LinkNode *fastNode = head;
    LinkNode *slowNode = head;
    for (int i = k-1; i > 0; i++) {
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

LinkNode* IVLinkList::middleNode(LinkNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    LinkNode *slowNode = head;
    LinkNode *fastNode = nullptr;
    if (slowNode->next) {
        fastNode = slowNode->next;
    }
    while (fastNode->next != nullptr) {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
        if (fastNode) {
            fastNode = fastNode->next;
        }
    }
    return slowNode;
}


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
