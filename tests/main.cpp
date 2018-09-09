// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"
#include <iostream>
#include "application.hpp"
#include "widgets/label.hpp"
#include "window/window.hpp"
// #include "window/window.hpp"

using namespace ppc;

int main() {
  Application app;
  auto mywin = app.NewWindow(Point(1, 1), Point(7, 3));
  mywin->AddWidget<Label>(Point(1, 1), "Hello");
  app.Draw();
  char ch;
  while ((ch = app.GetKeyEvents()) != 'q') {
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
    app.Draw();
  }
}
