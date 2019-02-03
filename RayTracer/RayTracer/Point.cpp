#include "pch.h"
#include "Point.h"


Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::~Point()
{
}

double Point::distance(const Point& other)
{
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2) + pow(this->z - other.z, 2));
}

void Point::transform()
{
}
