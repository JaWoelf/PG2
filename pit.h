#ifndef PIT_H
#define PIT_H

#include "tile.h"
#include "ramp.h"

class Pit : public Tile
{
public:
  Pit(int row, int col);
  ~Pit();
  Pit(Pit& p);
  Tile* onEnter(Tile *src, Character *who) override;
  Tile* onLeave(Tile *dst, Character *who) override;

};

#endif // PIT_H
