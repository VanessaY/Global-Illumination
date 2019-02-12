#include "pch.h"
#include "World.h"


World::World()
{
}


World::~World()
{
}

void World::add(Object * o)
{
	list.push_back(o);
}
