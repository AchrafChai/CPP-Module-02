#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called\n";
};

Fixed::Fixed(const int number) : value(number * (1 << fraction)) {
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fraction))) {
    std::cout << "Float constructor called\n";
}

float Fixed::toFloat(void) const {
    return (value / float(1 << fraction));
}

int Fixed::toInt(void) const {
    return (value / (1 << fraction));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called\n";
    *this = other;
};

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called\n";
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

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    value = raw;
}
