#include "util/point.hpp"
#include <iostream>

int main() {
    ppc::point p;
    std::cout << p << std::endl;
    p += ppc::point(1, 2);
    std::cout << p << std::endl;
    p -= ppc::point(0, 1);
    std::cout << p << std::endl;
    p == ppc::point(1, 1) ? std::cout << "y" << std::endl
                          : std::cout << "n" << std::endl;
    p != ppc::point(0, 0) ? std::cout << "y" << std::endl
                          : std::cout << "n" << std::endl;
    return 0;
}