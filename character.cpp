#include "character.h"

Character::Character() : texture("C") {};

Character::Character(string t) : texture(t) {};

Tile* Character::getTile()
{
//  cout << "getTile()" << endl;
  return this->tile;
}

string Character::getTexture()
{
  return texture;
}

bool Character::setTile(Tile* t){
  tile = t;
}
