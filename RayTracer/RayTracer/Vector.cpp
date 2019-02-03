#include "pch.h"
#include "Vector.h"


Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Vector::~Vector()
{
}


Vector Vector::cross(const Vector & other)
{
	double x = this->z * other.y - this->y * other.z;
	double y = this->x * other.z - this->z * other.x;
	double z = this->y * other.x - this->x * other.y;

	return Vector(x, y, z).normalize();
}

double Vector::dot(const Vector & other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

double Vector::length()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector& Vector::normalize()
{
	double len = this->length();
	this->x = this->x / len;
	this->y = this->y / len;
	this->z = this->z / len;

	return *this;
}

void Vector::transform()
{
}

Vector operator+(const Vector & a, const Vector & b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector & a, const Vector & b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z-b.z);
}
