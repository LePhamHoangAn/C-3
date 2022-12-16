#include "UFOBullet.h"

Texture UFOBullet::bullet;

UFOBullet::UFOBullet(float x, float y)
{
	/*bullet = LoadSprite("assets/bullet.png");*/
	Position.x = x;
	Position.y = y;
	radius = 1.5;
	speed = 5;
}

void UFOBullet::Update()
{
	DrawUFOBullet();
	Movement();
}

void UFOBullet::Unload()
{
	UnloadTexture(bullet);
}

void UFOBullet::DrawUFOBullet()
{
	DrawTextureEx(bullet, { Position.x-radius, Position.y-radius }, 1, 1, RAYWHITE);
}

void UFOBullet::load()
{
	bullet = LoadTexture("ass/bullet.png");
}

void UFOBullet::Movement()
{
	Position.y -= speed;
}

