#ifndef RAMP_H
#define RAMP_H

#include "tile.h"

class Ramp : public Tile
{
public:
  Ramp(int row, int col);
  ~Ramp();
  Ramp(Ramp& r);
  Tile* onEnter(Tile *src, Character *who) override;
};

#endif // RAMP_H
