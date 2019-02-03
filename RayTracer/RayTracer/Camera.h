#pragma once
#include "Point.h"
#include "Vector.h"

// Cameras have a position (point), a lookat (vector), and an up direction (vector)
class Camera
{
public:
	Point position;
	Vector lookat, up;
	Camera();
	~Camera();

	// Renders the world
	// TODO: not sure how. Also it's void render(World).
	void render();
};

