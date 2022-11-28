#include "Fixed.hpp"

// ------------ default ------------
Fixed::Fixed() : _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ------------ constructors ------------
Fixed::Fixed(const Fixed &base) {
    std::cout << "Copy constructor called" << std::endl;
	*this = base;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fix = n << _rightBitsNum;
}

// bit shift operation of 8
// (1<<1) is 1*(2^1) is 2, (1<<8) is 1*(2^8) is 256
// (1<<1) = 00000000 00000001 changes to 00000000 00000010
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fix = roundf((f) * (1 << _rightBitsNum));
}

//------------ member functions ------------
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fix);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fix = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)_fix / (1 << _rightBitsNum);
}

int Fixed::toInt( void ) const
{
	return _fix >> _rightBitsNum;
}

// -----------  operator overload  ------------
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fix = rhs.getRawBits();;
	return *this;
}

// ou = instance de ostream
// obj = instance de ma classe
// << inserer un entier vers la sortie de flux
// return out pour pouvoir le chainer
std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}