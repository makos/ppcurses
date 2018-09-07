#ifndef WINDOW_HEADER
#define WINDOW_HEADER
#include <string>
#include <vector>
#include "util/point.hpp"

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
#endif  // WINDOW_HEADER