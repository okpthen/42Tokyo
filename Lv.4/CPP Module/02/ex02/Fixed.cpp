#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	_RawBitValue = 0;	
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(n << _RawBitLiteral);
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(n * (1 << _RawBitLiteral)));
}

Fixed::Fixed(const Fixed &othre)
{
	// std::cout << "Copy constructor called" << std::endl;
	_RawBitValue = (othre.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &other)
		this->_RawBitValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout <<"Destructor called" <<std::endl;
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

//The 6 comparison operators: >, <, >=, <=, == and !=.

bool	Fixed::operator>(const Fixed &n) const
{
	if (this->getRawBits() > n.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &n) const
{
	if (this->getRawBits() < n.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &n) const
{
	if (this->getRawBits() >= n.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &n) const
{
	if (this->getRawBits() <= n.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &n) const
{
	if (this->getRawBits() == n.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &n) const
{
	if (this->getRawBits() != n.getRawBits())
		return (true);
	return (false);
}

//The 4 arithmetic operators: +, -, *, and /.

Fixed	Fixed::operator+(const Fixed &n) const
{
	Fixed result(this->toFloat() + n.toFloat());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &n) const
{
	Fixed result(this->toFloat() - n.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &n) const
{
	Fixed result(this->toFloat() * n.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &n) const
{
	Fixed result(this->toFloat() / n.toFloat());
	return (result);
}

//The 4 increment/decrement operators: ++(prefix and postfix) and --(prefix and postfix).

Fixed	&Fixed::operator++()
{
	_RawBitValue ++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_RawBitValue ++;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	_RawBitValue --;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_RawBitValue --;
	return (tmp);
}

//four our function

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}