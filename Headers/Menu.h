//
// Created by vasyl on 2/21/2024.
//

#ifndef DBO_LAB1_MENU_H
#define DBO_LAB1_MENU_H

#include <iostream>
#include "Constants.h"
#include "Publisher.h"
#include "Book.h"
#include "Functions.h"

int readInt(const char* text);

char* readString(const char* text);

void addPublisherMenu();

void getPublisherMenu();

void removePublisherMenu();

void updatePublisherName(Publisher& publisher);

void updatePublisherLocation(Publisher& publisher);

void updatePublisherFields(Publisher& publisher);

void updatePublisherMenu();

void addBookMenu();

void getBookMenu();

void removeBookMenu();

void updateBookTitle(Book& book);

void updateBookAuthor(Book& book);

void updateBookGenre(Book& book);

void updateBookFields(Book& book);

void updateBookMenu();

void countBooksOfPublisherMenu();

void start();
#endif //DBO_LAB1_MENU_H
