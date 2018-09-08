#include "window/window.h"
#include <curses.h>
#include <iostream>

namespace ppc {

// Public methods ------------------------------------------------------------
Window::Window(Point pos, Point size)
    : position_(pos),
      size_(size),
      curses_window_(newwin(size.y, size.x, pos.y, pos.x), &RawWindowDeleter),
      widgets_() {}

// New window needs to be created if we want to move or resize it.
void Window::SetPosition(Point t_position) {
  if (t_position.x < 0 || t_position.x + size_.x > COLS || t_position.y < 0 ||
      t_position.y + size_.y > LINES) {
    return;
  }

  position_ = t_position;
  curses_window_ = std::unique_ptr<WINDOW, decltype(&RawWindowDeleter)>(
      newwin(size_.y, size_.x, t_position.y, t_position.x), &RawWindowDeleter);
  box(RawPtr(), 0, 0);
}

// TODO: this method.
void Window::SetSize(Point t_size) {
  wclear(RawPtr());
  curses_window_ = std::unique_ptr<WINDOW, decltype(&RawWindowDeleter)>(
      newwin(t_size.y, t_size.x, position_.y, position_.x), &RawWindowDeleter);
}

// Private methods ---------------------------------------------------------
void Window::Draw() {
  werase(RawPtr());
  for (auto &widget : widgets_) {
    widget->Draw(*this);
  }
  box(RawPtr(), 0, 0);
  wrefresh(RawPtr());
}

char Window::GetKeyEvents() { return static_cast<char>(wgetch(RawPtr())); }

// Custom deleter
void RawWindowDeleter(WINDOW *win) {
  wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(win);
  delwin(win);
}

}  // namespace ppc
