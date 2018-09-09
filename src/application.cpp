#include "application.hpp"
#include <curses.hpp>
#include <iostream>

namespace ppc {

Application::Application()
    : focus_id_(Focus::Canvas), canvas_(stdscr), windows_() {
  initscr();
}

Application::~Application() { endwin(); }

WindowPtr Application::NewWindow(Point pos, Point size) {
  windows_.push_back(std::make_shared<Window>(pos, size));
  focus_id_ = windows_.size() - 1;
  return windows_[windows_.size() - 1];
}

void Application::Draw() {
  werase(canvas_.get());
  for (auto const &window : windows_) {
    window->Draw();
  }
  wrefresh(canvas_.get());
}

char Application::GetKeyEvents() {
  if (focus_id_ == Focus::Canvas) {
    return static_cast<char>(wgetch(canvas_.get()));
  } else {
    return windows_[focus_id_]->GetKeyEvents();
  }
}
}  // namespace ppc
