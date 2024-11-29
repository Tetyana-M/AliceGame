#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "Location.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Control;

/** 
 * @class Game: manages the main game logic, characters, 
 * locations, items and win/lose conditions.
 */
class Game 
{
    public:
        /**
         * Game constructor: constructs and initializes new game instance.
         */
        Game();
        /**
         * play function: starts and runs the game loop.
         */
        void play();
        /**
         * getCurrentLocation function: retrieves a pointer to the current location of
         * the main character.
         */
        Location* getCurrentLocation() const;
        /**
         * setCurrentLocation function: sets current location of the main character.
         * @param location - Location* - pointer to the new current location object.
         */
        void setCurrentLocation(Location* location);
        /**
         * getMainCharacter function: retrieves pointer to the main character object.
         * @return mainCharacter - Character* - pointer to the main character object.
         */
        Character* getMainCharacter() const;
        /**
         * moveMainCharacter function: sets location pointer of the main character pointing
         * at the new location object.
         * @param newLocation - Location* - new location pointer.
         */
        void moveMainCharacter(Location* newLocation);
        
    private:
        vector<Location*> locations;
        Location* currentLocation;
        vector<Character*> characters;
        Character* mainCharacter;
        Control* control;
        vector<Item*> items;
        
        /**
         * loadGameData function: call all the function that are responsible
         * for loading data into the game.
         */
        void loadGameData();
        /**
         * loadLocations function reads data from "locations.txt" to create and initialize
         * Location objects in the locations vector. Each line in the file represents a location
         * with a unique name, description, and a list of directional connections to other locations.
         * Expected file format:
         * Each line in "locations.txt" should be structured as follows:
         *     LocationName|Description|Direction-ConnectedLocation,Direction-ConnectedLocation,...|
         */
        void loadLocations();
        /** 
         * loadControl function: loads actions data from "control.txt" to create and initialize
         * Action objects for the actions vector of the Control object.
         * Expected file format:
         *      ActionName|target, target,...|
         */
        void loadControl();   
        /**
         * loadCharacters function: loads characters data from the "characters.txt" file 
         * and assigns initial location variable values to each character object.
         * Expected file format:
         *      CharacterName|Location|
         */
        void loadCharacters(); 
        /**
         * loadItems function: loads idems data from "items.txt" and assigns thems into 
         * specified locations.
         * Expected file format:
         *      LocationName|item, item,...|
         */
        void loadItems();
        /**
         * isEndGame function: checks for win/lose conditions based on user location 
         * in the game.
         * @return true/false - true is the game has ended, false otherwise.
         */
        bool isEndGame();
};

#endif
