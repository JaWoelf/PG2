#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#pragma once
#include "ui/abstractui.h"
#include "ui/tui/terminalui.h"
#include "level/level.h"

// nötig?
#include <vector>
#include "character.h"
#include "npc/npc.h"

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
