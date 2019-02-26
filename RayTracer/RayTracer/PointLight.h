#pragma once
#include "Point.h"
class PointLight
{
public:
	Point position;
	Point camPosition;

	double R = 0;
	double G = 0;
	double B = 0;

	void transform(Eigen::Matrix4d transform);
	PointLight();
	~PointLight();
};

