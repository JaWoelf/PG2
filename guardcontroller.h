#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H

#include <string>
#include "abstractcontroller.h"
#include <iostream>
using std::cout, std::endl, std::string;

// PATTERN IN CONSTRUKTOR SETZEN

class GuardController : public AbstractController
{
  unsigned int patternIndex = 0;
  string pattern = "66444466";

public:
  GuardController();
  int move() override;
};

#endif // GUARDCONTROLLER_H
