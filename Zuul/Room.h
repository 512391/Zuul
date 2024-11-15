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
      char name[20];
      std::vector<Item> items;
      int amountOfItems;
      std::map<Direction, Room> adjacentRooms;
    
    public:
    //this constructor is just to make an instance and test
      Room();
      Room(int amountOfItem, Item* item, int itemsLength, char* title);
      void getName(char* out);
      bool canDrop();
      void dropItem(Item item);
      Item pickupItem(int i);
      void printItems();
      void addAdjacentRoom(Direction direction, Room room);
      void printAdjacentRooms();
      Room getAdjacentRoom(Direction direction);
  };
}

