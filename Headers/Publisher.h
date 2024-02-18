//
// Created by vasyl on 2/15/2024.
//

#ifndef DBO_LAB1_PUBLISHER_H
#define DBO_LAB1_PUBLISHER_H

#include <string>
#include "Constants.h"
class Publisher
{
public:
    Publisher(int id,
              char* name,
              char* address,
              bool state = PUBLISHER_STATE_ACTIVE);

    Publisher() = default;

    int getId() const;

    void setId(int newID);

    char* getName() const;

    void setName(char* newName);

    char* getAddress() const;

    void setAddress(char* newAddress);

    bool getState() const;

    void setState(bool newState);

    std::string toString() const;
private:
    int id = -1;
    char* name = new char[STRING_SIZE];
    char* address = new char[STRING_SIZE];
    bool isRemoved = PUBLISHER_STATE_ACTIVE;
};

#endif //DBO_LAB1_PUBLISHER_H
