#include "pch.h"
#include "Material.h"


Material::Material()
{
	r = 255;
	g = 255;
	b = 255;
}

Material::Material(double r, double g, double b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


Material::~Material()
{
}
