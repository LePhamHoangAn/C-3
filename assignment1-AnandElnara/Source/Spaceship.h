#pragma once
// Spaceship.h
#include "raylib.h"
#include "Bullet.h" 
#include <math.h>
#include <deque>

class Spaceship
{
	Vector2 Velocity{};
	float acceleration{};
	Texture2D spaceship{};

	Sound pew;

	int bulletCooldown{}, teleportcooldown{};
	bool IsShooting{};

	enum class input
	{
		Gas,
		Left,
		Right,
		Teleport,
		Idle
	}inp;

public:
	std::deque<Bullet> bullets;
	Spaceship();
	Vector2 Position;
	float radius{}, angle{};
	void Update();
	void drawShip();
	void Input();
	void Movement();
	void Shooting();
	void DestroyBullet();

	void load();
	void unload();

};
