#include "pch.h"
#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

double Triangle::intersect(Ray r)
{
	//std::cout << "BEGIN" << std::endl;
	//std::cout << camA.x << " " << camA.y << " " << camA.z << std::endl;
	//std::cout << camB.x << " " << camB.y << " " << camB.z << std::endl;
	//std::cout << camC.x << " " << camC.y << " " << camC.z << std::endl;
	//
	//std::cout << r.direction.x << " " << r.direction.y << " " << r.direction.z << std::endl;
	//std::cout << r.origin.x << " " << r.origin.y << " " << r.origin.z << std::endl;

	Vector p0(camA.x, camA.y, camA.z);
	Vector p1(camB.x, camB.y, camB.z);
	Vector p2(camC.x, camC.y, camC.z);

	Vector e1 = p1 - p0;
	Vector e2 = p2 - p0;

	Vector rayOrigin(r.origin.x, r.origin.y, r.origin.z);
	Vector T = rayOrigin - p0;
	Vector P = r.direction.cross(e2);
	Vector Q = T.cross(e1);

	if (P.dot(e1) == 0) {
		return 0;
	}
	else {
		double coeff = 1 / P.dot(e1);

		double W = coeff * Q.dot(e2);
		double U = coeff * P.dot(T);
		double V = coeff * Q.dot(r.direction);

		if (W < 0) {
			return 0;
		}
		else if ((U < 0) || (V < 0) || (U + V > 1)) {
			return 0;
		}
		else {
			return W;
		}
	}
}


void Triangle::transform(Eigen::Matrix4d transform)
{
	camA = A;
	camA.transform(transform);

	camB = B;
	camB.transform(transform);

	camB = B;
	camB.transform(transform);
}
