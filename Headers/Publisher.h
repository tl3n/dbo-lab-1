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
              long firstBookAddress,
              bool state = STATE_ACTIVE);

    Publisher() = default;

    int getId() const;

    void setId(int newID);

    char* getName() const;

    void setName(char* newName);

    char* getLocation() const;

    void setLocation(char* newLocation);

    long getFirstBookAddress() const;

    void setFirstBookAddress(long newAddress);

    bool getState() const;

    void setState(bool newState);

    std::string toString();
private:
    int id = -1;
    char* name = new char[STRING_SIZE];
    char* location = new char[STRING_SIZE];
    long firstBookAddress = -1;
    bool isRemoved = STATE_ACTIVE;
};

#endif //DBO_LAB1_PUBLISHER_H
