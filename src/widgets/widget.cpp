#include "widgets/widget.h"
#include "window/window.h"

namespace ppc {

WINDOW* Widget::RawPtr(Window& win) { return win.RawPtr(); }

}  // namespace ppc