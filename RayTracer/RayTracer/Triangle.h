#pragma once
#include "Object.h"
class Triangle :
	public Object
{
public:
	Point A, B, C;
	Point camA, camB, camC;
	Triangle();
	~Triangle();

	double intersect(Ray r);
	void transform(Eigen::Matrix4d transform);
};

