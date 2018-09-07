#ifndef PPCURSES_WINDOW_WINDOW_H_
#define PPCURSES_WINDOW_WINDOW_H_
#include <memory>
#include <string>
#include <vector>
#include "util/point.h"

typedef struct _win WINDOW;

namespace ppc {

class Window {
  friend class Application;

 public:
  Window(Point pos, Point size);

  // void AddControl(Control &control);
  void AddControl(std::string control);
  void Draw();
  char GetKeyEvents();

 protected:
  Point position;
  Point size;

 private:
  std::unique_ptr<WINDOW> curses_window_;
  std::vector<std::string> controls_;
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_H_