#ifndef PPCURSES_WINDOW_WINDOW_H_
#define PPCURSES_WINDOW_WINDOW_H_
#include <memory>
#include <string>
#include <vector>
#include "ncurses_forward_decl.h"
#include "util/point.h"

namespace ppc {

void DeleteRawWindow(WINDOW *win);

class Window {
  friend class Application;

 public:
  Window(Point pos, Point size);

  template <class T>
  void AddWidget(T control);

  void SetPosition(Point t_position);
  Point Position() { return position; }

  void SetSize(Point t_size);
  Point Size() { return size; }

 protected:
  void Draw();
  char GetKeyEvents();

 protected:
  Point position;
  Point size;

 private:
  WINDOW *RawPtr() { return curses_window_.get(); }

 private:
  std::unique_ptr<WINDOW, decltype(&DeleteRawWindow)> curses_window_;
  std::vector<std::string> widgets_;
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_H_
