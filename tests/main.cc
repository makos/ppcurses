// #define CATCH_CONFIG_MAIN
// #include "catch.h"
#include <iostream>
#include "application.h"
// #include "window/window.h"

using namespace ppc;

int main() {
  Application app;
  auto mywin = app.NewWindow(Point(1, 1), Point(5, 3));
  app.Draw();
  char ch;
  while ((ch = app.GetKeyEvents()) != 'q') {
    app.Draw();
    switch (ch) {
      case 'h':
        mywin->SetPosition(mywin->Position() + Point(-1, 0));
        break;
      case 'j':
        mywin->SetPosition(mywin->Position() + Point(0, 1));
        break;
      case 'l':
        mywin->SetPosition(mywin->Position() + Point(1, 0));
        break;
      case 'k':
        mywin->SetPosition(mywin->Position() + Point(0, -1));
        break;
    }
  }
}
