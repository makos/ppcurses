#ifndef WINDOW_HEADER
#define WINDOW_HEADER
#include "util/point.hpp"
#include <string>
#include <vector>

namespace ppc {

class window {
  protected:
    window();

    void add_control(std::string control);

  protected:
    point position;

  private:
    std::vector<std::string> m_controls;
};

} // namespace ppc
#endif // WINDOW_HEADER