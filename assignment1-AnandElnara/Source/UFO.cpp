#include "UFO.h"



UFO::UFO()
{
	Position.x = 50;
	Position.y = 950;
	/*height = 50;
	width = Position.x + 50;*/
	radius = 25;
	speed = 2;
	IsShooting = false;
	bulletCooldown = 60;
	alive = true;
}

void UFO::DrawUFO()
{	
	DrawTextureEx(ufo, { Position.x-radius, Position.y-radius }, 1, 1, RAYWHITE);
}

void UFO::Movement()
{
	Position.x += speed;
	if (Position.x > 975 || Position.x < 25)
	{
		speed *= -1;
	}
}

void UFO::Update()
{
	if (alive != false)
	{

		DrawUFO();
		Movement();
		Shooting();
	}
}

void UFO::Load()
{
	ufo = LoadTexture("ass/ufo.png");
	UFOBullet::load();
	UFOBullet::Unload();
}

void UFO::Unload()
{
	UnloadTexture(ufo);
}

void UFO::Shooting()
{
	bulletCooldown--;

	if (bulletCooldown < 0)
	{
		UFOBullet newBullet(Position.x, Position.y);
		UFObullets.push_back(newBullet);
		bulletCooldown = 60;	
	}

	for (int i = 0; i < UFObullets.size(); i++)
	{
		UFObullets[i].Update();
	}

	DestroyBullet();
}

void UFO::DestroyBullet()
{
	for (int i = 0; i < UFObullets.size(); i++)
	{
		if (UFObullets[i].Position.y < 0)
		{
			UFObullets.pop_front();
		}
	}
}
