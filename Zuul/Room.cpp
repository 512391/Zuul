#include<iostream>
#include <cstring>
#include "./Room.h"
#include <vector>
#include <map>
#include <cstring>

using namespace std;
using namespace Zuul;

/*
  Author: jay williamson
  Date: 11/21/2024
  this class controls the logic of the room
 */

//constructor for items
Item::Item(char* title, bool win)
{
  //assigns name and whether it is the key
  strcpy(Item::name, title);
  Item::winner = win;
}

//constructor for room
Room::Room(char* title)
{
  //assigns variables
  Room::amountOfItems = 0;
  strcpy(Room::name, title);

  //assigns hashmaps of direction to word
  Room::directionToWord[North] = north;
  Room::directionToWord[South] = south;
  Room::directionToWord[West] = west;
  Room::directionToWord[East] = east;
  
}

//gets the name of the room
void Room::getName(char* out)
{
  strcpy(out, Room::name);
}

//checks if the room has any space to drop something
bool Room::canDrop()
{
  //checks if the amount of items it too much
  if(Room::amountOfItems >= Zuul::MAX_ITEMS)
    {
      return false;
    }
  return true;
}

//drops and item into the room
void Room::dropItem(Item* item)
{
  Room::items.push_back(item);
  Room::amountOfItems++;
}

//pickups and item by returning it
Item* Room::pickupItem(int i)
{
  //gets item and its position
  auto itemToErase = Room::items.begin() + i;
  Item* itemToReturn = Room::items.at(i);

  //gets rid of item
  Room::items.erase(itemToErase);
  
  return itemToReturn;
}

//prints the items in the room
void Room::printItems()
{
  int i = 0;
  //iterates thru the items and prints them
  for(auto& item : items)
    {
      cout << i << ": " << item->name << "\n";
	i++;
    }
}

//adds a room in a certain direction
void Room::addAdjacentRoom(Direction direction, Room* room)
{
  Room::adjacentRooms[direction] = room;
}

//prints the rooms near
void Room::printAdjacentRooms()
{
  map<Direction, Room*>::iterator it = Room::adjacentRooms.begin();

  //iterates through the rooms
  while (it != Room::adjacentRooms.end()) {
    //prints out the rooms and their directions in relation to the current room
    cout << Room::directionToWord[it->first] << ": " << it->second->name << endl;
        ++it;
    }
}

//gets an adjacent room in a certain direction
Room* Room::getAdjacentRoom(Direction direction)
{
  return Room::adjacentRooms[direction];
}
