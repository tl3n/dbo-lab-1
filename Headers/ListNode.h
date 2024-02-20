//
// Created by vasyl on 2/20/2024.
//

#ifndef DBO_LAB1_LISTNODE_H
#define DBO_LAB1_LISTNODE_H

#include <iostream>
#include "Constants.h"

struct ListNode {
    int id = -1;
    long address = -1;
    ListNode* next = nullptr;
};


long getAddress(int id, ListNode* head);

bool isIdFree(int id, ListNode* head);

void addListNode(int id, long address, ListNode** head);

void removeListNode(int id, ListNode** head);

void sortList(ListNode** head);

void printList(ListNode* head);

#endif //DBO_LAB1_LISTNODE_H
