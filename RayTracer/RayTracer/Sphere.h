#pragma once
#include "Object.h"
#include "Ray.h"
class Sphere :
	public Object
{
public:
	Point center;
	Point camCenter;
	double radius;
	Sphere();
	~Sphere();

	// Returns 0 if no intesect
	// Else returns distance from ray origin that it intersects
	double intersect(Ray r);

	void transform(Eigen::Matrix4d transform);
};

