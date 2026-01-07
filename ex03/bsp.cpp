#include "Point.hpp"

// area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|

Fixed area(Point const &a, Point const &b, Point const &c) {
    Fixed tmp = ((a.getX() * (b.getY() - c.getY())) +
                 (b.getX() * (c.getY() - a.getY())) +
                 (c.getX() * (a.getY() - b.getY()))) /
                2;
    if (tmp < 0)
        tmp = tmp * -1;
    return (tmp);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed area1 = area(a, b, c);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(a, point, c);
    Fixed area4 = area(a, b, point);

    if (area2 == 0 || area3 == 0 || area4 == 0)
        return false;
    return (area2 + area3 + area4 == area1);
}