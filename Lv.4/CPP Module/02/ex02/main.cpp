#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		Fixed	a;
		Fixed	b(123);
		std::cout << std::endl;
		std::cout << a <<std::endl;
		std::cout << b <<std::endl;
	}
	{
		Fixed	const a = 22;
		Fixed	const b(33.234f);
		Fixed	const c = 33.466f;
		Fixed	d;
		d = a + c;
		std::cout << std::endl;
		std::cout << a <<std::endl;
		std::cout << b <<std::endl;
		std::cout << c <<std::endl;
		std::cout << d <<std::endl;
		std::cout << Fixed::min(a, b) << std::endl;
	}
	return 0;
}