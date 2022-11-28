#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed& base);
        ~Fixed();
        Fixed &operator=(const Fixed& rhs);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int _fix;
        static const int _rightBitsNum = 8;

};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);

#endif