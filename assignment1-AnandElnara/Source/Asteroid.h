#pragma once
#include "raylib.h"
#include "Math.h"


class Asteroid
{
public:
	float SpeedX{};
	float SpeedY{};
	float Angle{};
	float Size{};
	float Radius{};
	float Rotate{};

	//only need to send the texture once
	static Texture asteroidpic;


	Vector2 position{};

	Asteroid(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation);

	void moving();
	static void loadtexture();
	void drawasteroid();
	static void unloadasteroids();
};


