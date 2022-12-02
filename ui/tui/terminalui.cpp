#include "terminalui.h"

TerminalUI::TerminalUI()
{

};

int TerminalUI::move(){
  // EINGABE (cout inputrequest)(cin input)(validate input)
  int dir = 0;
  char ch;
  cout << "\n Move Character" << endl
       << endl << "q - top left " <<
          endl << "w - top " <<
          endl << "e - top right " <<
          endl << "a - left " <<
          endl << "d - right " <<
          endl << "y - down left " <<
          endl << "x - down " <<
          endl << "c - down right " <<
          endl << "0 - Exit " << endl << endl;

  cin >> ch;
  dir = normalizeInput(ch);
  return dir;
}

void TerminalUI::draw(Level* l)
{
  // AUSGABE (cout level)
  int height = l->getHeight();
  int width = l->getWidth();
  for( int h = 0; h < height; h++){
      for (int w = 0; w < width; w++){
          cout << l->getTile(h,w)->getTexture();
      }
      cout << endl;
  }
}

int TerminalUI::normalizeInput(char ch)
{
  switch(ch){
    case('0'):
      _Exit(EXIT_SUCCESS);
    case('1'):
      return 1;
    case('2'):
      return 2;
    case('3'):
      return 3;
    case('4'):
      return 4;
    case('6'):
      return 6;
    case('7'):
      return 7;
    case('8'):
      return 8;
    case('9'):
      return 9;

    case('y'):
      return 1;
    case('x'):
      return 2;
    case('c'):
      return 3;
    case('a'):
      return 4;
    case('d'):
      return 6;
    case('q'):
      return 7;
    case('w'):
      return 8;
    case('e'):
      return 9;

    default:    // SOMETHING WHENT WRONG
      cout << "ERROR - Faulty Input: " << ch << endl << endl;
    return 0;
  }
}

