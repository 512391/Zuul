#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include<iostream>
#include <map>

namespace Zuul
{
  const int MAX_ITEMS = 5;

  struct Item
  {
     char name[10];
     bool winner;
  };

  enum Direction
    {
      North,
      South,
      East,
      West
    };

  class Room
  {
    protected:
      char name[25];
      std::vector<Item*> items;
      int amountOfItems;
      std::map<Direction, Room*> adjacentRooms;
    std::map<Direction, char*> directionToWord;
    
    public:
    Room(char* title);
      void getName(char* out);
      bool canDrop();
      void dropItem(Item* item);
      Item* pickupItem(int i);
      void printItems();
      void addAdjacentRoom(Direction direction, Room* room);
      void printAdjacentRooms();
      Room* getAdjacentRoom(Direction direction);
  };
}

#endif
