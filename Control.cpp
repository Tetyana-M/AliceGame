#include "Control.h"
#include "Game.h"
#include <iostream>
#include <sstream>

Control::Control(Game& game) : game(game) {}

void Control::startGame() 
{
    // At the start of the game set carrunt location to Rabbit Hole.
    //setCurrentLocation("Rabbit Hole");
    //std::string input;
    //std::cout << "Enter an action: ";
    //while (std::cin >> input) {
    //    handleInput(input);
    //    std::cout << "Enter an action: ";
   // }
}

void Control::addAction(Action* action) 
{
    actions.push_back(action);
}

void Control::executeAction(const Action& action) 
{
    Location* currentLocation = game.getCurrentLocation();
        
    if (action.getName() == "exit" || action.getName() == "quit")
    {
        cout << "\nGood bye!\n" << endl;
        exit(0);
    }
    else if (action.getName() == "go") 
    {
        string targetLocationDirection = action.getTarget(); 
        Location* exitLocation = currentLocation->getExit(targetLocationDirection);
        if(exitLocation)
        {
            game.setCurrentLocation(exitLocation);
            // Move main character.
            game.moveMainCharacter(exitLocation);
            cout << "You are at: " << game.getCurrentLocation()->getName() << endl;
        }
        else
        {
            cout << "You can't go that way." << endl;
        }
    } 
    else if(action.getName() == "show")
    {
        string showTarget = action.getTarget(); 
        if(showTarget == "location")
        {
            currentLocation->describe();
        }
        else if(showTarget == "characters")
        {
            vector<Character*> presentCharacters = currentLocation->getCharacters();
            for (auto it = presentCharacters.begin(); it != presentCharacters.end(); ++it)
            {
                cout << (*it)->getName() << endl;
            }       
        }
    }
    else if (action.getName() == "take") 
    {
        cout << "You take the " << action.getTarget() << ".\n";
        // Add item to inventory here
    } 
    else if (action.getName() == "drop") 
    {
        cout << "You drop the " << action.getTarget() << ".\n";
        // Remove item from inventory here
    } 
    else 
    {
        cout << "Action not implemented.\n";
    }
};

void Control::processCommand(const string& command) 
{
    istringstream stream(command);
    string name, target;
    bool actionFound = false;
    stream >> name >> target;
    for (auto it = actions.begin(); it != actions.end(); ++it)
    {
        Action* action = *it;
        string actionName = action->getName();
        string actionTarget = action->getTarget();
        if (actionName == name && actionTarget == target) 
        {
            executeAction(*action);
            actionFound = true;
            break;
        }
    }
    if(!actionFound)
    {
        cout << "Wrong command, try again!" << endl;
    }
}

void Control::handleInput(const std::string& input) {
    if (input == "take") {
        if (item) {
            inventory.addItem(item);
            std::cout << "You took the " << item->getName() << "." << std::endl;
        }
    } else {
        std::cout << "Unknown action!" << std::endl;
    }
}
//void Control::setCurrentLocation(const string& locationName)
//{

//}
