#pragma once

// Materials have color
// And other properties but that's later

class Material
{
public:
	double r, g, b;
	Material();
	Material(double r, double g, double b);
	~Material();
};

