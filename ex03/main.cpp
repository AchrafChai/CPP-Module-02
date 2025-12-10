#include "Point.hpp"
#include <iostream>

int main(void) {

    Point a(0, 0);
    Point b(1, 0);
    Point c(0, Fixed(1.5f));

    Point p(Fixed(0.5f), Fixed(0.5f));

    if (bsp(a, b, c, p))
        std::cout << "inside\n";
    else
        std::cout << "outside\n";
    return 0;
}