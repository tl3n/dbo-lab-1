//
// Created by vasyl on 2/15/2024.
//

#include "Book.h"

Book::Book(int id,
           int publisherId,
           long long isbn,
           std::string title,
           std::string author,
           std::string genre,
           bool state) {
    // TODO: is this id is already taken
    this->id = id;
    // TODO: is this publisherId exists
    this->publisherId = publisherId;
    // TODO: if books have the same isbn but don't have the same title, author and genre
    // maybe use map with isbn as key?
    this->isbn = isbn;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->state = state;
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
    this->isbn = newIsbn;
}

std::string Book::getTitle() const {
    return this->title;
}

void Book::setTitle(const std::string& newTitle) {
    this->title = newTitle;
}

std::string Book::getAuthor() const {
    return this->author;
}

void Book::setAuthor(const std::string& newAuthor) {
    this->author = newAuthor;
}

std::string Book::getGenre() const {
    return this->genre;
}

void Book::setGenre(const std::string &newGenre) {
    this->genre = newGenre;
}

bool Book::getState() const {
    return this->state;
}

void Book::setState(bool newState) {
    this->state = newState;
}

std::string Book::toString() const {
    return "ID: " + std::to_string(this->id) +
           "; Publisher ID: " + std::to_string(this->publisherId) +
           "; ISBN: " + std::to_string(this->isbn) +
           "; Title: " + this->title +
           "; Author: " + this->author +
           "; Genre: " + this->genre + '\n';
}