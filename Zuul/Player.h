#include<vector>
#include<iostream>
#include"./Room.h"
/*
  Author: jay williamson
  Date: 11/21/2024
  this header defines the functions and variables of the player
 */


namespace Zuul
{
  //struct of the inventory
  struct Inventory
  {
    const int MAX_INVENTORY_ITEMS = 5;

    std::vector<Item*> items;
    int amountOfItems;
  };

  //class for the player
  class Player
  {
    protected:
    //an inventory pointer for the instance of the inventory
      Inventory* inventory;

    public:
    //room pointer for the room the player is in
    Room* currentRoom;
    //constructor
      Player(Room* room);
    //checks if the player has the key
    bool hasKey();
    //checks if the player has room to pick something up
      bool canPickup();
    //picks something up from a room
      void pickup(int i);
    //drops something into the current room
    void drop(int i);
    //moves the player into a new room
      void move(Direction direction);
    //prints the inventory
    void printInventory();
  };
}
