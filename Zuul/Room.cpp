#include<iostream>
#include <cstring>
#include "./Room.h"
#include <vector>


using namespace std;
using namespace Zuul;


Room::Room()
{
  cout << "made a room";
}
Room::Room(int amountOfItem, Item* item, int itemsLength, char* title)
{
  Room::amountOfItems = amountOfItem;
  strcpy(Room::name, title);

  Room::amountOfItems = itemsLength;
  
  for(int i = 0; i < itemsLength; i++)
    {
      Room::items.push_back(item[i]);
    }
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

void Room::dropItem(Item item)
{
  Room::items.push_back(item);
  Room::amountOfItems++;
}

Item Room::pickupItem(int i)
{
  Item itemToReturn = Room::items.at(i);

  Room::items.erase(itemToReturn);
  
  return itemToReturn;
}
