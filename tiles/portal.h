#ifndef PORTAL_H
#define PORTAL_H

#pragma once
#include "tile.h"

class Portal : public Tile
{
  Portal* dst;
public:
  Portal(int row, int col);
  ~Portal();
  Portal(Portal& p);

  Tile* onEnter(Tile* src, Character* who) override;
  //Tile* onLeave(Tile* dst, Character* whi) override;

  void setLink(Portal* p);
};

#endif // PORTAL_H
