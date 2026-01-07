#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int number) : value(number * (1 << fraction)) {}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fraction))) {}

float Fixed::toFloat(void) const {
    return (value / float(1 << fraction));
}

int Fixed::toInt(void) const {
    return (value / (1 << fraction));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        value = other.value;
    return *this;
}

bool Fixed::operator<(const Fixed &other) const {
    return value < other.value;
}

bool Fixed::operator>(const Fixed &other) const {
    return value > other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return value <= other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return value >= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed fixed;
    fixed.value = value + other.value;
    return fixed;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed fixed;
    fixed.value = value - other.value;
    return fixed;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed fixed;
    long long tmp = (long long)value * other.value;
    fixed.value = int(tmp >> fraction);
    return fixed;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed fixed;
    long long tmp = ((long long)value << fraction) / other.value;
    fixed.value = int(tmp);
    return fixed;
}

Fixed &Fixed::operator++() {
    ++value;
    return *this;
};

Fixed Fixed::operator++(int) {
    Fixed fixed = *this;
    ++value;
    return fixed;
};

Fixed &Fixed::operator--() {
    --value;
    return *this;
};

Fixed Fixed::operator--(int) {
    Fixed fixed = *this;
    --value;
    return fixed;
};

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
    return (fixed1 < fixed2) ? fixed1 : fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
    return (fixed1 < fixed2) ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
    return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
    return (fixed1 > fixed2) ? fixed1 : fixed2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return os;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    value = raw;
}
