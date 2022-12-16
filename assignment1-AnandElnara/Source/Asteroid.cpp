
#include "Asteroid.h"

Texture Asteroid::asteroidpic;

Asteroid::Asteroid(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation)
{
	Rotate = rotation;
	Size = size;
	Radius = radius;
	position.x = posX;
	position.y = posY;
	SpeedX = speedX;
	SpeedY = speedY;
	Angle = angle;	
}

void Asteroid::moving()
{
	position.x += (float)sin((Angle * 3.14) / 180) * SpeedX;
	position.y -= (float)cos((Angle * 3.14) / 180) * SpeedY;
}

void Asteroid::loadtexture()
{
	asteroidpic = LoadTexture("Ass/asteroid.png");
}

void Asteroid::drawasteroid()
{
	DrawTextureEx(asteroidpic, Vector2{ position.x - Radius, position.y - Radius }, Rotate, Size, WHITE);
}

void Asteroid::unloadasteroids()
{
	UnloadTexture(asteroidpic);
}




