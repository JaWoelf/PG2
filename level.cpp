#include "level.h"


//
// DBG
#include "iostream"
using std::cout;
using std::endl;
//
//


Level::Level() : height(4), width(4)
{
  // Build Grid
  grid.resize(width);
  for ( int w = 0; w < width; w++){
      grid.at(w).resize(height);
  }

  // Fill Grid
  for (int w = 0; w < width; w++){
      for (int h = 0; h < height; h++){
          grid[w][h] = new Floor(w,h);
      }
  }

  // Place Portals
  Portal* p0 = new Portal(0,0);
  delete grid.at(0).at(0);
  grid[0][0] = p0;

  Portal* p1 = new Portal(width-1,height-1);
  delete grid.at(width-1).at(height-1);
  grid[width-1][height-1] = p1;

  p0->setLink(p1);
  p1->setLink(p0);

  // Place 1 Door & 1 Switch
  Door* d0 = new Door(1,1);
  delete grid.at(1).at(1);
  grid[1][1] = d0;

  Switch* s0 = new Switch(1,2);
  s0->attach(d0);
  delete grid.at(1).at(2);
  grid[1][2] = s0;


  // Place 2 pits & 1 ramp
  Pit* pt0 = new Pit(1,0);
  delete grid.at(1).at(0);
  grid[1][0] = pt0;

  Pit* pt1 = new Pit(2,0);
  delete grid.at(2).at(0);
  grid[2][0] = pt1;

  Ramp* r0 = new Ramp(2,1);
  delete grid.at(2).at(1);
  grid[2][1] = r0;


  // Place Character
  Character *c = new Character();
  c->setTile(grid[0][0]);
  grid[0][0]->setCharacter(c);
  character = c;

  // Place NPCs
  GuardController* gc = new GuardController();
  Npc* npc0 = new Npc(gc);
  npcs.push_back(npc0);
  npc0->setTile(grid[0][3]);
  grid[0][3]->setCharacter(npc0);

  Npc* npc1 = new Npc(gc);
  npcs.push_back(npc1);
  npc1->setTile(grid[3][2]);
  grid[3][2]->setCharacter(npc1);

  cout << "set wall" << endl;
  // Set a single Wall
  delete grid.at(3).at(1);
  Wall* w = new Wall(3,1);
  grid[3][1] = w;
}

/*
Level::Level(string map) : height(pow(map.length(),0.5)), width(pow(map.length(),0.5))
{
  cout << "build grid" << endl;
  // Build Grid
  grid.resize(width);
  for ( int w = 0; w < width; w++){
      grid.at(w).resize(height);
  }
  cout << "fill grid" << endl;
  // Fill Tiles
  int row = 0, col = 0;
  Portal* p0 = nullptr;
  Portal* p1;
  for (char a :map){
      cout << "   next char" << endl;
      // next line
      if (a == '\n'){
          row++;
          col = 0;
          continue;
      }

      grid[row][col] = buildTileFromChar(a, row, col);

      switch(a){
        // Handle Portal
        case('O'):
          cout << "     portal" << endl;
          {
            if(!p0)
                p0 = dynamic_cast<Portal*>(grid[row][col]);
            else{
                p1 = dynamic_cast<Portal*>(grid[row][col]);
                p0->setLink(p1);
                p1->setLink(p0);
              }
            continue;
          }
        // Handle Player
        case('C'):
          {
            cout << "     player" << endl;
            Character* c = new Character();
            c->setTile(grid[row][col]);
            grid[row][col]->setCharacter(c);
            character = c;
            continue;
          }
        // Handle NPC - Guardian
        case('W'):{
            cout << "     npc guardian" << endl;
            GuardController* gc = new GuardController();
            Npc* npc = new Npc(gc);
            npc->setTile(grid[row][col]);
            grid[0][3]->setCharacter(npc);
            npcs.push_back(npc);
            continue;
          }
        }
  }

}

*/

Level::Level(string map) : height(pow(map.length(),0.5)), width(pow(map.length(),0.5))
{
  cout << "size grid" << height << "-" << width << endl;
  grid.resize(width);
  for (int w = 0; w < width; w++)
    grid.at(w).resize(height);
  cout << "size grid" << grid.size() << "-" << grid.at(0).size() << endl;


  cout << "fill grid" << endl;
  Portal* p0 = nullptr;
  Portal* p1;
  vector<Switch*> switches;
  vector<Door*> doors;
  Tile* current;
  int charIdx = 0; // sequential string reading index
  char tileChar;


  for (int r = 0; r < height; r++)
    {
    for(int c = 0; c < width; c++)
    {
//        cout << "Progress: " << "[" << r << "][" << c << "] - " << charIdx << "/" << map.length() << "-" << height*width << endl;
//        cout << map << endl;
//        cout << map.at(charIdx) << endl;
        tileChar = map.at(charIdx);
//        cout << tileChar << endl;

         current = buildTileFromChar(tileChar, r, c);

         grid.at(r).at(c) = current;
         //grid[r][c] = current;
//        cout << current->getTexture() << "  <<-- current->getTexture()" << endl;
//         cout << "   handle specials" << endl;
         switch(tileChar)
         {
           case('O'):
             {
//               cout << "   Portal" << endl;
               if(!p0)
                 p0 = dynamic_cast<Portal*>(current);
               else
                 {
                   p1 = dynamic_cast<Portal*>(current);
                   p0->setLink(p1);;
                   p1->setLink(p0);
                   p0 = nullptr; // usefull if more than 1 pair
                 }
               break;
             }
           case('C'):
             {
//               cout << "   Character" << endl;
               character = new Character();
               character->setTile(current);
               current->setCharacter(character);
               break;
             }
           case('W'):
             {
//               cout << "   Npc guardian" << endl;
               GuardController* gc = new GuardController();
               npcs.push_back(new Npc(gc));
               npcs.back()->setTile(current);
               current->setCharacter(npcs.back());
               break;
             }
           case('X'):
             {
               cout << "   Door" << endl;
               doors.push_back(dynamic_cast<Door*>(current));
               break;
             }
           case('?'):
             {
               cout << "  Switch" << endl;
               switches.push_back(dynamic_cast<Switch*>(current));
               break;
             }
         }//switch

         charIdx++;
    }
  }

  if (switches.size() != doors.size())
    {
      cout << "ERROR - Initialization Error" << endl
           << " Number of Switches and Number of Doors mismatch." << endl;
      _Exit(EXIT_FAILURE);
    }
  else
      for (int i = 0; i < switches.size(); i++)
          switches.at(i)->attach(doors.at(i));
}

Tile* Level::buildTileFromChar(char t, int trow, int tcol){
  cout << "buildTileFromChar " << t << "[" << trow << "][" << tcol << "]" << endl;
  switch(t){
      case('.'):{  // Floor
        Floor* f = new Floor(trow, tcol);
        return f;
      }case('#'):{  // Wall
        Wall* w = new Wall(trow, tcol);
        return w;
      }case('O'):{  // Portal
        Portal* p = new Portal(trow, tcol);
        return p;
      }case('X'):{  // Door
        Door* d = new Door(trow, tcol);
        return d;
      }case('_'):{  // Pit
        Pit* p = new Pit(trow, tcol);
        return p;
      }case('<'):{  // Ramp
        Ramp* r = new Ramp(trow, tcol);
        return r;
      }case('?'):{  // Switch
        Switch* s = new Switch(trow, tcol);
        return s;
      }case('W'):{  // NPC - guardian
        Floor* w = new Floor(trow, tcol);
        return w;
      }case('C'):{  // Player
        Floor* w = new Floor(trow, tcol);
        return w;
      }
  }
}

Level::~Level(){
  for (int w = 0; w < width; w++){
      for (int h = 0; h < height; h++){
          delete grid[w][h];
          grid[w][h] = nullptr;
      }
  }

  delete character;
  for (auto n : npcs){
      if (n->getController())
        delete n->getController();
      delete n;
    }
}

/*
Level::Level(Level& l) : height{ l.height }, width{ l.width }
{
  // Match grid sizes
  grid.resize(l.grid.size());
  for (int h = 0; h < height; h++){
      grid[h].resize(l.grid.size());
  }

  // Copy grid tiles
  static Floor* nf;
  static Wall* nw;
  static Portal* np;
  for (int h = 0; h < height; h++){
      for (int w = 0; w < width; w++){
          if (typeid(l.grid[h][w]) == typeid(Floor)){
              nf = dynamic_cast<Floor*>(l.grid[w][h]);
              grid[w][h] = new Floor(*nf);
          }
          else if (typeid(l.grid[h][w]) == typeid(Wall)){
              nw = dynamic_cast<Wall*>(l.grid[w][h]);
              grid[w][h] = new Wall(*nw);
          }
          else if (typeid(l.grid[h][w]) == typeid(Portal)){
              np = dynamic_cast<Portal*>(l.grid[w][h]);
              grid[w][h] = new Portal(*np);
          }
      }
  }

  // copy characters
  for (auto lc : l.characters){
      if (typeid(*lc) == typeid(Character)){
          auto c = dynamic_cast<Character*>(lc);
          characters.push_back(new Character(*c));
        }
    }

}
*/

Tile *Level::getTile(int row, int col){
  return grid[row][col];
}

const Tile *Level::getTile( int row, int col) const {
  return grid[row][col];
}

void Level::setCharacter(Character *c, int row, int col){
  grid[row][col]->setCharacter(c);
}

int Level::getHeight()
{
  return height;
}

int Level::getWidth()
{
  return width;
}

Character* Level::getCharacter()
{
  return character;
}

vector<Npc*> Level::getNpcs()
{
  return npcs;
}
