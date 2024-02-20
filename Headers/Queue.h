//
// Created by vasyl on 2/20/2024.
//

#ifndef DBO_LAB1_QUEUE_H
#define DBO_LAB1_QUEUE_H

#include <iostream>
#include "Constants.h"
struct QueueNode {
    long address = -1;
    QueueNode* next = nullptr;
};

struct Queue {
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;

    bool isEmpty() const;

    void push(long address);

    long pop();
};

#endif //DBO_LAB1_QUEUE_H
