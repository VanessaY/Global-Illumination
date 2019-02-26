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
	Eigen::Vector3d p0(camA.x, camA.y, camA.z);
	Eigen::Vector3d p1(camB.x, camB.y, camB.z);
	Eigen::Vector3d p2(camC.x, camC.y, camC.z);

	Eigen::Vector3d O(r.origin.x, r.origin.y, r.origin.z);
	Eigen::Vector3d D(r.direction.x, r.direction.y, r.direction.z);

	Eigen::Vector3d e1 = p1 - p0;
	Eigen::Vector3d e2 = p2 - p0;

	Eigen::Vector3d T = O - p0;
	
	Eigen::Vector3d P = D.cross(e2);

	Eigen::Vector3d Q = T.cross(e1);

	float denom = P.dot(e1);
	if (denom == 0) {
		return 0;
	}
	else {
		Eigen::Vector3d wuv = 1 / denom * Eigen::Vector3d(Q.dot(e2), P.dot(T), Q.dot(D));
		//std::cout << -p0 << std::endl;
		if (wuv.x() < 0) {
			return 0;
		}
		else if (wuv.y() < 0 || wuv.z() < 0 || wuv.y() + wuv.z() > 1) {
			return 0;
		}
		else {
			return wuv.x();
		}
	}

}


void Triangle::transform(Eigen::Matrix4d transform)
{
	camA = A;
	camA.transform(transform);

	camB = B;
	camB.transform(transform);

	camC = C;
	camC.transform(transform);
}
