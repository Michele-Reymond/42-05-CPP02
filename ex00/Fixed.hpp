#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& base);
        ~Fixed();
        Fixed &operator=(const Fixed& rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fix;
        static const int _rightBitsNum = 8;

};

#endif