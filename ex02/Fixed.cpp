#include "Fixed.hpp"


// ------------ default ------------
Fixed::Fixed() : _fix(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// ------------ constructors ------------
Fixed::Fixed(const Fixed &instance) {
    // std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed::Fixed(const int n) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fix = n << _rightBitsNum;
}

Fixed::Fixed(const float f) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fix = roundf((f) * (1 << _rightBitsNum));
}

//------------ member functions ------------
int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fix);
}

void Fixed::setRawBits(const int raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_fix = raw;
}

float Fixed::toFloat( void ) const {
	return (float)_fix / (1 << _rightBitsNum);
}

int Fixed::toInt( void ) const {
	return _fix >> _rightBitsNum;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if ( a < b )
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if ( a < b )
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if ( a > b )
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if ( a > b )
		return (a);
	else
		return (b);
}

// -----------  operator overload  ------------
Fixed &Fixed::operator=(const Fixed &instance) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fix = instance.getRawBits();;
	return *this;
}

bool Fixed::operator>(const Fixed &instance) const {
	return (this->_fix > instance._fix);
}

bool Fixed::operator<(const Fixed &instance) const {
	return (this->_fix < instance._fix);
}

bool Fixed::operator>=(const Fixed &instance) const {
	return (this->_fix >= instance._fix);
}

bool Fixed::operator<=(const Fixed &instance) const {
	return (this->_fix <= instance._fix);
}

bool Fixed::operator==(const Fixed &instance) const {
	return (this->_fix == instance._fix);
}

bool Fixed::operator!=(const Fixed &instance) const {
	return (this->_fix != instance._fix);
}

Fixed Fixed::operator+(const Fixed &instance) {
	Fixed tmp;

	tmp._fix = this->_fix + instance._fix;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &instance) {
	Fixed tmp;

	tmp._fix = this->_fix - instance._fix;
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &instance) {
	Fixed tmp(this->toFloat() * instance.toFloat());
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &instance) {
	Fixed tmp(this->toFloat() / instance.toFloat());
	return (tmp);
}

Fixed &Fixed::operator++() {
	++this->_fix;
	return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp (*this);

    ++this->_fix;
    return tmp;
}

Fixed &Fixed::operator--() {
	--this->_fix;
	return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp (*this);

    --this->_fix;
    return tmp;
}

std::ostream &operator<<(std::ostream &out, const Fixed &instance) {
	out << instance.toFloat();
	return (out);
}