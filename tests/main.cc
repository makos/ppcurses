#include <curses.h>
#include "application.h"
#include "util/point.h"
#include "window/window.h"

int main() {
  ppc::Application app;
  ppc::Window &my_win = app.NewWindow(ppc::Point(7, 7), ppc::Point(10, 10));
  ppc::Window &my_win2 = app.NewWindow(ppc::Point(11, 10), ppc::Point(3, 3));
  app.Draw();
  char ch;
  while ((ch = app.GetKeyEvents()) != 'q') {
    app.Draw();
  }
  return 0;
}