#include "pch.h"
#include "World.h"
#include "PointLight.h"

World::World()
{
}


World::~World()
{
}

void World::add(Object * o)
{
	objList.push_back(o);
}

void World::add(PointLight * l)
{
	lightList.push_back(l);
}

void World::transformAll(Eigen::Matrix4d transform)
{
	for (std::vector<Object*>::iterator it = objList.begin(); it != objList.end(); ++it) {
		(*it)->transform(transform);
	}
	for (std::vector<PointLight*>::iterator it = lightList.begin(); it != lightList.end(); ++it) {
		(*it)->transform(transform);
	}
}
