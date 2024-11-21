#include <iostream>
#include <cstring>
#include "./Room.h"
#include "./Player.h"
#include "./Parser.h"

using namespace std;
using namespace Zuul;

/*
  author: jay williamson
  date: 11/21/2024
  this si the main class that is responsible for the overall gameplay of the game
 */

//this funciton processes the input
void processInput(Player* player)
{
  //makes a parser
  Parser parser;

  //gets input
  char input[17];
  cin.getline(input, 17);
  parser.inputWords(input);

  char firstWord[7];
  char secondWord[10];

  //seperates the input
  parser.getFirstInput(firstWord);
  parser.getSecondInput(secondWord);

  //checks the first word
  //if it is go it checks which direction and moves the player
  if(strcmp(firstWord, "go") == 0)
    {
      if(strcmp(secondWord, "North") == 0)
	{
	  player->move(North);
	}
      else if(strcmp(secondWord, "South") == 0)
        {
          player->move(South);
        }
      else if(strcmp(secondWord, "East") == 0)
        {
          player->move(East);
        }
      else if(strcmp(secondWord, "West") == 0)
        {
          player->move(West);
        }
    }
  //checks if the player is quitting
  if(strcmp(firstWord, "quit") == 0)
    {
      //exits the program
      exit(0);
    }

  //checks if you want to pickup
  if(strcmp(firstWord, "pickup") == 0)
    {
      //checks if you can pickup
      if(player->canPickup())
	{
	  //picks up
	  player->pickup(secondWord[0] - '0');
	}
    }
  //checks if you want to drop something
  if(strcmp(firstWord, "drop") == 0)
    {
      //drops it into the room
      player->drop(secondWord[0] - '0');
    }
  //checks if you want to print all your stats
  if(strcmp(firstWord, "print") == 0)
    {
      //prints all of the stats
      cout << "inventory \n";
      player->printInventory();
      cout << "Items in room \n";
      player->currentRoom->printItems();
      cout << "Adjacent Rooms \n";
      player->currentRoom->printAdjacentRooms();
      cout << "\n";
    }
  //checks if you need help
  if(strcmp(firstWord, "help") == 0)
    {
      //gives a spiel about the controls
      cout << "So heres the deal" << endl;
      cout << "you can say go (North, South, East, West) to move" << endl;
      cout << "you can also say pickup (0, 1, 2, 3 etc) based on the number next to the thing you want to pick up" << endl;
      cout << "the same goes for drop" << endl;
      cout << "print will print you inventory, the items in the room, and the exits" << endl;
      cout << "and help is always here" << endl;
    }
}

//this makes all the rooms and returns the starting room
Room* makeRooms()
{
  Room* rooms[15];

  //names of the rooms
  char names[15][25] = {"parking lot", "lobby", "ticket booth", "dinosaur exhibit", "planetarium", "planes exhibit", "bathroom"
			, "secret room", "security room", "gift shop", "after party", "ww2 exhibit", "modern art exhibit"
			, "lights exhibit", "marine exhibit"};
  //creates all of the rooms
  rooms[0] = new Room(names[0]);
  rooms[1] = new Room(names[1]);
      rooms[2] = new Room(names[2]);

  rooms[3] = new Room(names[3]);
rooms[4] = new Room(names[4]);
rooms[5] = new Room(names[5]);
rooms[6] = new Room(names[6]);
 rooms[7] = new Room(names[7]);
rooms[8] = new Room(names[8]);
rooms[9] = new Room(names[9]);
rooms[10] = new Room(names[10]);
rooms[11] = new Room(names[11]);
rooms[12] = new Room(names[12]);
rooms[13] = new Room(names[13]);
rooms[14] = new Room(names[14]);

//item names
 char itemNames[5][10] = {"key", "pencil", "umbrella", "bench", "grinch"};

 //creates all the items
 Item* key = new Item(itemNames[0], true);
 Item* pencil = new Item(itemNames[1], false);
Item* umbrella = new Item(itemNames[2], false);
Item* bench = new Item(itemNames[3], false);
Item* grinch = new Item(itemNames[4], false);

//assigns all the items to rooms
 rooms[8]->dropItem(key);
 rooms[4]->dropItem(pencil);
rooms[10]->dropItem(umbrella);
rooms[2]->dropItem(bench);
rooms[13]->dropItem(grinch);


//makes win condition of needing key to get into the after parts
 rooms[10]->needKey = true;

 
 //the rest of the functions is just assigning exits to the room in accordance to the map
 rooms[0]->addAdjacentRoom(North, rooms[1]);
 
 rooms[1]->addAdjacentRoom(South, rooms[0]);
 rooms[1]->addAdjacentRoom(East, rooms[2]);
 rooms[1]->addAdjacentRoom(North, rooms[3]);

 rooms[2]->addAdjacentRoom(West, rooms[1]);
 
 rooms[3]->addAdjacentRoom(South, rooms[1]);
 rooms[3]->addAdjacentRoom(East, rooms[4]);
 rooms[3]->addAdjacentRoom(North, rooms[11]);
 rooms[3]->addAdjacentRoom(West, rooms[14]);

 rooms[4]->addAdjacentRoom(West, rooms[3]);
 rooms[4]->addAdjacentRoom(North, rooms[5]);
 rooms[4]->addAdjacentRoom(East, rooms[6]);

rooms[5]->addAdjacentRoom(South, rooms[4]);
rooms[5]->addAdjacentRoom(West, rooms[11]);

rooms[6]->addAdjacentRoom(West, rooms[4]);
rooms[6]->addAdjacentRoom(South, rooms[7]);

rooms[7]->addAdjacentRoom(North, rooms[6]);

rooms[8]->addAdjacentRoom(South, rooms[9]);

rooms[9]->addAdjacentRoom(North, rooms[8]);
rooms[9]->addAdjacentRoom(South, rooms[10]);
rooms[9]->addAdjacentRoom(East, rooms[14]);

rooms[10]->addAdjacentRoom(North, rooms[9]);

rooms[11]->addAdjacentRoom(North, rooms[13]);
rooms[11]->addAdjacentRoom(West, rooms[12]);
rooms[11]->addAdjacentRoom(East, rooms[5]);
rooms[11]->addAdjacentRoom(South, rooms[3]);

rooms[12]->addAdjacentRoom(East, rooms[11]);
rooms[12]->addAdjacentRoom(South, rooms[14]);

rooms[13]->addAdjacentRoom(South, rooms[11]);

rooms[14]->addAdjacentRoom(North, rooms[12]);
rooms[14]->addAdjacentRoom(West, rooms[9]);
rooms[14]->addAdjacentRoom(East, rooms[3]);

//returns the first room
 return rooms[0];
}

//main function
int main()
{
  //makes the player and assigns it to the first room
  Player* player = new Player(makeRooms());

  //prints out the intial welcome
  cout << "welcome to Zuul type help to see the controls" <<  endl;
  cout << "find the key and get tot the after party" << endl;

  //asks for player input until win or quit happens
  while(true)
    {
      processInput(player);
    }
}


