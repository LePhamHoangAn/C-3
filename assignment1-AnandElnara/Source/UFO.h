#pragma once
#include <deque>
#include "Spaceship.h"
#include "UFOBullet.h"

class UFO
{
	float height{}, width{};
	float speed{};
	int bulletCooldown{};
	Texture ufo{};
public:
	float radius{};
	bool IsShooting{}, alive{};
	Vector2 Position{};
	std::deque <UFOBullet> UFObullets;

	UFO();

	void DrawUFO();
	void Movement();
	void Update();
	void Shooting();
	void DestroyBullet();

	void Load();
	void Unload();

};