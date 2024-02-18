//
// Created by vasyl on 2/15/2024.
//

#include "Publisher.h"

Publisher::Publisher(int id,
                     char* name,
                     char* address,
                     bool isRemoved) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->isRemoved = isRemoved;
}

int Publisher::getId() const {
  return this->id;
}

void Publisher::setId(int newId) {
    this->id = newId;
}

char* Publisher::getName() const {
    return this->name;
}

void Publisher::setName(char* newName) {
    this->name = newName;
}

char* Publisher::getAddress() const {
    return this->address;
}

void Publisher::setAddress(char* newAddress) {
    this->address = newAddress;
}

bool Publisher::getState() const {
    return this->isRemoved;
}

void Publisher::setState(bool newState) {
    this->isRemoved = newState;
}

std::string Publisher::toString() const {
    return "ID: " + std::to_string(this->id) +
           "; Name: " + this->name +
           "; Address: " + this->address +
           ";";
}



