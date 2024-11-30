**Overview**

"Wonderland" is an interactive game inspired by "Alice in Wonderland".  Players control 
Alice, explore locations and collect items to complete a specific goal.  The game 
emphasizes exploration, puzzle-solving, and inventory management as players navigate 
Wonderland. 

**Game Concept**

The objective is for Alice to explore Wonderland, interact with characters, and gather items.  Alice must place all collected items in the "Safe Room" and then reach the "Queen’s Court" 
to win. If Alice reaches the Queen’s Court without placing all items in the Safe Room, she 
loses. This goal encourages exploration and planning. 


**Gameplay Mechanics** 
<ul>
<li>Exploration<br>
Alice moves between locations using commands like "go north" or "go east." Exits 
connect the locations in Wonderland, which player explores to locate characters 
and items. </li>
<li>Interactions<br> 
Alice encounters different characters at each location. Player can discover what 
characters are present at each location by issuing a “say Hello” command and 
watching what character responds to the greeting. Another way to discover what 
characters are present at the scene is by entering “show characters” command or 
“describe” command. </li>
<li>Inventory System<br> 
Alice can take items from a location’s inventory and drop items into a location’s 
inventory. Each character maintains an inventory of items they hold, as well as each 
location maintains an inventory of items. A character and inventory can exchange 
items by issuing “take <item>” or “drop <item>” commands.  When a character 
takes an item, the item is removed from the location’s inventory and added to the 
character's inventory, when a player drops an item, it is removed from the player's 
inventory and added to the location’s inventory. To check what items are available 
for taking or dropping at any point in the game a player can issue “show items” 
command and the items in each character and location inventory will be displayed. </li>
<li>Win and Lose Conditions<br> 
Reaching the Queen’s Court with all items in the Safe Room triggers a win. Reaching 
the Queen's Court without all items in the Safe Room triggers a loss. </li>
<li>Narrative Feedback <br>
The game provides whimsical descriptions of Alice’s surroundings and characters at 
each location, enhancing immersion and entertaining the player. </li>
</ul>

**Compiling and Running the Game** 

To compile the game place all the .cpp, .h, and .txt files in the same folder,  and then run 
this command:  <br>
<code>g++ -o Wonderland main.cpp Action.cpp Character.cpp Control.cpp 
Game.cpp Inventory.cpp Item.cpp Location.cpp </code><br>
Execution:  
<code>Wonderland </code><br>
A complete list of files that make up the game: 
main.cpp,  
Action.cpp,  
Action.h,  
Character.cpp,  
Character.h,  
Control.cpp,  
Control.h,  
Game.cpp,  
Game.h,  
Inventory.cpp,  
Inventory.h,  
Item.cpp,  
Item.h,  
Location.cpp,  
Location.h,  
characters.txt,  
control,txt,  
items.txt,  
locations.txt

**Map of locations**

The map of locations is defined in locatins.txt. Each location is represented with a ‘|’ 
separated line, where the first item is the name of the location, second item is the 
description, and the third is comma separated list of exits, where each exit is represented 
with a <code>\<direction>-\<name of the location></code>. For example, the Hall of Doors location is 
defined with: <br>
<code>Hall of Doors|A grand hallway filled with doors of various sizes.|south-Garden,east-Tea Party,north-Safe Room| </code><br>
Where, “Hall of Doors” is the name, “A grand hallway filled with doors of various sizes.” Is the description, and “south-Garden,east-Tea Party,north-Safe Room” is the list of exits, where for example “south-Garden” represents exit to the Garden location in the south direction. 
<P>
The content of  the default locations.txt: <br>
<code>Rabbit Hole|A dark, narrow entrance leading down into Wonderland. Once you descend, there's no going back.|down-Hall of Doors,| <br>
Hall of Doors|A grand hallway filled with doors of various sizes.|south-Garden,east-Tea Party,north-Safe Room| <br>
Garden|A beautiful garden with vibrant flowers and curious creatures.|north-Hall of Doors,east-Queen's Court| <br>
Tea Party|A long table set for tea, complete with mismatched teapots, cups, and saucers.|west-Hall of Doors,south-Queen's Court| <br>
Queen's Court|An opulent courtroom where the Queen of Hearts rules.|| <br>
Safe Room|Safe storage room.|south-Hall of Doors| </code>
<p>
To add a location to the map we modify the locations.txt. For example, let’s add a location, Black Forest,  that is to the east from the Safe Room and north from the Tea Party, the player can exit from the safe Room to the Black Forest, but they can not go back, and the player can go back and forth between the Safe Room and Black Forest. 
To achieve that we add a line to the locations.txt: <br>
<code>Black Forest|A shadowy maze of gnarled trees and whispered secrets, where enchantment and mystery lurk in every shadowy corner.|south-Tea Party| </code><br>
As well as two new exits, from the Safe Room, <code>east-Black Forest</code>, and from the Tea 
Party, <code>north-Black Forest</code>. <p>
The next time the game is started the updated locations.txt is loaded in and the new 
location becomes part of the game. 
