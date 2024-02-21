//
// Created by vasyl on 2/19/2024.
//

#ifndef DBO_LAB1_FUNCTIONS_H
#define DBO_LAB1_FUNCTIONS_H

#include "Book.h"
#include "Publisher.h"
#include "Utilities.h"
#include "ListNode.h"
#include "Queue.h"

long getPublisherAddress(int id);

Publisher getPublisher(int id);

long getBookAddress(int id);

Book getBook(int id);

void deletePublisher(int id);

void deleteBook(int id);

void insertPublisher(const Publisher& newPublisher);

void insertBook(const Book& newBook);

void updatePublisher(int id, const Publisher& newPublisher);

void updateBook(int id, const Book& newBook);

#endif //DBO_LAB1_FUNCTIONS_H
