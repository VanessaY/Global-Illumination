#pragma once
#include "Point.h"
#include "Vector.h"
#include "World.h"
#include <SFML/Graphics/Color.hpp>
// Cameras have a position (point), a lookat (vector), and an up direction (vector)
// Changing eyepoint to a vector because of the dot product shenanigans. Shouldn't affect it.
class Camera
{
public:
	Vector eyepoint;
	Vector lookat;
	Vector up;

	double screenHeight;
	double screenWidth;
	int pixHeight;
	int pixWidth;

	double focalLength;

	Camera();
	~Camera();

	// Renders the world
	void render(World w, sf::Uint8* pixels);
};

