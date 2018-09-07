#include "application.h"
#include <curses.h>

namespace ppc {

Application::Application()
    : canvas_(std::make_unique<WINDOW>(*stdscr)), windows_() {}

}  // namespace ppc