#include "window/window.h"
#include <curses.h>
#include <iostream>
#include "application.h"

namespace ppc {

Window::Window(Point pos, Point size)
    : position(pos),
      size(size),
      curses_window_(
          std::unique_ptr<WINDOW>(newwin(size.y, size.x, pos.y, pos.x))),
      controls_() {}

void Window::AddControl(std::string control) { controls_.push_back(control); }

void Window::Draw() {
  werase(curses_window_.get());
  box(curses_window_.get(), 0, 0);
  wrefresh(curses_window_.get());
}

char Window::GetKeyEvents() {
  return static_cast<char>(wgetch(curses_window_.get()));
}

}  // namespace ppc