#ifndef PPCURSES_APPLICATION_HPP_
#define PPCURSES_APPLICATION_HPP_
#include <memory>
#include <vector>
#include "window/window.h"
// ncurses
typedef struct _win WINDOW;

// class Window;

namespace ppc {

class Application {
 public:
  Application();

 private:
  std::unique_ptr<WINDOW> canvas_;
  std::vector<std::unique_ptr<Window>> windows_;
};

}  // namespace ppc

#endif  // PPCURSES_APPLICATION_HPP_