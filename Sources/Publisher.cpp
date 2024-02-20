//
// Created by vasyl on 2/15/2024.
//

#include "Publisher.h"

Publisher::Publisher(int id,
                     char* name,
                     char* location,
                     long firstBookAddress,
                     bool isRemoved) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->firstBookAddress = firstBookAddress;
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

char* Publisher::getLocation() const {
    return this->location;
}

void Publisher::setLocation(char* newLocation) {
    this->location = newLocation;
}

long Publisher::getFirstBookAddress() const {
    return this->firstBookAddress;
}

void Publisher::setFirstBookAddress(long newAddress) {
    this->firstBookAddress = newAddress;
}

bool Publisher::getState() const {
    return this->isRemoved;
}

void Publisher::setState(bool newState) {
    this->isRemoved = newState;
}

std::string Publisher::toString() {
    return "ID: " + std::to_string(this->id) +
           "; Name: " + this->name +
           "; Location: " + this->location +
           "; First book address: " + std::to_string(this->firstBookAddress) +
           ";\n";
}

