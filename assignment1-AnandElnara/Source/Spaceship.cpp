//Spaceship.cpp

#include "Spaceship.h"


Spaceship::Spaceship()
{
	//spaceship = ("ass/spaceship.png");
	Position.x = 500;
	Position.y = 500;
	radius = 15;
	angle = 0;
	Velocity.x = 1;
	Velocity.y = 1;
	acceleration = 0;
	teleportcooldown = 0;
	inp = input::Idle;
}

void Spaceship::Update()
{
	drawShip();
	Input();
	Movement();
	Shooting();
}

void Spaceship::drawShip()
{
	DrawTextureEx(spaceship, { Position.x - radius, Position.y - radius }, angle, 1, RAYWHITE);
}

void Spaceship::Input()
{
	if (IsKeyDown(KEY_UP))
	{
		inp = input::Gas;
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		inp = input::Left;
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		inp = input::Right;
	}
	else
	{
		inp = input::Idle;
	}

	if (IsKeyDown(KEY_SPACE))
	{
		IsShooting = true;
	}
	else
	{
		IsShooting = false;
	}
	if (IsKeyDown(KEY_DOWN) && teleportcooldown < 0)
	{
		inp = input::Teleport;
	}
}

void Spaceship::Movement()
{
	Velocity.x = sinf((angle * 3.14f) / 180);
	Velocity.y = cosf((angle * 3.14f) / 180);
	Position.x += (Velocity.x * acceleration);
	Position.y -= (Velocity.y * acceleration);

	switch (inp)
	{
	case input::Gas:
	{
		if (acceleration < 5)
		{
			acceleration++;
		}
		else if (acceleration == 5)
		{
			acceleration = 5;
		}
		break;
	}

	case input::Right:
	{
		angle += 2;
		break;
	}
	case input::Left:
	{
		angle -= 2;
		break;
	}
	case input::Idle:
	{
		break;
	}
	case input::Teleport:
	{
		Position.x = float(rand() % 1000);
		Position.y = float(rand() % 1000);
		teleportcooldown = 300;
		break;
	}
	}
	acceleration *= 0.99f;
}

void Spaceship::Shooting()
{
	bulletCooldown--;

	if (bulletCooldown < 0)
	{
		if (IsShooting == true)
		{
			Bullet newBullet(Position.x, Position.y, angle);
			bullets.push_back(newBullet);
			bulletCooldown = 20;
		}
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update();
	}

	IsShooting = false;

	DestroyBullet();
}

void Spaceship::DestroyBullet()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].Position.y < 0 || bullets[i].Position.y > 1000 ||
			bullets[i].Position.x < 0 || bullets[i].Position.x > 1000)
		{
			bullets.pop_front();
		}
	}
}

void Spaceship::load()
{
	pew = LoadSound("ass/pew.ogg");
	spaceship = LoadTexture("ass/spaceship.png");
}

void Spaceship::unload()
{
	UnloadTexture(spaceship);
	UnloadSound(pew);
}



