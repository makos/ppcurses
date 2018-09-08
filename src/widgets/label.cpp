#include "widgets/label.h"
#include <curses.h>

namespace ppc {

Label::Label(Point pos, const char *text) : position(pos), text(text) {}

void Label::Draw(Window &win) {
  mvwprintw(RawPtr(win), position.y, position.x, text.c_str());
  // wrefresh(RawPtr(win));
}

}  // namespace ppc