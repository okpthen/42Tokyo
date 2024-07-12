#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &p);
		Point &operator=(const Point &p);
		~Point();

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point o);

#endif