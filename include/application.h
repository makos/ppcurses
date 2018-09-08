#ifndef PPCURSES_APPLICATION_H_
#define PPCURSES_APPLICATION_H_
#include <memory>
#include <vector>
#include "ncurses_forward_decl.h"
#include "window/window.h"

#define PPCURSES_VERSION_MAJOR 0
#define PPCURSES_VERSION_MINOR 2
#define PPCURSES_VERSION_PATCH 0

namespace ppc {

enum Focus { Canvas = -1 };

using WindowPtr = std::shared_ptr<Window>;

class Application {
 public:
  Application();
  ~Application();

  WindowPtr NewWindow(Point pos, Point size);

  // Event GetWindowEvents();
  char GetKeyEvents();
  void Draw();

 private:
  int focus_id_;
  std::unique_ptr<WINDOW> canvas_;
  std::vector<std::shared_ptr<Window>> windows_;
};

}  // namespace ppc

#endif  // PPCURSES_APPLICATION_H_
