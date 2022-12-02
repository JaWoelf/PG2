#ifndef PASSIVE_H
#define PASSIVE_H

#pragma once
#include "active.h"

#include <string>
#include <iostream>
using std::cout, std::endl;

class Active;

class Passive
{
public:
  Passive();
  ~Passive();
  Passive(Passive& a);

  virtual void notify(Active* source) = 0;
};

#endif // PASSIVE_H
