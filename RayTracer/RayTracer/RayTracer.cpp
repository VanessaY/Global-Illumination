// RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Sphere.h"
#include "Material.h"
#include "Triangle.h"
int main()
{
	double SCREEN_WIDTH = 20;
	double SCREEN_HEIGHT = 15;
	int PIX_WIDTH = 400;
	int PIX_HEIGHT = 300;

	// World creation ==============================================================================================
	World w;

	// Material creation ===========================================================================================
	Material* glassMat = new Material(255, 255, 255);
	Material* metalMat = new Material(50, 50, 50);
	Material* groundMat = new Material(0, 255, 255);

	// Sphere initialization =======================================================================================
	Sphere* glass = new Sphere();
	glass->radius = 2;
	glass->center = Point(-1, 0, 8);
	glass->material = glassMat;
	w.add(glass);

	Sphere* metal = new Sphere();
	metal->radius = 1.5;
	metal->center = Point(2, 0, 10);
	metal->material = metalMat;
	w.add(metal);

	// Ground initialization =======================================================================================
	Triangle* ground1 = new Triangle();
	ground1->A = Point(-1, 0, 6);
	ground1->B = Point(-1, 1, 6);
	ground1->C = Point(1, 0, 6);
	ground1->material = groundMat;
	w.add(ground1);
	Triangle* ground2 = new Triangle();

	// Camera creation =============================================================================================
	Camera camera;
	camera.eyepoint = Vector(0, 0, 0);
	camera.lookat = Vector(0, 0, 1).normalize();
	camera.up = Vector(0, 1, 0).normalize();
	camera.screenHeight = SCREEN_HEIGHT;
	camera.screenWidth = SCREEN_WIDTH;
	camera.pixHeight = PIX_HEIGHT;
	camera.pixWidth = PIX_WIDTH;
	camera.focalLength = 15;

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
	delete groundMat;
	delete glass;
	delete metal;
	delete ground1;
	delete ground2;
	return 0;
}
