#pragma once
#include <SFML/Graphics/Color.hpp>
// Materials have color
// And other properties but that's later

class Material
{
public:
	sf::Uint8 r, g, b;
	Material();
	Material(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b);
	~Material();
};

