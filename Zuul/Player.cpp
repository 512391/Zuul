#include<vector>
#include<iostream>
#include "./Player.h"

using namespace Zuul;
using namespace std;

Player::Player(Room* room)
{
  Player::inventory = new Inventory();
  Player::currentRoom = room;

  Player::currentRoom->printAdjacentRooms();
  Player::currentRoom->printItems();
}

bool Player::canPickup()
{
  if(Player::inventory->amountOfItems >= Player::inventory->MAX_INVENTORY_ITEMS)
    {
      return false;
    }
  return true;
}
void Player::pickup(int i)
{
  Item* item = Player::currentRoom->pickupItem(i);

  Player::inventory->items.push_back(item);

  Player::inventory->amountOfItems++;
}

void Player::drop(int i)
{
  if(Player::currentRoom->canDrop() && i < Player::inventory->amountOfItems)
    {
      auto pos = Player::inventory->items.begin() + i;
      Item* item = Player::inventory->items.at(i);
      
      Player::inventory->items.erase(pos);

      Player::currentRoom->dropItem(item);

      Player::inventory->amountOfItems--;
    }
  else
    {
      cout << "cant drop";
    }
}

bool Player::hasKey()
{
  for(auto& item : Player::inventory->items)
    {
      if(item->winner)
	{
	  return true;
	}
    }
  return false;
}

void Player::move(Direction direction)
{
  if(Player::currentRoom->getAdjacentRoom(direction)->needKey && hasKey())
    {
      cout << "You won congrats on making it to the after part";
    }
  else if(Player::currentRoom->getAdjacentRoom(direction)->needKey)
    {
      cout << "ya need a key";
    }
  else
    {
      Player::currentRoom = Player::currentRoom->getAdjacentRoom(direction);
      Player::currentRoom->printAdjacentRooms();
      Player::currentRoom->printItems();
    }
}

void Player::printInventory()
{
  int i = 0;
  for(auto& item : Player::inventory->items)
    {
      cout << i << ": " << item->name << "\n";
        i++;
    }

}
