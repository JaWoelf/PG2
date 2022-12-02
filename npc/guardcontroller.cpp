#include "guardcontroller.h"

GuardController::GuardController()
{

}


int GuardController::move()
{
  cout << "GuardController.move()" << endl;
  cout << pattern.size() << endl;
  char c = pattern.at(patternIndex);
  cout << c << "|" << int(c) - 48 << endl;

  patternIndex++;
  if (patternIndex+1 == pattern.length())
    patternIndex = 0;

  return (int(c) - 48);
}
