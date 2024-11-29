#include "Control.h"
#include "Game.h"
#include <iostream>
#include <sstream>

Control::Control(Game& game) : game(game) {}

void Control::addAction(Action* action) 
{
    actions.push_back(action);
}

void Control::executeAction(const Action& action) 
{
    Location* currentLocation = game.getCurrentLocation();
    Character* mainCharacter = game.getMainCharacter();
    string actionName = action.getName();
    string actionTarget = action.getTarget(); 
        
    if (actionName == "exit" || actionName == "quit")
    {
        cout << "\nGood bye!\n" << endl;
        exit(0);
    }
    else if (actionName == "help")
    {
        cout << "List of all commands:" << endl;
        showActions();
    }
    else if (actionName == "go") 
    {
        Location* exitLocation = currentLocation->getExit(actionTarget);
        if(exitLocation)
        {
            game.setCurrentLocation(exitLocation);
            // Move main character.
            game.moveMainCharacter(exitLocation);
            cout << "You are at the " << game.getCurrentLocation()->getName() << endl;
        }
        else
        {
            cout << "You can't go that way." << endl;
        }
    }
    else if (actionName == "say")
    {
        vector<Character*> allCharacters = currentLocation->getCharacters();
        for (auto it = allCharacters.begin(); it != allCharacters.end(); ++it)
        {
            Character* character = (*it);
            if(character->getName() != game.getMainCharacter()->getName())
            {
                cout << character->getName() << " says \"" << character->respondToGreeting(actionTarget) << "\"" << endl;
            }
        }
    }
    else if(actionName == "show")
    {
        if(actionTarget == "location")
        {
            currentLocation->describe();
        }
        else if(actionTarget == "characters")
        {
            vector<Character*> allCharacters = currentLocation->getCharacters();
            for (auto it = allCharacters.begin(); it != allCharacters.end(); ++it)
            {
                Character* character = (*it);
                cout << character->getName() << ": " << character->describeSelf() << endl;
            }
        }
        else if(actionTarget == "items")
        {
            currentLocation->showInventory();
            mainCharacter->showInventory();
        }
    }
    else if (actionName == "take") 
    {
        mainCharacter->takeItem(actionTarget, currentLocation);
    } 
    else if (actionName == "drop") 
    {
        mainCharacter->dropItem(actionTarget, currentLocation);
    } 
    else if (actionName == "describe")
    {
        cout << description();

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

string Control::description() const 
{
    ostringstream description;

    // Get main character details
    Character* mainCharacter = game.getMainCharacter();
    Location* currentLocation = mainCharacter->getCurrentLocation();
    
    // Start description with character's name and current location
    description << "Ah, dear " << mainCharacter->getName() << "! Here you find yourself at the " 
                << currentLocation->getName() << ".\n" << currentLocation->getDescription() << "\n";

    // List exits
    const auto& exits = currentLocation->getExits();
    if (!exits.empty()) 
    {
        description << "Look around, and you'll see the path";
        if (exits.size() > 1) 
        {
            description << "s";
        } 
        description << " ";
        bool first = true;
        for (const auto& exit : exits) 
        {
            if (!first) 
            {
                description << ", ";
            }
            description << exit;
            first = false;
        }
        description << ".\n";
    } 
    else 
    {
        description << "Alas, there are no exits here—no choice but to linger a while longer.\n";
    }

    // List other characters at the location
    const auto& characters = currentLocation->getCharacters();
    string otherCharacters;
    bool firstCharacter = true;
    for (const auto& character : characters) 
    {
        if (character != mainCharacter) 
        { // Exclude main character from the list
            if (!firstCharacter) 
            {
                otherCharacters += ", ";
            }
            otherCharacters += character->getName();
            firstCharacter = false;
        }
    }
    if (!otherCharacters.empty()) 
    {
        description << "You are not alone, dear " << mainCharacter->getName() << "! " 
                    << (characters.size() > 2 ? "In the shadows, we spot " : "With you stands ") 
                    << otherCharacters << ".\n";
    }

    // List items in main character's inventory
    description << "In your pockets, you carry ";
    const auto& inventoryItems = mainCharacter->getInventory();
    if (!inventoryItems.empty()) 
    {
        bool firstItem = true;
        for (const auto& item : inventoryItems) 
        {
            if (!firstItem) 
            {
                description << ", ";
            }
            description << item->getName();
            firstItem = false;
        }
    } 
    else 
    {
        description << "nothing but dreams";
    }
    description << ".\n";

    // List items available at the location
    description << "Here at the " << currentLocation->getName() << ", you spy ";
    const auto& locationItems = currentLocation->getInventory().getInventoryItems();
    if (!locationItems.empty()) 
    {
        bool firstLocationItem = true;
        for (const auto& item : locationItems) 
        {
            if (!firstLocationItem) 
            {
                description << ", ";
            }
            description << item->getName();
            firstLocationItem = false;
        }
        description << ".\n";
    } 
    else 
    {
        description << "nothing but whispers and shadows.\n";
    }
    
    return description.str();
}

void Control::showActions()
{
    for (auto it = actions.begin(); it != actions.end(); ++it)
    {
        cout << (*it)->getName() << " " << (*it)->getTarget() << endl;
    }

}
