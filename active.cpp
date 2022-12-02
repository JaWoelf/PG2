#include "active.h"
/*
Active::~Active(){};

Active::Active()
{

}
*/
bool Active::isPassiveAttached(Passive *p)
{
  for (auto a : passives){
      if (a == p)
        return true;
  }
  return false;
}

void Active::attach(Passive* p)
{
  if (! this->isPassiveAttached(p))
    passives.push_back(p);
}

void Active::detach(Passive *p)
{
  if (! this->isPassiveAttached(p))
    return;

  int i  = 0;
  for (auto a : passives){
      if (a == p){
        passives.erase(passives.begin() + i);
        return;
      }
   }

}

void Active::activate(){
  for (auto p : passives){
      p->notify(this);
    }
}



