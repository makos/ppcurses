#ifndef PPCURSES_WIDGETS_LABEL_H_
#define PPCURSES_WIDGETS_LABEL_H_
#include <string>
#include "util/point.h"
#include "widget.h"

namespace ppc {

class Label : public Widget {
  friend class Window;

 public:
  Label(Point pos, const char *text);

  Point position;
  std::string text;

 protected:
  void Draw(Window &win) override;
};

}  // namespace ppc

#endif  // PPCURSES_WIDGETS_LABEL_H