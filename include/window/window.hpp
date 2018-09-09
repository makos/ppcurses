#ifndef PPCURSES_WINDOW_WINDOW_H_
#define PPCURSES_WINDOW_WINDOW_H_
#include <memory>
#include <string>
#include <vector>
#include "ncurses_forward_decl.hpp"
#include "util/point.hpp"
#include "widgets/widget.hpp"

namespace ppc {
// FIXME: hide this deleter from public API
void RawWindowDeleter(WINDOW *win);

using WidgetPtr = std::shared_ptr<Widget>;

class Window {
  friend class Application;
  friend class Widget;

 public:
  Window(Point pos, Point size);

  template <class T, class... Args>
  void AddWidget(Args... args) {
    auto widget = std::make_shared<T>(args...);
    widgets_.push_back(widget);
  }

  void SetPosition(Point t_position);
  inline Point Position() { return position_; }

  void SetSize(Point t_size);
  inline Point Size() { return size_; }

 private:
  Point position_;
  Point size_;

  std::shared_ptr<WINDOW> curses_window_;
  std::vector<WidgetPtr> widgets_;
  inline WINDOW *RawPtr() { return curses_window_.get(); }
  void Draw();
  char GetKeyEvents();
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_H_
