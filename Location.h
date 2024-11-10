#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>
#include "Character.h"

using namespace std;

class Location 
{
    public:
        Location(const string& name, const string& description);
        void describe() const;
        void showInfo() const;
        void addExit(const string& direction, Location* location);
        Location* getExit(const string& direction);
        string getName();

        void addCharacter(Character* character);
        void removeCharacter(Character* character);
        vector<Character*> getCharacters() const;

    private:
        string name;
        string description;
        map<string, Location*> exits;
        vector<Character*> characters;
};

#endif
