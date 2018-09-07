#include <curses.h>
#include <iostream>
#include "util/point.h"

int main() {
  ppc::Point p;
  std::cout << p << std::endl;
  p += ppc::Point(1, 2);
  std::cout << p << std::endl;
  p -= ppc::Point(0, 1);
  std::cout << p << std::endl;
  p == ppc::Point(1, 1) ? std::cout << "y" << std::endl
                        : std::cout << "n" << std::endl;
  p != ppc::Point(0, 0) ? std::cout << "y" << std::endl
                        : std::cout << "n" << std::endl;
  return 0;
}