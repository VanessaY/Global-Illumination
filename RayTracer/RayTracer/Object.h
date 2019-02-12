#pragma once

#include "Material.h"
#include "Ray.h"

class Object
{
public:
	Material* material;
	Object();
	~Object();

	virtual double intersect(Ray r) = 0;
	virtual void transform(Eigen::Matrix4d transform) = 0;
};
