#include<vector>
#include<iostream>

namespace Zuul
{
  const int MAX_ITEMS = 5;

  struct Item
  {
     char name[10];
     bool winner;
  };

  class Room
  {
    protected:
      char name[20];
      vector<Item> items;
      int amountOfItems;
      
    public:
    //this constructor is just to make an instance and test
    Room();
      Room(int amountOfItem, Item* item, int itemsLength, char* title);
      void getName(char* out);
      bool canDrop();
      void dropItem(Item item);
      Item pickupItem(int i);
      void printItems();
  };
}

