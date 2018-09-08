#ifndef PPCURSES_WINDOW_WINDOW_H_
#define PPCURSES_WINDOW_WINDOW_H_
#include <memory>
#include <string>
#include <vector>
#include "ncurses_forward_decl.h"
#include "util/point.h"
#include "widgets/widget.h"

namespace ppc {
// FIXME: hide this deleter from public API
void RawWindowDeleter(WINDOW *win);

class Window {
  friend class Application;

 public:
  Window(Point pos, Point size);

  template <class T, class... Args>
  void AddWidget(Args... args);

  void SetPosition(Point t_position);
  inline Point Position() { return position_; }

  void SetSize(Point t_size);
  inline Point Size() { return size_; }

 private:
  Point position_;
  Point size_;

  std::unique_ptr<WINDOW, decltype(&RawWindowDeleter)> curses_window_;
  std::vector<Widget> widgets_;
  inline WINDOW *RawPtr() { return curses_window_.get(); }
  void Draw();
  char GetKeyEvents();
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_H_
