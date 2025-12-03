#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    static const int fraction;
    int value;
};

#endif