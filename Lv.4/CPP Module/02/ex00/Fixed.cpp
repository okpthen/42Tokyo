#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_RawBitValue = 0;	
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
	std::cout << "getRawBits member function called" << std::endl;
	return (_RawBitValue);
}

void	Fixed::setRawBits(int const raw)
{
	_RawBitValue = raw;
}