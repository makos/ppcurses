#ifndef PPCURSES_WINDOW_WINDOW_H_
#define PPCURSES_WINDOW_WINDOW_H_
#include <memory>
#include <string>
#include <vector>
#include "ncurses_forward_decl.h"
#include "util/point.h"

namespace ppc {

class Window {
  friend class Application;

 public:
  Window(Point pos, Point size);

  // void AddControl(Control &control);
  template <class T>
  void AddWidget(T control);

 protected:
  void Draw();
  char GetKeyEvents();

 protected:
  Point position;
  Point size;

 private:
  std::unique_ptr<WINDOW> curses_window_;
  std::vector<std::string> widgets_;
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_H_