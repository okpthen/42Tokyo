#include "Point.hpp"

Point::Point(void)
{
	_x = 0;
	_y = 0;
}

Point::Point(const Fixed x, const Fixed y)
{
	_x = x;
	_y = y;
}

Point::Point(const Point &p)
{
	_x = p.getX();
	_y = p.getY();
}

Point&	Point::operator=(const Point &p)
{
	if (this != &p)
	{
		this->_x = p.getX();
		this->_y = p.getY();
	}
	return (*this);
}

Point::~Point(){}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
