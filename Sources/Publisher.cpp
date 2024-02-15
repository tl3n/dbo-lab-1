//
// Created by vasyl on 2/15/2024.
//

#include "Publisher.h"

Publisher::Publisher(int id, std::string name, std::string address, bool state)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->state = state;
}

int Publisher::getId()
{
  return this->id;
}

void Publisher::setId(int newId)
{
    this->id = newId;
}

std::string Publisher::getName()
{
    return this->name;
}

void Publisher::setName(const std::string& newName)
{
    this->name = newName;
}

std::string Publisher::getAddress()
{
    return this->address;
}

void Publisher::setAddress(const std::string& newAddress)
{
    this->address = newAddress;
}

bool Publisher::getState()
{
    return this->state;
}

void Publisher::setState(bool newState)
{
    this->state = newState;
}

std::string Publisher::toString() {
    return "ID: " + std::to_string(this->id) +
           "; Name: " + this->name +
           "; Adress: " + this->address +
           ";";
}



