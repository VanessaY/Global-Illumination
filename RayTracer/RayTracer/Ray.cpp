#include "pch.h"
#include "Ray.h"

Ray::Ray()
{
}


Ray::~Ray()
{
}

Ray::Ray(const Point& origin, const Vector& direction)
{
	this->origin.x = origin.x;
	this->origin.y = origin.y;
	this->origin.z = origin.z;

	this->direction.x = direction.x;
	this->direction.y = direction.y;
	this->direction.z = direction.z;
}
