#pragma once
#include <SFML/Graphics/Color.hpp>
// Materials have color
// And other properties but that's later

class Material
{
public:
	sf::Uint8 r, g, b;
	double diffuseR, diffuseG, diffuseB = 0;
	double specularR, specularG, specularB = 1;

	//diffuseReflec + specularReflec < 1
	double ambientReflec, diffuseReflec, specularReflec = 0;
	double specularHighlight = 0;

	Material();
	Material(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b);
	~Material();
};

