#include "door.h"

Door::~Door() {};

Door::Door(int row, int col) : Tile("X", row, col)
{

}


Tile* Door::onEnter(Tile *src, Character *who)
{
  if (this->texture == "X")
    return nullptr;
  else
    return this;
}

void Door::notify(Active *source)
{
  cout << "Door[" << row << "]["<< col <<"]::notify()" << endl;
  cout << "Ma texture is: " << texture << endl;
  if (texture == "X")
    texture = "/";
  else
    texture = "X";
  cout << "Ma texture is: " << texture << endl;
  return;
}
