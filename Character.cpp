#include "Character.h"
#include "Location.h"
#include <iostream>

Character::Character(const string& name, Location* currentLocation)
    : name(name), currentLocation(currentLocation) {}

string Character::getName() const 
{
    return name;
}

Location* Character::getCurrentLocation() const 
{
    return currentLocation;
}

void Character::setCurrentLocation(Location* location) 
{
    currentLocation = location;
}

void Character::showInfo()
{
    cout << "Name: " << name << endl;
    cout << "Location: " << currentLocation->getName() << endl;
}

void Character::interact() const {
    cout << name << " interacts with you." << std::endl;
}
