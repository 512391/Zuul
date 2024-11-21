#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include<iostream>
#include <cstring>
#include <map>

/*
  Author: jay williamson
  Date: 11/21/2024
  this header defines the functions and variables of the room
 */



namespace Zuul
{
  const int MAX_ITEMS = 5;

  //item struct
  struct Item
  {
     char name[10];
    //whether it is the key or not
     bool winner;

    //constructor
    Item(char* title, bool win);
  };

  //enum for the direction of a room
  enum Direction
    {
      North,
      South,
      East,
      West
    };

  //the room class
  class Room
  {
    protected:
      std::vector<Item*> items;
      int amountOfItems;
      std::map<Direction, Room*> adjacentRooms;
    //input a direction and get out the english
    std::map<Direction, const char*> directionToWord;
    //words for the directions
    const char east[6] = "East";
    const char west[6] = "West";
    const char south[6] = "South";
    const char north[6] = "North";
    
    public:
    //name of the room
    char name[25];
    //checks if you need a key to get in
    bool needKey = false;
    //constructor
    Room(char* title);
    //gives name
      void getName(char* out);
    //checks if you can drop something in the room
      bool canDrop();
    //drops an item into the room
      void dropItem(Item* item);
    //picks an item up from the room
      Item* pickupItem(int i);
    //prints items in the room
      void printItems();
    //adds a room in a specified direction
      void addAdjacentRoom(Direction direction, Room* room);
    //prints to rooms next to the current room and their directions
      void printAdjacentRooms();
    //gets a specific adjacent room based on the direction
      Room* getAdjacentRoom(Direction direction);
  };
}

#endif
