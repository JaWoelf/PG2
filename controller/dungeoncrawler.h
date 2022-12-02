#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#pragma once
#include "abstractui.h"
#include "terminalui.h"
#include "level.h"

// nötig?
#include <vector>
#include "character.h"
#include "npc.h"

class AbstractUI;
class TerminalUI;

class DungeonCrawler
{
  Level* level;
  AbstractUI* ui;
  Character* player;

public:
  DungeonCrawler();
  DungeonCrawler(string map);

  void turn();
  bool turnPlayer();
  bool turnNpc(Npc* npc);
  Tile* newPos(Tile* dst);
  Tile* findTurnTarget(int input, Tile* src);


};

#endif // DUNGEONCRAWLER_H
