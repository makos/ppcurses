#include "widgets/widget.hpp"
#include "window/window.hpp"

namespace ppc {

WINDOW* Widget::RawPtr(Window& win) { return win.RawPtr(); }

}  // namespace ppc