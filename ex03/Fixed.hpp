#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);
    bool operator<(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &fixed1, Fixed &fixed2);
    static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
    static Fixed &max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
    
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    static const int fraction;
    int value;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif