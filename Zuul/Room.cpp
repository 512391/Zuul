#include<iostream>
#include <cstring>
#include "./Room.h"
#include <vector>
#include <map>

using namespace std;
using namespace Zuul;
Room::Room(char* title)
{
  Room::amountOfItems = 0;
  strcpy(Room::name, title);

  char north[6] = "North";
  Room::directionToWord[North] = north;

  char south[6] = "South";
  Room::directionToWord[South] = south;

  char west[6] = "West";
  Room::directionToWord[West] = west;

  char east[6] = "East";
  Room::directionToWord[East] = east;

}

void Room::getName(char* out)
{
  strcpy(out, Room::name);
}

bool Room::canDrop()
{
  if(Room::amountOfItems >= Zuul::MAX_ITEMS)
    {
      return false;
    }
  return true;
}

void Room::dropItem(Item* item)
{
  Room::items.push_back(item);
  Room::amountOfItems++;
}

Item* Room::pickupItem(int i)
{
  auto itemToErase = Room::items.begin() + i;
  Item* itemToReturn = Room::items.at(i);
  
  Room::items.erase(itemToErase);
  
  return itemToReturn;
}

void Room::printItems()
{
  int i = 0;
  for(auto& item : items)
    {
      cout << i << ": " << item->name << "\n";
	i++;
    }
}

void Room::addAdjacentRoom(Direction direction, Room* room)
{
  Room::adjacentRooms[direction] = room;
}

void Room::printAdjacentRooms()
{
  map<Direction, Room*>::iterator it = Room::adjacentRooms.begin();

  while (it != Room::adjacentRooms.end()) {
    cout << Room::directionToWord[it->first] << ": " << it->second->name << endl;
        ++it;
    }
}

Room* Room::getAdjacentRoom(Direction direction)
{
  return Room::adjacentRooms[direction];
}
