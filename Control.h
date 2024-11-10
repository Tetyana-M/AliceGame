#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include "Action.h"
#include "Location.h"
//#include "Game.h"

using namespace std;

class Game;

class Control 
{
    public:
        Control(Game& game);
        void startGame();
        void handleInput(const string& input);
        void addAction(Action* action);
        void showActions()
        {
            for (auto it = actions.begin(); it != actions.end(); ++it)
            {
                (*it)->showInfo();
            }

        }
        void executeAction(const Action& action);
        void processCommand(const string& command);
        
    private:
        Game& game;
        vector<Action*> actions;
        Inventory inventory;
        Item* item; 
        Location* currentLocation;
};

#endif
