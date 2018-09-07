#ifndef PPCURSES_APPLICATION_H_
#define PPCURSES_APPLICATION_H_
#include <memory>
#include <vector>
#include "window/window.h"
// ncurses
typedef struct _win WINDOW;

namespace ppc {

enum Focus { Canvas = -1 };

class Application {
 public:
  Application();
  ~Application();

  Window &NewWindow(Point pos, Point size);

  char GetKeyEvents();
  void Draw();

 private:
  int focus_id_;
  std::unique_ptr<WINDOW> canvas_;
  std::vector<std::unique_ptr<Window>> windows_;
};

}  // namespace ppc

#endif  // PPCURSES_APPLICATION_H_