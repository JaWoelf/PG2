#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QPixmap>
#include <vector>
#include "abstractui.h"

using std::vector;
class MainWindow;

class GraphicalUI : public AbstractUI
{
    MainWindow* window;
    vector<QPixmap> pixmaps;
public:
  GraphicalUI();

};

#endif // GRAPHICALUI_H
