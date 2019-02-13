#include "pch.h"
#include "Camera.h"
#include <vector>
#include <float.h>
Camera::Camera()
{

}


Camera::~Camera()
{
}


void Camera::render(World w, sf::Uint8 * pixels)
{
	Vector N = lookat.normalize();
	Vector U = up.cross(N).normalize();
	Vector V = N.cross(U).normalize();
	//std::cout << N.x << " " << N.y << " " << N.z << std::endl;
	//std::cout << U.x << " " << U.y << " " << U.z << std::endl;
	//std::cout << V.x << " " << V.y << " " << V.z << std::endl;

	Vector negEye = Vector(-eyepoint.x, -eyepoint.y, -eyepoint.z);
	Eigen::Matrix4d transform;
	transform << U.x, V.x, N.x, 0,
				U.y, V.y, N.y, 0,
				U.z, V.z, N.z, 0,
				negEye.dot(U), negEye.dot(V), negEye.dot(N), 1;
	
	std::cout << transform << std::endl;
	std::vector<Object*> list = w.list;
	for (std::vector<Object*>::iterator it = list.begin(); it != list.end(); ++it) {
		(*it)->transform(transform);
	}

	double pixelWidth = screenWidth / pixWidth;
	double pixelHeight = screenHeight / pixHeight;

	for (int x = 0; x < pixWidth; x++)
	{
		for (int y = 0; y < pixHeight; y++)
		{
			Ray fired;
			fired.origin = Point(0, 0, 0);
			fired.direction = Vector(	-(screenWidth / 2) + pixelWidth / 2 + x*pixelWidth, 
										screenHeight / 2 - pixelHeight / 2 - y * pixelHeight, 
										focalLength).normalize();
			
			Object* closest = *list.begin();
			double closestOmega = DBL_MAX;
			for (std::vector<Object*>::iterator it = list.begin(); it != list.end(); ++it) {
				double omega = (*it)->intersect(fired);
				if (omega > 0) {
					if (omega < closestOmega) {
						closest = *it;
						closestOmega = omega;
					}
				}
			}

			if (closestOmega != DBL_MAX) {
				pixels[(x + y * pixWidth) * 4] = closest->material->r;
				pixels[(x + y * pixWidth) * 4 + 1] = closest->material->g;
				pixels[(x + y * pixWidth) * 4 + 2] = closest->material->b;
				pixels[(x + y * pixWidth) * 4 + 3] = 255;
			}
			else
			{
				pixels[(x + y * pixWidth) * 4] = 0;
				pixels[(x + y * pixWidth) * 4 + 1] = 0;
				pixels[(x + y * pixWidth) * 4 + 2] = 0;
				pixels[(x + y * pixWidth) * 4 + 3] = 255;
			}
		}
	}

}
