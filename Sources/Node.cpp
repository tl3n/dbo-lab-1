//
// Created by vasyl on 2/20/2024.
//

#include "Node.h"

long getAddress(int id, Node* head) {
    // checking id range
    if (id < 1 || id > INDEXES_MAX_SIZE) {
        std::cerr << "ID is out of range.\n";
        return -1;
    }

    // finding address
    Node* temp = head;
    while (temp) {
        if (temp->id == id) {
            return temp->address;
        }
        temp = temp->next;
    }
    // if address wasn't found, returning an error
    std::cerr << "Index not found.\n";
    return -1;
}

bool isIdFree(int id, Node* head) {
    // check if id is already taken and is in range
    if (id < 1 || id > INDEXES_MAX_SIZE) {
        std::cerr << "ID is out of range.\n";
        return false;
    }

    // check if head exists
    if (!head) {
        std::cerr << "Invalid list head pointer\n";
        return false;
    }

    // check if id is free
    Node* temp = head;
    while (temp) {
        if (temp->id == id) {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

void addNode(int id, long address, Node** head) {
    // check if id is already taken and is in range
    // check if head exists
    if (!isIdFree(id, *head)) {
        std::cerr << "This ID is already taken.\n";
        return;
    }

    // check if address is in range
    if (address < 0) {
        std::cerr << "Address is out of range\n";
        return;
    }

    Node* temp = new Node;
    temp->id = id;
    temp->address = address;

    temp->next = *head;
    (*head) = temp;
}

void removeNode(int id, Node** head) {
    // check if id is already taken and is in range
    // check if head exists
    if (isIdFree(id, *head)) {
        return;
    }

    // check if head is node to delete
    if ((*head)->id == id) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    // delete node
    Node* temp = *head;
    while (temp->next) {
        if (temp->next->id == id) {
            Node* toRemove = temp->next;
            temp->next = temp->next->next;
            delete toRemove;
            return;
        }
        temp = temp->next;
    }
}

void sortList(Node** head) {
    if (!(*head) || !(*head)->next) {
        // if the list is empty or has only one element it is already sorted
        return;
    }

    //  bubble sort algorithm
    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = *head;

        while (current->next != lastSorted) {
            if (current->id > current->next->id) {
                // swap the nodes data
                int tempId = current->id;
                long tempAddress = current->address;

                current->id = current->next->id;
                current->address = current->next->address;

                current->next->id = tempId;
                current->next->address = tempAddress;

                swapped = true;
            }
            current = current->next;
        }
        // mark the last sorted node to optimize the sorting process
        lastSorted = current;
    } while (swapped);
}

void printList(Node* head) {
    if (!head) {
        std::cerr << "Invalid list head pointer.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        std::cout << temp->id << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}