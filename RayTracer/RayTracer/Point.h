#pragma once

// A point has a location in xyz.

class Point
{
public:
	double x, y, z;

	Point();
	Point(double x, double y, double z);
	~Point();


	// Checks the distance between this point and another point
	double distance(const Point& other);

	// Transforms the point.
	// Takes a 4x4 transformation matrix
	void transform(Eigen::Matrix4d transform);
};

