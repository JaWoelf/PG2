#ifndef NPC_H
#define NPC_H

#include "character.h"
#include "abstractcontroller.h"

class Npc : public Character
{
  AbstractController* controller;
public:
  Npc(AbstractController *ctrl);
  AbstractController* getController() const;

};

#endif // NPC_H
