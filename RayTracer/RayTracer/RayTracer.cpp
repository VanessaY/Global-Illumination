// RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Sphere.h"
#include "Material.h"
int main()
{
	double SCREEN_WIDTH = 2;
	double SCREEN_HEIGHT = 1.5;
	int PIX_WIDTH = 400;
	int PIX_HEIGHT = 300;

	// World creation ==============================================================================================
	World w;

	// Material creation ===========================================================================================
	Material* glassMat = new Material(255, 255, 255);
	Material* metalMat = new Material(50, 50, 50);

	// Sphere initialization =======================================================================================
	Sphere* glass = new Sphere();
	glass->radius = 4;
	glass->center = Point(4, 9, -3);
	glass->material = glassMat;
	w.add(glass);

	Sphere* metal = new Sphere();
	metal->radius = 3;
	metal->center = Point(7, 8, 0);
	metal->material = metalMat;
	w.add(metal);

	// Camera creation =============================================================================================
	Camera camera;
	camera.eyepoint = Vector(0, 0, 0);
	camera.lookat = Vector(0, 0, 1).normalize();
	camera.up = Vector(0, 1, 0).normalize();
	camera.screenHeight = SCREEN_HEIGHT;
	camera.screenWidth = SCREEN_WIDTH;
	camera.pixHeight = PIX_HEIGHT;
	camera.pixWidth = PIX_WIDTH;
	camera.focalLength = 1;

	sf::Uint8* pixels = new sf::Uint8[PIX_WIDTH*PIX_HEIGHT * 4];
	sf::Texture texture;
	texture.create(PIX_WIDTH, PIX_HEIGHT);

	sf::Sprite sprite(texture);

	camera.render(w, pixels);

	texture.update(pixels);


	sf::RenderWindow window(sf::VideoMode(PIX_WIDTH, PIX_HEIGHT), "SFML works!");

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	delete[] pixels;
	delete glassMat;
	delete metalMat;
	delete glass;
	delete metal;
	return 0;
}
