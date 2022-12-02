#include <iostream>

#include "dungeoncrawler.h"
#include "MapPack1.h"

using namespace std;

int main()
{
//  DungeonCrawler* dc = new DungeonCrawler();
  DungeonCrawler* dc = new DungeonCrawler(level_map_1);

  static int ctr = 0;
  while(true){
      cout << "Run: " << ++ctr << endl;
      dc->turn();
  }

  cout << "lol";
}
