#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed& instance);
        ~Fixed();

        Fixed &operator=(const Fixed& instance);

        Fixed operator+(const Fixed &instance);
        Fixed operator-(const Fixed &instance);
        Fixed operator*(const Fixed &instance);
        Fixed operator/(const Fixed &instance);


        bool operator>(const Fixed &instance) const;
        bool operator>=(const Fixed &instance) const;
        bool operator<(const Fixed &instance) const;
        bool operator<=(const Fixed &instance) const;
        bool operator==(const Fixed &instance) const;
        bool operator!=(const Fixed &instance) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        static const    Fixed &min(const Fixed &a, const Fixed &b);
        static          Fixed &min(Fixed &a, Fixed &b);
        static const    Fixed &max(const Fixed &a, const Fixed &b);
        static          Fixed &max(Fixed &a, Fixed &b);

    private:
        int _fix;
        static const int _rightBitsNum = 8;

};

std::ostream &operator<<(std::ostream &out, Fixed const &instance);

#endif