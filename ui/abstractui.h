#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#pragma once
#include "level.h"
//#include "dungeoncrawler.h"

class AbstractUI
{
public:
  AbstractUI();
  virtual ~AbstractUI();
  AbstractUI(AbstractUI& a);

  virtual void draw(Level* l) = 0;
  virtual int move() = 0;
};

#endif // ABSTRACTUI_H
