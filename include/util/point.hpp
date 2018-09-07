#ifndef POINT_HEADER
#define POINT_HEADER
#include <ostream>

namespace ppc {

class point {
  public:
    point() : x(0), y(0) {}
    point(int t_x, int t_y) : x(t_x), y(t_y) {}

    point &operator+=(const point &rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    point &operator-=(const point &rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const point &p);

  public:
    int x;
    int y;
};

inline bool operator==(const point &lhs, const point &rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

inline bool operator!=(const point &lhs, const point &rhs) {
    return (!operator==(lhs, rhs));
}

inline point operator+(point lhs, const point &rhs) {
    lhs += rhs;
    return lhs;
}

inline point operator-(point lhs, const point &rhs) {
    lhs -= rhs;
    return lhs;
}

inline std::ostream &operator<<(std::ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
} // namespace ppc
#endif // POINT_HEADER