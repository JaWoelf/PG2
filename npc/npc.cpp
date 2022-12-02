#include "npc.h"

Npc::Npc(AbstractController *ctrl) : Character("W"), controller(ctrl)
{

}

AbstractController* Npc::getController() const{
  return controller;
}
