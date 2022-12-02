#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(){
  level = new Level();
  ui = new TerminalUI();
}

DungeonCrawler::DungeonCrawler(string map){
  level = new Level(map);
  ui = new TerminalUI();
}

/*
void DungeonCrawler::turn()
{
  // kick off next turn
  ui->draw(level);
  int input = ui->move();

  Character* c = level->getCharacter();

  Tile* src = c->getTile();
  int srcRow = src->getRow();
  int srcCol = src->getCol();
  int dstRow, dstCol;


  switch(input){
    case(1):  // DOWN LEFT
      {
        dstRow = srcRow+1;
        dstCol = srcCol-1;
        break;
      }
    case(2):  // DOWN
      {
        dstRow = srcRow+1;
        dstCol = srcCol;
        break;
      }
    case(3):  // BOTTOM RIGHT
      {
        dstRow = srcRow+1;
        dstCol = srcCol+1;
        break;
      }
    case(4):  // LEFT
      {
        dstRow = srcRow;
        dstCol = srcCol-1;
        break;
      }
    case(6):  // RIGHT
      {
        dstRow = srcRow;
        dstCol = srcCol+1;
        break;
      }
    case(7):  // TOP LEFT
      {
        dstRow = srcRow-1;
        dstCol = srcCol-1;
        break;
      }
    case(8):  // TOP
      {
        dstRow = srcRow-1;
        dstCol = srcCol;
        break;
      }
    case(9):  // TOP RIGHT
      {
        dstRow = srcRow-1;
        dstCol = srcCol+1;
        break;
      }
    default:
      return;
  }

  if ( (dstRow < 0) || (dstCol < 0) || (dstRow >= level->getWidth()) || (dstCol >= level->getHeight()))
    {
      cout << "CANNOT MOVE OUT OF LEVEL" << endl;
      return;
    }

  // Execute Move
  src->moveTo(level->getTile(dstRow,dstCol),c);

}
*/

void DungeonCrawler::turn()
{
  // Draw
  ui->draw(level);

  // player movement
  if (!turnPlayer())
    return;
  // npc movement
  else{
      for (Npc* npc : level->getNpcs()){
          turnNpc(npc);
      }
  }
}

bool DungeonCrawler::turnPlayer()
{
//  cout << "turnPlayer()" << endl;
  int input = ui->move();
  Character* c = level->getCharacter();
  Tile* src = c->getTile();
  Tile* dst = findTurnTarget(input, src);

  if (!dst)
    return false;

  src->moveTo(dst,c);
  return true;
}

bool DungeonCrawler::turnNpc(Npc* npc)
{
//  cout << "turnNPCs()" << endl;
  //iterate NPCs
  // per npc: get src; get direction; get target;
  Tile* src;
  Tile* dst;
  int input;
  src = npc->getTile();
  input = npc->getController()->move();
  dst = findTurnTarget(input, src);

  if(!dst)
      return false;
  src->moveTo(dst, npc);
  return true;
}

Tile* DungeonCrawler::findTurnTarget(int input, Tile* src){

//  cout << "findTurnTarget()" << endl;
  int dstRow = src->getRow();
  int dstCol = src->getCol();

  switch(input){
    case(1):  // DOWN LEFT
      {
        dstRow++;
        dstCol--;
        break;
      }
    case(2):  // DOWN
      {
        dstRow++;
        break;
      }
    case(3):  // BOTTOM RIGHT
      {
        dstRow++;
        dstCol++;
        break;
      }
    case(4):  // LEFT
      {
        dstCol--;
        break;
      }
    case(6):  // RIGHT
      {
        dstCol++;
        break;
      }
    case(7):  // TOP LEFT
      {
        dstRow--;
        dstCol--;
        break;
      }
    case(8):  // TOP
      {
        dstRow--;
        break;
      }
    case(9):  // TOP RIGHT
      {
        dstRow--;
        dstCol++;
        break;
      }
    default:{
      cout << "find turn target - DEFAULT" << endl;
      return nullptr;
    }
  }

  if ( (dstRow < 0) || (dstCol < 0) || (dstRow >= level->getWidth()) || (dstCol >= level->getHeight()))
    {
      cout << "CANNOT MOVE OUT OF LEVEL" << endl;
      return nullptr;
    }
//  cout << "find turn target - return (destRow[" << dstRow << "][" << dstCol << "]" << endl;
  cout << "direction: " << input << " = " << dstRow << "|" << dstCol << endl;
  return level->getTile(dstRow, dstCol);
}


