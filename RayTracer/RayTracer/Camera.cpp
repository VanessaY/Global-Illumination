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
	std::cout << eyepoint.x << " " << eyepoint.y << " " << eyepoint.z << std::endl;
	std::cout << lookat.x << " " << lookat.y << " " << lookat.z << std::endl;
	std::cout << eyepoint.x - lookat.x << " " << eyepoint.y - lookat.y << " " << eyepoint.z - lookat.z << std::endl;

	Vector N = Vector(eyepoint.x - lookat.x, eyepoint.y - lookat.y, eyepoint.z - lookat.z).normalize();
	Vector U = up.cross(N).normalize();
	Vector V = N.cross(U).normalize();

	std::cout << U.x << " " << U.y << " " << U.z << std::endl;
	std::cout << V.x << " " << V.y << " " << V.z << std::endl;
	std::cout << N.x << " " << N.y << " " << N.z << std::endl;

	Vector negEye = Vector(-eyepoint.x, -eyepoint.y, -eyepoint.z);
	Eigen::Matrix4d transform;
	/*
	transform << U.x, V.x, N.x, 0,
				U.y, V.y, N.y, 0,
				U.z, V.z, N.z, 0,
				negEye.dot(U), negEye.dot(V), negEye.dot(N), 1;
	*/
	transform << U.x, U.y, U.z, negEye.dot(U),
				V.x, V.y, V.z, negEye.dot(V),
				N.x, N.y, N.z, negEye.dot(N),
				0, 0, 0, 1;
	std::cout << transform << std::endl;
	std::vector<Object*> list = w.objList;
	w.transformAll(transform);

	double pixelWidth = screenWidth / pixWidth;
	double pixelHeight = screenHeight / pixHeight;


	for (int x = 0; x < pixWidth; x++)
	{
		for (int y = 0; y < pixHeight; y++)
		{
			int r = 0;
			int g = 0;
			int b = 0;

			
			sf::Uint8 a = 255;

			for (int w = 0; w < 1; w++) {
				for (int h = 0; h < 1; h++) {
					Ray fired;
					fired.origin = Point(0, 0, 0);
					fired.direction = Vector(-(screenWidth / 2) + pixelWidth / 2 + x * pixelWidth - pixelWidth / 4 + w * (pixelWidth / 2),
						screenHeight / 2 - pixelHeight / 2 - y * pixelHeight - pixelHeight / 4 + h * (pixelHeight / 2),
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
						r += closest->material->r;
						g += closest->material->g;
						b += closest->material->b;
					}
					else
					{
						r += 0;
						g += 0;
						b += 0;
					}
				}
			}

			r /= 1;
			g /= 1;
			b /= 1;

			pixels[(x + y * pixWidth) * 4] = r;
			pixels[(x + y * pixWidth) * 4 + 1] = g;
			pixels[(x + y * pixWidth) * 4 + 2] = b;
			pixels[(x + y * pixWidth) * 4 + 3] = 255;
		}
	}

}
