#include "pch.h"
#include "PointLight.h"


void PointLight::transform(Eigen::Matrix4d transform)
{
	camPosition = position;
	camPosition.transform(transform);
}

PointLight::PointLight()
{
}


PointLight::~PointLight()
{
}
