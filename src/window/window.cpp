#include "window/window.hpp"

namespace ppc {

window::window() : position(point()), m_controls() {}

void window::add_control(std::string control) { m_controls.push_back(control); }

} // namespace ppc