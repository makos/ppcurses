#ifndef PPCURSES_WINDOW_WINDOW_HPP_
#define PPCURSES_WINDOW_WINDOW_HPP_
#include <string>
#include <vector>
#include "util/point.h"

namespace ppc {

class Window {
 protected:
  Window();

  void AddControl(std::string control);

 protected:
  Point position;

 private:
  std::vector<std::string> controls_;
};

}  // namespace ppc
#endif  // PPCURSES_WINDOW_WINDOW_HPP_