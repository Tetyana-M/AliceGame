#include "Game.h"
#include "Control.h"
#include "Action.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <memory>

Game::Game() : currentLocation(nullptr), control(new Control(*this))
{
    loadGameData();
    // Set initial location to "Rabbit Hole", which is the first item on the 
    // list of locations.
    if (!locations.empty()) 
    {
        currentLocation = locations[0]; 
    }
    else
    {
        cerr << "Error: Failed to load locations." << endl;
        exit(0);
    }
}

void Game::play() 
{
    cout << "\nWelcome, dear Alice, to the land of whimsy and wonder!\n";
    cout << "Your quest is clear: gather all treasures scattered across Wonderland and\n";
    cout << "deliver them to the Safe Room. But beware! Only when all items are\n";
    cout << "safely placed in the Safe Room and you find yourself at the Queen's Court\n";
    cout << "shall you be deemed victorious. Fail to secure every treasure, and alas,\n";
    cout << "even if you reach the Queens Court, the game is lost. Good luck, Alice!\n\n";

    cout << "\nYou are at: " << currentLocation->getName() << endl;
    string command;
    while (true)
    {
        cout << "\nEnter command: ";
        getline(cin, command);
        control->processCommand(command);

        if (isEndGame()) 
        {
            break; // End the game if win or lose conditions are met
        }
    }
}

void Game::loadGameData() 
{
    loadLocations();
    loadControl();
    loadItems();
    loadCharacters();
}

void Game::loadLocations() 
{
    ifstream file("locations.txt");
    if (!file.is_open()) 
    {
        cerr << "Error: Could not open locations.txt" << endl;
        return;
    }

    string line;
    int locationCount = 0;

    // Count the number of locations.
    while (getline(file, line)) 
    {
        locationCount++;
    }

    // Pre-allocate space in the vector.
    locations.resize(locationCount);

    // Reset file to read locations again.
    file.clear();
    file.seekg(0);

    // Create each Location and assign to vector by index.
    int index = 0;
    while (getline(file, line) && index < locationCount) 
    {
        istringstream stream(line);
        string name, description, connections;

        // Parse name, description, and connections.
        getline(stream, name, '|');
        getline(stream, description, '|');
        
        // Create a new Location and assign it to the vector by index.
        locations[index] = new Location(name, description);
        index++;
    }

    // Reset file to read connections
    file.clear();
    file.seekg(0);

    // Establish connections between locations.
    index = 0;
    while (getline(file, line) && index < locationCount) 
    {
        istringstream stream(line);
        string name, description, connections;

        getline(stream, name, '|');
        getline(stream, description, '|');
        getline(stream, connections, '|');

        // Get current Location pointer.
        Location* currentLocation = locations[index]; 

        // Parse each connection in the format "direction-connectedLocation".
        istringstream connStream(connections);
        string connection;
        while (getline(connStream, connection, ',')) 
        {
            size_t dashPos = connection.find('-');
            if (dashPos != string::npos) 
            {
                string direction = connection.substr(0, dashPos);
                string connectedLocationName = connection.substr(dashPos + 1);
                // Find the connected location by name.
                Location* connectedLocation = nullptr;
                for (const auto& location : locations) 
                {
                    if (location->getName() == connectedLocationName) 
                    {
                        connectedLocation = location;
                        break;
                    }
                }

                // Add the exit to currentLocation if the connected location was found.
                if (connectedLocation) 
                {
                    currentLocation->addExit(direction, connectedLocation);
                }
            }
        }
        index++;
    }
}

void Game::loadControl()
{
    ifstream file("control.txt");
    if (!file) 
    {
        cerr << "Error: Could not open control.txt" << endl;
        return;
    }

    string line;
    int actionCount = 0;

    // Count the number of actions.
    while (getline(file, line)) 
    {
        actionCount++;
    }
    // Reset file to read locations again.
    file.clear();
    file.seekg(0);

    // Create each action and assign to vector by index.
    int index = 0;
    while (getline(file, line) && index < actionCount) 
    {
        istringstream stream(line);
        string name, targets;

        // Parse name, description, and connections.
        getline(stream, name, '|');
        getline(stream, targets, '|');
 
        // Split targets by comma and create Action objects.
        istringstream targetStream(targets);
        string target;
        if (targetStream.str().empty())
        {
            Action* newAction = new Action(name, "");
            control->addAction(newAction);
        }
        else
        {
            while (getline(targetStream, target, ',')) 
            {
                Action* newAction = new Action(name, target);
                control->addAction(newAction);
            }
        }
    }
}

Location* Game::getCurrentLocation() const 
{
    return currentLocation;
}

void Game::setCurrentLocation(Location* location)
{
    currentLocation = location;
}
 
void Game::loadItems() 
{
    ifstream file("items.txt");
    if (!file) 
    {
        cerr << "Error: Could not open items.txt" << endl;
        return;
    }
    string line;
    while (getline(file, line)) 
    {
        istringstream stream(line);
        string locationName, itemsList;

        // Parse location and items
        getline(stream, locationName, '|');
        getline(stream, itemsList, '|');

        // Find location by name
        Location* location = nullptr;
        for (const auto& loc : locations) 
        {
            if (loc->getName() == locationName) 
            {
                location = loc;
                break;
            }
        }
        if (!location) 
        {
            cerr << "Location " << locationName << " not found." << endl;
            continue;
        }

        // Add items to the location’s inventory
        istringstream itemsStream(itemsList);
        string itemName;
        while (getline(itemsStream, itemName, ',')) 
        {
            Item* item = new Item(itemName);
            items.push_back(item); 
            location->getInventory().addItem(item);
        }
    }
}

void Game::loadCharacters() 
{
    ifstream file("characters.txt");
    if (!file) 
    {
        cerr << "Error: Could not open characters.txt" << endl;
        return;
    }

    string line;
    int characterCount = 0;
    // Count the number of characters.
    while (getline(file, line)) 
    {
        characterCount++;
    }
    // Reset file to read characters again.
    file.clear();
    file.seekg(0);

    // Create each character and assign to vector by index.
    int index = 0;
    while (getline(file, line) && index < characterCount) 
    {
        istringstream stream(line);
        string name, locationName, description;

        // Parse name, description, and connections.
        getline(stream, name, '|');
        getline(stream, locationName, '|');
        getline(stream, description, '|');

        Location* characterLocation;

        // Get a location object for this location.
        for (auto it = locations.begin(); it != locations.end(); ++it)
        {
            Location* location = (*it);
            if (location->getName() == locationName)
            {
                characterLocation = location;
                break;
            }
        }
 
        // Create Character objects.
        Character* newCharacter = new Character(name, characterLocation, description);
        // Add them to characters array.
        characters.push_back(newCharacter);
        // Add character to its location.
        characterLocation->addCharacter(newCharacter);
        // If the character is Alice assign the main character pointer to her.
        if (name == "Alice")
        {
            mainCharacter = newCharacter;
        }
    }
}

void Game::moveMainCharacter(Location* newLocation)
{
    Location* oldLocation = mainCharacter->getCurrentLocation();
    mainCharacter->setCurrentLocation(newLocation);
    newLocation->addCharacter(mainCharacter);
    oldLocation->removeCharacter(mainCharacter);
}

Character* Game::getMainCharacter() const
{
    return mainCharacter;
}

bool Game::isEndGame() 
{
    // Identify the Safe Room and Queen's Court by their names
    Location* safeRoom = nullptr;
    Location* queensCourt = nullptr;
    
    for (const auto& location : locations) 
    {
        if (location->getName() == "Safe Room") 
        {
            safeRoom = location;
        } 
        else if (location->getName() == "Queen's Court") 
        {
            queensCourt = location;
        }
    }

    if (!safeRoom || !queensCourt) 
    {
        cerr << "Error: Safe Room or Queen's Court not found." << endl;
        return false;
    }

    // Check if Alice is at the Queen's Court
    if (mainCharacter->getCurrentLocation() == queensCourt) 
    {
        // Check if all items are in the Safe Room
        bool allItemsInSafeRoom = true;
        for (const auto& item : items) 
        {
            if (safeRoom->getInventory().getItem(item->getName()) == nullptr) 
            {
                allItemsInSafeRoom = false;
                break;
            }
        }

        if (allItemsInSafeRoom) 
        {
            cout << "\nCongratulations, dear Alice! You have triumphed gloriously!\n";
            cout << "All treasures rest safely in the Safe Room, and you stand victorious\n";
            cout << "before the Queen!\n";
            cout << "\nYou won!\n" << endl;
            return true; // Win condition met
        } 
        else 
        {
            cout << "\nAlas, dear Alice, your journey ends in sorrow.\n";
            cout << "Though you have reached the Queen's Court, not all treasures\n";
            cout << "rest in the Safe Room. The Queen is displeased...\n";
            cout << "\nYou lost!\n" << endl;
            return true; // Lose condition met
        }
    }
    
    return false; // Game continues
}