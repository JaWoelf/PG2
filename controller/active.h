#ifndef ACTIVE_H
#define ACTIVE_H

#pragma once
#include <vector>
#include "controller/passive.h"

using std::vector;

#include <string>
#include <iostream>
using std::cout, std::endl;

class Passive;

class Active
{
protected:
  vector<Passive*> passives;
  bool isPassiveAttached(Passive* passive);

public:
 /* Active();
  ~Active();
  Active(Active& a);
*/
  void attach(Passive* passive);
  void detach(Passive* passive);
  void activate();
  //virtual void notify() = 0;
};

#endif // ACTIVE_H
