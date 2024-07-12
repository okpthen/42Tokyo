#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		long				_RawBitValue;
		static const int	_RawBitLiteral = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &n);
		Fixed &operator=( const Fixed &n );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;


		bool	operator>(const Fixed &n) const;
		bool	operator<(const Fixed &n) const;
		bool	operator>=(const Fixed &n) const;
		bool	operator<=(const Fixed &n) const;
		bool	operator==(const Fixed &n) const;
		bool	operator!=(const Fixed &n) const;

		Fixed	operator+(const Fixed &n) const;
		Fixed	operator-(const Fixed &n) const;
		Fixed	operator/(const Fixed &n) const;
		Fixed	operator*(const Fixed &n) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif