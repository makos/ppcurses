#include "window/window.h"
#include <curses.h>
#include <iostream>

namespace ppc {

// Public methods ------------------------------------------------------------
Window::Window(Point pos, Point size)
    : position(pos),
      size(size),
      curses_window_(newwin(size.y, size.x, pos.y, pos.x), &DeleteRawWindow),
      widgets_() {}

template <class T>
void Window::AddWidget(T widget) {
  widgets_.push_back(widget);
}

// New window needs to be created if we want to move or resize it.
void Window::SetPosition(Point t_position) {
  if (t_position.x < 0 || t_position.x + size.x > COLS || t_position.y < 0 ||
      t_position.y + size.y > LINES) {
    return;
  }

  wclear(RawPtr());
  position = t_position;
  curses_window_ = std::unique_ptr<WINDOW, decltype(&DeleteRawWindow)>(
      newwin(size.y, size.x, t_position.y, t_position.x), &DeleteRawWindow);
  box(RawPtr(), 0, 0);
  wrefresh(RawPtr());
}

void Window::SetSize(Point t_size) {
  wclear(RawPtr());
  curses_window_ = std::unique_ptr<WINDOW, decltype(&DeleteRawWindow)>(
      newwin(t_size.y, t_size.x, position.y, position.x), &DeleteRawWindow);
}

// Protected methods ---------------------------------------------------------
void Window::Draw() {
  werase(RawPtr());
  box(RawPtr(), 0, 0);
  wrefresh(RawPtr());
}

char Window::GetKeyEvents() { return static_cast<char>(wgetch(RawPtr())); }

// Custom deleter
void DeleteRawWindow(WINDOW *win) {
  wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(win);
  delwin(win);
}

}  // namespace ppc
