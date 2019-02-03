#pragma once

// A vector has a magnitude in XYZ. 
class Vector
{
public:
	double x, y, z;

	Vector();
	Vector(double x, double y, double z);
	~Vector();

	// You can add and subtract vectors
	friend Vector operator+ (const Vector& a, const Vector& b);
	friend Vector operator- (const Vector& a, const Vector& b);

	// Other self explanatory vector functions
	// Dot and cross product
	Vector cross(const Vector& other);
	double dot(const Vector& other);

	//Length of vector (magnitude)
	double length();

	// Normalize the vector
	Vector& normalize();

	// Transform the vector
	// TODO not sure how.
	void transform();
};

