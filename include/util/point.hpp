#ifndef PPCURSES_UTIL_POINT_H_
#define PPCURSES_UTIL_POINT_H_
#include <ostream>

namespace ppc {

class Point {
 public:
  Point() : x(0), y(0) {}
  Point(int t_x, int t_y) : x(t_x), y(t_y) {}

  Point &operator+=(const Point &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }

  Point &operator-=(const Point &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Point &p);

 public:
  int x;
  int y;
};

inline bool operator==(const Point &lhs, const Point &rhs) {
  return (lhs.x == rhs.x && lhs.y == rhs.y);
}

inline bool operator!=(const Point &lhs, const Point &rhs) {
  return (!operator==(lhs, rhs));
}

inline Point operator+(Point lhs, const Point &rhs) {
  lhs += rhs;
  return lhs;
}

inline Point operator-(Point lhs, const Point &rhs) {
  lhs -= rhs;
  return lhs;
}

inline std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
}  // namespace ppc
#endif  // PPCURSES_UTIL_POINT_H_
