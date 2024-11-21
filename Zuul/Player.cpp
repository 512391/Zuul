#include<vector>
#include<iostream>
#include "./Player.h"

using namespace Zuul;
using namespace std;

/*
  Author: jay williamson
  Date: 11/21/2024
  this class controls the logic of the player
 */

//constructor
Player::Player(Room* room)
{
  //makes inventory
  Player::inventory = new Inventory();
  //assigns room
  Player::currentRoom = room;

  //prints initial stuff
  Player::currentRoom->printAdjacentRooms();
  Player::currentRoom->printItems();
}

//checks if there is inventory space to pick something up
bool Player::canPickup()
{
  //checks if the amount of items is too much
  if(Player::inventory->amountOfItems >= Player::inventory->MAX_INVENTORY_ITEMS)
    {
      return false;
    }
  return true;
}

//pickups up an item with an index
void Player::pickup(int i)
{
  //gets the item
  Item* item = Player::currentRoom->pickupItem(i);

  //puts it in inventory
  Player::inventory->items.push_back(item);
  Player::inventory->amountOfItems++;
}

//drops an item out of the inventory
void Player::drop(int i)
{
  //checks if you can drop something
  if(Player::currentRoom->canDrop() && i < Player::inventory->amountOfItems)
    {
      //gets the item and its position
      auto pos = Player::inventory->items.begin() + i;
      Item* item = Player::inventory->items.at(i);

      //gets rid of the item
      Player::inventory->items.erase(pos);
      Player::currentRoom->dropItem(item);
      Player::inventory->amountOfItems--;
    }
  else
    {
      cout << "cant drop";
    }
}

//checks if the player has the key
bool Player::hasKey()
{
  //goes through the inventory
  for(auto& item : Player::inventory->items)
    {
      //checks if any of thema are the key
      if(item->winner)
	{
	  return true;
	}
    }
  return false;
}

///moves the player to anotgher room
void Player::move(Direction direction)
{
  //checks if you are entering the after party to win
  if(Player::currentRoom->getAdjacentRoom(direction)->needKey && hasKey())
    {
      cout << "You won congrats on making it to the after part" << endl;
      cout << "type quit to exit" << endl;
    }//tells you u cant enter if u dont have a key
  else if(Player::currentRoom->getAdjacentRoom(direction)->needKey)
    {
      cout << "ya need a key" << endl;
    }
  else
    {
      //just moves the player into the room instructed
      Player::currentRoom = Player::currentRoom->getAdjacentRoom(direction);

      cout << "you are now in the " << Player::currentRoom->name << endl;
      
      Player::currentRoom->printAdjacentRooms();
      Player::currentRoom->printItems();
    }
}

//prints out the inventory
void Player::printInventory()
{
  int i = 0;
  //iterates through the items
  for(auto& item : Player::inventory->items)
    {
      //prints the items
      cout << i << ": " << item->name << "\n";
        i++;
    }

}
