#pragma once
#include <vector>
#include "Object.h"
class World
{
public:
	std::vector<Object*> list = {};
	
	// Attributes here
	//

	World();
	~World();

	void add(Object* o);

private:

};

