#ifndef TERMINALUI_H
#define TERMINALUI_H

#pragma once
#include <iostream>
#include "abstractui.h"
#include "level.h"

using namespace std;

//class AbstractUI;
//class TerminalUI;

class TerminalUI : public AbstractUI
{
public:
  TerminalUI();
  int normalizeInput(char ch);
  int move() override;
  void draw(Level* l) override;
};
#endif // TERMINALUI_H
