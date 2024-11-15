#include<vector>
#include<iostream>
#include"./Room.h"
namespace Zuul
{ 
  struct Inventory
  {
    const int MAX_INVENTORY_ITEMS = 5;

    std::vector<Item> items;
    int amountOfItems;
  };

  class Player
  {
    protected:
      Inventory* inventory;
      Room currentRoom;

    public:
      Player(Room room);
      bool canPickup();
      void pickup(int i);
      void move(Direction direction);
  };
}
