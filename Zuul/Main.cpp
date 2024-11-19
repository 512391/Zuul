#include <iostream>
#include <cstring>
#include "./Room.h"
#include "./Player.h"
#include "./Parser.h"

using namespace std;
using namespace Zuul;

Parser parser;
Room* rooms[15];

void processInput(Player* player)
{
  char input[17];
  cin.getline(input, 17);
  parser.inputWords(input);

  char firstWord[7];
  char secondWord[10];

  parser.getFirstInput(firstWord);
  parser.getSecondInput(secondWord);
  
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

  if(strcmp(firstWord, "quit") == 0)
    {
      exit(0);
    }

  if(strcmp(firstWord, "pickup") == 0)
    {
      if(player->canPickup())
	{
	  player->pickup(secondWord[0] - '0');
	}
    }

  if(strcmp(firstWord, "drop") == 0)
    {
      player->drop(secondWord[0] - '0');
    }
  if(strcmp(firstWord, "print") == 0)
    {
      player->printInventory();
      cout << "\n";
      player->currentRoom->printItems();
      cout << "\n";
      player->currentRoom->printAdjacentRooms();
      cout << "\n";
    }
}

void makeRooms()
{
  char names[15][25] = {"parking lot", "lobby", "ticket booth", "dinosaur exhibit", "planetarium", "planes exhibit", "bathroom"
			, "secret room", "security room", "gift shop", "after party", "ww2 exhibit", "modern art exhibit"
			, "lights exhibit", "marine exhibit"};
  Item* items[15][5];
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

 rooms[0]->addAdjacentRoom(North, rooms[1]);
 
 rooms[1]->addAdjacentRoom(South, rooms[0]);
 rooms[1]->addAdjacentRoom(East, rooms[2]);
 rooms[1]->addAdjacentRoom(North, rooms[3]);

 rooms[2]->addAdjacentRoom(South, rooms[1]);
 
 rooms[3]->addAdjacentRoom(South, rooms[1]);
 rooms[3]->addAdjacentRoom(East, rooms[4]);
 rooms[3]->addAdjacentRoom(North, rooms[11]);
 rooms[3]->addAdjacentRoom(West, rooms[14]);

 rooms[4]->addAdjacentRoom(West, rooms[3]);
}

int main()
{
  makeRooms();
  Player* player = new Player(rooms[0]);
}


