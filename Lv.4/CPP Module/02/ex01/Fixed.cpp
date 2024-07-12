#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_RawBitValue = 0;	
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << _RawBitLiteral);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(n * (1 << _RawBitLiteral)));
}

Fixed::Fixed(const Fixed &othre)
{
	std::cout << "Copy constructor called" << std::endl;
	_RawBitValue = (othre.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &other)
		this->_RawBitValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" <<std::endl;
}

int	Fixed::getRawBits(void)const
{
	return (_RawBitValue);
}

void	Fixed::setRawBits(int const raw)
{
	_RawBitValue = raw;
}

int	Fixed::toInt(void) const
{
	return (_RawBitValue >> _RawBitLiteral);
}

float	Fixed::toFloat(void) const
{
	return ((float)_RawBitValue / (1 << _RawBitLiteral));
}

std::ostream& operator<<( std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}