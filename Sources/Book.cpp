//
// Created by vasyl on 2/15/2024.
//

#include "Book.h"

Book::Book(int id,
           int publisherId,
           long long isbn,
           char* title,
           char* author,
           char* genre,
           long prevBookAddress,
           long nextBookAddress,
           bool isRemoved) {
    // TODO: is this id is already taken
    this->id = id;
    // TODO: is this publisherId exists
    this->publisherId = publisherId;
    // TODO: if books have the same isbn but don't have the same title, author and genre
    // maybe use map with isbn as key?
    this->setIsbn(isbn);
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->prevBookAddress = prevBookAddress;
    this->nextBookAddress = nextBookAddress;
    this->isRemoved = isRemoved;
}
int Book::getId() const {
    return this->id;
}

// TODO: is this id is already taken
void Book::setId(int newId) {
    this->id = newId;
}

// TODO: is this publisherId exists
int Book::getPublisherId() const {
    return this->publisherId;
}

void Book::setPublisherId(int newPublisherId) {
    this->publisherId = newPublisherId;
}

long long Book::getIsbn() const {
    return this->isbn;
}

void Book::setIsbn(long long newIsbn) {
    if (std::to_string(newIsbn).length() != 13) {
        std::cerr << "ISBN must be 13 digits long.";
        return;
    }
    else {
        this->isbn = newIsbn;
    }
}

char* Book::getTitle() const {
    return this->title;
}

void Book::setTitle(char* newTitle) {
    this->title = newTitle;
}

char* Book::getAuthor() const {
    return this->author;
}

void Book::setAuthor(char* newAuthor) {
    this->author = newAuthor;
}

char* Book::getGenre() const {
    return this->genre;
}

void Book::setGenre(char* newGenre) {
    this->genre = newGenre;
}

long Book::getPrevBookAddress() const {
    return this->prevBookAddress;
}

void Book::setPrevBookAddress(long newAddress) {
    this->prevBookAddress = newAddress;
}

long Book::getNextBookAddress() const {
    return this->nextBookAddress;
}

void Book::setNextBookAddress(long newAddress) {
    this->nextBookAddress = newAddress;
}

bool Book::getState() const {
    return this->isRemoved;
}

void Book::setState(bool newState) {
    this->isRemoved = newState;
}

std::string Book::toString() const {
    return "ID: " + std::to_string(this->id) +
           "; Publisher ID: " + std::to_string(this->publisherId) +
           "; ISBN: " + std::to_string(this->isbn) +
           "; Title: " + this->title +
           "; Author: " + this->author +
           "; Genre: " + this->genre + '\n';
}