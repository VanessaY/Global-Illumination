#pragma once
#include <vector>
#include "Object.h"
#include "PointLight.h"
class World
{
public:
	std::vector<Object*> objList = {};
	std::vector<PointLight*> lightList = {};
	// Attributes here
	//
	double ambiantR = 0;
	double ambiantG = 0;
	double ambiantB = 0;

	World();
	~World();

	void add(Object* o);
	void add(PointLight* l);

	void transformAll(Eigen::Matrix4d transform);

private:

};

