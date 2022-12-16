//Bullet.cpp
#include "Bullet.h"

Texture Bullet::bullet;

Bullet::Bullet(float posX, float posY, float ang)
{
	angle = ang * -1.0f;
	Position.x = 0;
	Position.y = 0;
	Position.x = posX;
	Position.y = posY;
	radius = 1.5;
	Velocity.x = float(sin((angle * 3.14) / 180));
	Velocity.y = float(cos((angle * 3.14) / 180));
	speed = 5;
	alive = true;
}

void Bullet::Update()
{
	DrawBullet();
	Movement();
}

void Bullet::DrawBullet()
{
	DrawTextureEx(bullet, { Position.x - radius, Position.y - radius }, angle, 1, RAYWHITE);
}

void Bullet::Load()
{
	bullet = LoadTexture("ass/bullet.png");
}

void Bullet::Unload()
{
	UnloadTexture(bullet);
}

void Bullet::Movement()
{
	Position.x -= (Velocity.x * speed);
	Position.y -= (Velocity.y * speed);
}

