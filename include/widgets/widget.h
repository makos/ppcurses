#ifndef PPCURSES_WIDGET_WIDGET_H_
#define PPCURSES_WIDGET_WIDGET_H_
#include "ncurses_forward_decl.h"

namespace ppc {
class Window;

class Widget {
  friend class Window;

 public:
  virtual ~Widget() = default;

 protected:
  WINDOW *RawPtr(Window &win);
  virtual void Draw(Window &win) = 0;
};

}  // namespace ppc

#endif  // PPCURSES_WIDGET_WIDGET_H_