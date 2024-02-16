//
// Created by vasyl on 2/15/2024.
//

#ifndef DBO_LAB1_BOOK_H
#define DBO_LAB1_BOOK_H

#include <string>
#include "Constants.h"

class Book
{
public:
    Book(int id,
         int publisherId,
         long long isbn,
         std::string title,
         std::string author,
         std::string genre,
         bool state = DIRECTOR_STATE_ACTIVE);

    Book() = default;

    int getId() const;

    void setId(int newId);

    int getPublisherId() const;

    void setPublisherId(int newPublisherId);

    long long getIsbn() const;

    void setIsbn(long long newIsbn);

    std::string getTitle() const;

    void setTitle(const std::string& newTitle);

    std::string getAuthor() const;

    void setAuthor(const std::string& newAuthor);

    std::string getGenre() const;

    void setGenre(const std::string& newGenre);

    bool getState() const;

    void setState(bool newState);

    std::string toString() const;
private:
    int id = -1;
    int publisherId = -1;
    long long isbn;
    std::string title;
    std::string author;
    std::string genre;
    bool state = DIRECTOR_STATE_ACTIVE;
};

#endif //DBO_LAB1_BOOK_H
