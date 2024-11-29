#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include "Action.h"
#include "Location.h"

using namespace std;

class Game;

/**
 * @class Control: handles processing player comands and managing interactions
 * in the game.
 */
class Control 
{
    public:
        /**
         * Control constructor: constructs a control object for a specified 
         * game instance.
         * @param game - Game - the game object that the Control will operate on.
         */
        Control(Game& game);
        /**
         * processCommand function: processes player command strings, determining 
         * and executing actions.
         * * @param command - string - the player’s command as a string.
         */
        void processCommand(const string& command);
        /**
         * addAction function: adds a valid action to the list of actions the 
         * player can execute.
         * * @param action - Action* - the Action object to add.
         */
        void addAction(Action* action);
        /**
         * description function: formats and returns a descriptive string of the 
         * player's current location, characters present, exits available, and 4
         * items in both player inventory and location.
         * @return description - string - a formatted description string of the 
         * current scene.
         */
        string description() const;
        /**
         * showActions function: prints out action name and target for each action. 
         */
        void showActions();
        /**
         * executeAction function: calls corresponding commands for each action 
         * requested by the user, acts as the main switchboard of the game.
         * @param action - Action - action object to be executed.
         */
        void executeAction(const Action& action);
        
    private:
        Game& game;
        vector<Action*> actions;
        Inventory inventory;
        Item* item; 
        Location* currentLocation;
};

#endif
