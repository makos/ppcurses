#include "window/window.hpp"

namespace ppc {

Window::Window() : position(ppc::Point()), controls_() {}

void Window::AddControl(std::string control) { controls_.push_back(control); }

}  // namespace ppc