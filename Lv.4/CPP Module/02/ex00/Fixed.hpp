#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_RawBitValue;
		static const int	_RawBitLiteral = 8;
	public:
		Fixed();
		Fixed(const Fixed &othre);
		Fixed& operator=( const Fixed& othre );
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif