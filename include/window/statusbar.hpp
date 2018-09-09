#ifndef PPCURSES_WINDOW_STATUSBAR_H_
#define PPCURSES_WINDOW_STATUSBAR_H_
#include "label.hpp"

namespace ppc {

enum class BarPosition { Top, Bottom };

class Statusbar {
 public:
  Statusbar();
  Statusbar(BarPosition pos);

  template <Args... args>
  void AddLabel(Args... args) {}

 private:
  std::vector<Label> widgets_;
};

}  // namespace ppc

#endif  // PPCURSES_WINDOW_STATUSBAR_H