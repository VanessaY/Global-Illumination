#include "pch.h"
#include "Sphere.h"


Sphere::Sphere()
{
	radius = 0;
	center = Point(0, 0, 0);
}


Sphere::~Sphere()
{
}

double Sphere::intersect(Ray r)
{
	double dx = r.direction.x;
	double dy = r.direction.y;
	double dz = r.direction.z;

	double xo = r.origin.x;
	double yo = r.origin.y;
	double zo = r.origin.z;
	
	double xc = camCenter.x;
	double yc = camCenter.y;
	double zc = camCenter.z;

	double A = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
	double B = 2 * (dx * (xo - xc) + dy * (yo - yc) + dz * (zo - zc));
	double C = pow(xo - xc, 2) + pow(yo - yc, 2) + pow(zo - zc, 2) - pow(radius, 2);

	double precheck = B * B - 4 * A * C;
	if (precheck < 0) {
		return 0;
	}
	else {
		double plus = (-B + sqrt(precheck)) / (2 * A);
		double minus = (-B - sqrt(precheck)) / (2 * A);

		if (plus < minus) {
			return plus;
		}
		else {
			return minus;
		}
	}
}

void Sphere::transform(Eigen::Matrix4d transform)
{

	camCenter = center;
	std::cout << camCenter.x << " " << camCenter.y << " " << camCenter.z << std::endl;
	camCenter.transform(transform);
	std::cout << camCenter.x << " " << camCenter.y << " " << camCenter.z << std::endl;
}
