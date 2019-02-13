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
	double x = this->y * other.z - this->z * other.y;
	double y = this->z * other.x - this->x * other.z;
	double z = this->x * other.y - this->y * other.x;

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

void Vector::transform(Eigen::Matrix4d transform)
{
	Eigen::Vector4d vec(x, y, z, 1);
	vec = transform * vec;
	x = vec.x()/vec.w();
	y = vec.y()/vec.w();
	z = vec.z()/vec.w();
}

Vector operator+(const Vector & a, const Vector & b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector & a, const Vector & b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z-b.z);
}
