//
// Created by vasyl on 2/15/2024.
//

#ifndef DBO_LAB1_BOOK_H
#define DBO_LAB1_BOOK_H

#include <iostream>
#include <string>
#include "Constants.h"

struct Book
{
public:
    Book(int id,
         int publisherId,
         long long isbn,
         char* title,
         char* author,
         char* genre,
         long prevBookAddress,
         long nextBookAddress,
         bool state = STATE_ACTIVE);

    Book() = default;

    int getId() const;

    void setId(int newId);

    int getPublisherId() const;

    void setPublisherId(int newPublisherId);

    long long getIsbn() const;

    void setIsbn(long long newIsbn);

    char* getTitle() const;

    void setTitle(char* newTitle);

    char* getAuthor() const;

    void setAuthor(char* newAuthor);

    char* getGenre() const;

    void setGenre(char* newGenre);

    long getPrevBookAddress() const;

    void setPrevBookAddress(long newAddress);

    long getNextBookAddress() const;

    void setNextBookAddress(long newAddress);

    bool getState() const;

    void setState(bool newState);

    std::string toString() const;

private:
    int id = -1;
    int publisherId = -1;
    long long isbn = -1;
    char* title = new char[STRING_SIZE]; // I need certain size of the string, so it's better to use char*[] than std::string
    char* author = new char[STRING_SIZE];
    char* genre = new char[STRING_SIZE];
    long prevBookAddress = -1;
    long nextBookAddress = -1;
    bool isRemoved = STATE_ACTIVE;
};

#endif //DBO_LAB1_BOOK_H
