//
// Created by vasyl on 2/19/2024.
//

#ifndef DBO_LAB1_FUNCTIONS_H
#define DBO_LAB1_FUNCTIONS_H

#include "Utilities.h"
#include "Publisher.h"
#include "Book.h"
#include "ListNode.h"
#include "Queue.h"
#include "Menu.h"

long getPublisherAddress(int id);

Publisher getPublisher(int id);

void getAllPublishers();

void countPublishers();

long getBookAddress(int id);

Book getBook(int id);

void getAllBooks();

void countBooks();

int countBooksOfPublisher(int id);

bool removePublisher(int id);

bool removeBook(int id);

bool insertPublisher(const Publisher& newPublisher);

bool insertBook(Book& newBook);

bool updatePublisher(int id, const Publisher& newPublisher);

bool updateBook(int id, const Book& newBook);

bool checkPublisherId(int id);

bool checkBookId(int id);

void loadIndex(char* filePath, ListNode** head);

void loadGarbage(char* filePath, Queue** garbage);

void prepareFiles(char* publishersPath,
                  char* booksPath,
                  char* publishersIndexPath,
                  char* booksIndexPath,
                  char* publishersGarbagePath,
                  char* booksGarbagePath);

void close(char* publishersIndexPath, char* booksIndexPath, char* publishersGarbagePath, char* booksGarbagePath);
#endif //DBO_LAB1_FUNCTIONS_H
