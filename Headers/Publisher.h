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
              std::string name,
              std::string address,
              bool state = PUBLISHER_STATE_ACTIVE);

    Publisher() = default;

    int getId();

    void setId(int newID);

    std::string getName();

    void setName(const std::string& newName);

    std::string getAddress();

    void setAddress(const std::string& newAddress);

    bool getState();

    void setState(bool newState);

    std::string toString();
private:
    int id = -1;
    std::string name;
    std::string address;
    bool state = PUBLISHER_STATE_ACTIVE;
};

#endif //DBO_LAB1_PUBLISHER_H
