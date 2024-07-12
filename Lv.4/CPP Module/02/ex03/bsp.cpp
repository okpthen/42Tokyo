#include "Point.hpp"

bool	check(const Fixed ab, const Fixed bc, const Fixed ca)
{
	if (ab > 0 && bc > 0 && ca > 0)
		return (true);
	if (ab < 0 && bc < 0 && ca < 0)
		return (true);
	return (false);
}

Fixed	cross(const Point a, const Point b, const Point o)
{
	return ((b.getX() - a.getX()) * (o.getY() - b.getY()) -
		(b.getY() - a.getY()) * (o.getX() - b.getX()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point o)
{
	Fixed	ab = cross(a, b, o);
	Fixed	bc = cross(b, c, o);
	Fixed	ca = cross(c, a, o);
	return (check(ab, bc, ca));
}
















	//b - a = ab = A
	//o - b = bo = B



//Ax * By - Ay *Bx