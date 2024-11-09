#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "Location.h"
#include "Item.h"
#include "Character.h"
//#include "Control.h"

class Control;

class Game 
{
    public:
        Game();
        void play();
        Location* getCurrentLocation() const;
        void setCurrentLocation(Location* location);
        const vector<Location*>& getLocations() const;
        void moveMainCharacter(Location* newLocation);

    private:
        vector<Location*> locations;
        Location* currentLocation;

        vector<Item*> items;
        vector<Character*> characters;
        
        Control* control;

        Character* mainCharacter;
        
        void loadLocations();
        void loadControl();
        
        void loadGameData();
        //void loadItems();
        void loadCharacters(); 
};

#endif
