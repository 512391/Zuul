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
  Item item = Player::currentRoom->pickupItem(i);

  Player::inventory->items.push_back(item);
}

void Player::move(Direction direction)
{
  Player::currentRoom = Player::currentRoom->getAdjacentRoom(direction);
  Player::currentRoom->printAdjacentRooms();
  Player::currentRoom->printItems();
}
