#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point &other) {
    *this = other;
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}