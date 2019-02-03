#pragma once
#include "Point.h"
#include "Vector.h"

// A ray has an origin and a direction, a point and a vector.

class Ray
{
public:
	Ray();
	~Ray();
	Ray(const Point& origin, const Vector& direction);
	Point origin;
	Vector direction;
};

