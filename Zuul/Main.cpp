#include <iostream>
#include "./Room.h"
#include "./Player.h"
#include "./Parser.h"

using namespace std;
using namespace Zuul;

Parser parser;
Room* rooms[15];

void processInput(Player* player)
{
  parser.inputWords(cin.getline());

  if(strcmp(parser.getFirstWord(), "go") == 0)
    {
      if(strcmp(parser.getSecondWord(), "North") == 0)
	{
	  player->move(Direction.North);
	}
      else if(strcmp(parser.getSecondWord(), "South") == 0)
        {
          player->move(Direction.South);
        }
      else if(strcmp(parser.getSecondWord(), "East") == 0)
        {
          player->move(Direction.West);
        }
      else if(strcmp(parser.getSecondWord(), "West") == 0)
        {
          player->move(Direction.NORTH);
        }
    }

  if(strcmp(parser.getFirstWord(), "quit") == 0)
    {
      exit(0);
    }

  if(strcmp(parser.getFirstWord(), "pickup") == 0)
    {
      if(player->canPickup())
	{
	  player->pickup(parser.getSecondWord[0] - '0')
	}
    }

  if(strcmp(parser.getFirstWord(), "drop") == 0)
    {
      
    }
}

void makeRooms()
{
  
}

int main()
{
  Player* player = new Player(rooms[0]);
}


