#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
//#include "Location.h"

using namespace std;

class Location;

class Character 
{
    public:
        Character(const string& name, Location* currentLocation);
        string getName() const;
        Location* getCurrentLocation() const;
        void setCurrentLocation(Location* location);
        void showInfo();
        void interact() const;

    private:
        string name;
        Location* currentLocation;
};

#endif
