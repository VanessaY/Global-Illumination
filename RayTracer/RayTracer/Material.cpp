#include "pch.h"
#include "Material.h"


Material::Material()
{
	r = 255;
	g = 255;
	b = 255;
}

Material::Material(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


Material::~Material()
{
}
