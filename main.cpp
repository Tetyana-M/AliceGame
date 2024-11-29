/* 
 Title: Wonderland Game
 Description: a whimsical, interactive game inspired by the world of "Alice in Wonderland."
 Date: November 16, 2024
 Author: Tetyana Manuylenko
 Version: 1.0
 Copyright: 2024 Tetyana Manuylenko
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate use of object oriented principals in game design.
 	Also demonstrate practical use of the COMP306 learning material.

 Compile (assuming Cygwin is running): g++ -o Wonderland main.cpp Action.cpp Character.cpp Control.cpp Game.cpp Inventory.cpp Item.cpp Location.cpp
 Execution (assuming Cygwin is running): Wonderland

 Game technical design and implementation documentation can be found in 
 the Asignment4_DesignDocument.pdf that is submitted with this assignment.
*/

/*
 TEST PLAN
 
Testing game initialization:
 - Start the game and check if Alice appears at the starting location defined in
 - characters.txt.
 - Cross-check location descriptions, exits, and initial inventories listed in 
   locations.txt and items.txt with "show location" and "show items" commands.
 - Confirm that all commands in control.txt are recognized during gameplay.
 - type in "help" command to see the list of all possible commands, cross-check 
   the commands against ones in control.txt.
 - type in invalid command, e.g. "ds fgh" to veryfy the game displays an error message.
Testng location exploration:
 - Move Alice in valid directions using commands like "go north" or "go east".
 - Confirm that Alice arrives at the correct connected location using "show location".
 - Attempt movement in an invalid direction (e.g., "go up" if no upward direction exists
   and "go east" if no east exit exists).
   Verify the game displays an error message like "You can't go that way."
 - Check location descriptions to ensure they match locations.txt data with 
   "description" command.
 - Navigate through multiple locations and return to previous locations to confirm
   exits work correctly in both directions.
Character initialization:
 - At each location type "say Hi" or "say Hello" and confirm a character present at
   that location responds with "Hello" or "Hi".
 - At each location type in "show characters" to ensure the present characters 
   provide a correct description.
 - Cross-check the characters and their description with the characters.txt.
Inventory management:
 - Use "show items" command to see inventory at the current location and in Alice's
   posession at each location.
 - Visit each location and cross-check the items present with the data in items.txt.   
 - Use "take <item>" command to pick up an item from a location.
 - Verify the item moves to Alice’s inventory and is removed from the location’s 
   inventory with the "show items" command and "describe command".
 - Use "drop <item> command to drop an item from Alice’s inventory.
 - Confirm the item appears in the location’s inventory and is removed from Alice’s
   inventory with the "show items" command and "describe command".
 - Attempt to take an item that does not exist or is not at the location to confirm
   that the game displays an error message.
Command processing:
 - Test all valid commands listed in control.txt and confirm each command executes
   its intended action.
 - Enter invalid commands (e.g., gibberish or unsupported commands) and verify
   the game displays an appropriate error message.
Win and lose conditions:
 - Place all items in the Safe Room and move Alice to the Queen’s Court. Confirm 
   the game ends with a win message.
 - Move Alice to the Queen’s Court without placing all items in the Safe Room. 
   Confirm the game ends with a lose message like.
Modifying configuration files:
 - Add a new location:
    - Modify locations.txt:
        - Add this line:
        Black Forest|A shadowy maze of gnarled trees and whispered secrets, where enchantment and mystery lurk in every shadowy corner.|south-Tea Party| 
        - Add two new exits, from the Safe Room: east-Black Forest 
         and from the Tea Party: north-Black Forest.
    - Restart the game and repeat testing steps above to veryfy the new Black Forest
      location is a part of the game.
 - Add a new character:
    - Modify characters.txt:
        - Add this line:
        Caterpillar|Black Forest|An enigmatic figure, the Caterpillar lounges on a mushroom, puffing smoke and offering cryptic, thought-provoking wisdom.|
    - Restart the game and repeat testing charater steps above to veryfy the new character
      is a part of the game.    
 - Add a new item to the inventory:
    - Modify items.txt:
        - Add this line:
        Black Forest|pipe|
    - Modify control.txt:
        - Add pipe to the take and drop commands.
    - Restart the game and repeat testing steps above, especially testing
      win and lose conditions, to veryfy the new item is a part of the game.  
 - Test removing characters, locations and items from the game by removing 
   corresponding records from the configuration files.
*/

#include "Game.h"

int main() 
{
    Game game;
    game.play();
    return 0;
};
