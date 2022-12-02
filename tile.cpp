#include "tile.h"

Tile::Tile(string texture, int row, int col) : texture(texture), row(row), col(col)
{

};

Tile::~Tile() {};

string Tile::getTexture()
{
  if (hasCharacter())
    return character->getTexture();
  else
    return texture;
}

bool Tile::hasCharacter()
{
  return (character != nullptr);
};

bool Tile::moveTo(Tile* dst, Character* who){
//  cout << "MoveTo: " << dst->getRow() << "/" << dst->getCol() << " FROM: " << who->getTile()->getRow() << "/" << who->getTile()->getCol() << endl;

  if(!this->onLeave(dst, who))
    return false;

  dst = dst->onEnter(this, who); // get real destination (portal and stuff)
  if(!dst)
    return false;


  this->setCharacter(nullptr);
  dst->setCharacter(who);
  who->setTile(dst);

  return true;
};

// virtual Tile* onEnter(Tile* src, Character* who) = 0;

Tile* Tile::onLeave(Tile *dst, Character *who)
{
  return this;
};

void Tile::setCharacter(Character *c){
  character = c;
}

int Tile::getRow() { return row; };
int Tile::getCol() { return col; };
