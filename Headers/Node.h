//
// Created by vasyl on 2/20/2024.
//

#ifndef DBO_LAB1_NODE_H
#define DBO_LAB1_NODE_H

#include <iostream>
#include "Constants.h"

struct Node {
    int id = -1;
    long address = -1;
    Node* next = nullptr;
};


long getAddress(int id, Node* head);

bool isIdFree(int id, Node* head);

void addNode(int id, long address, Node** head);

void removeNode(int id, Node** head);

void sortList(Node** head);

void printList(Node* head);

#endif //DBO_LAB1_NODE_H
