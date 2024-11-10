#include "Game.h"
#include "Control.h"
#include "Action.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

Game::Game() : currentLocation(nullptr), control(new Control(*this))
{
    //control = new Control(*this);
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
    cout << "\nWelcome to Wonderland! Your goal is to find and collect treasures." << endl;
    cout << "You are at: " << currentLocation->getName() << endl;
    control->startGame();
    string command;
    while (true)
    {
        cout << "Enter command: ";
        getline(cin, command);
        control->processCommand(command);
    }
}

void Game::loadGameData() 
{
    loadLocations();
    loadControl();
    //loadItems();
    loadCharacters();
}

/**
 * The loadLocations() function reads data from "locations.txt" to create and initialize
 * Location objects in the locations vector. Each line in the file represents a location
 * with a unique name, description, and a list of directional connections to other locations.
 * 
 * Expected file format:
 * Each line in "locations.txt" should be structured as follows:
 * 
 *     LocationName|Description|Direction-ConnectedLocation,Direction-ConnectedLocation,...|
 */
void Game::loadLocations() 
{
    ifstream file("locations.txt");
    if (!file.is_open()) {
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
/**
 * 
 */
void Game::loadControl()
{
    ifstream file("control.txt");
    if (!file) {
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
    //control->showActions();
}

const vector<Location*>& Game::getLocations() const 
{
    return locations;
}

Location* Game::getCurrentLocation() const 
{
    return currentLocation;
}
/**
 * 
 */
void Game::setCurrentLocation(Location* location)
{
    currentLocation = location;
}
/* 
void Game::loadItems() {
    std::ifstream file("items.txt");
    std::string line;
    while (std::getline(file, line)) {
        items.push_back(std::make_unique<Item>(line)); 
    }
}
*/
void Game::loadCharacters() {
    ifstream file("characters.txt");
    if (!file) {
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
        string name, locationName;

        // Parse name, description, and connections.
        getline(stream, name, '|');
        getline(stream, locationName, '|');

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
        Character* newCharacter = new Character(name, characterLocation);
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
