#pragma once
#include "raylib.h"

class UFOBullet
{
	static Texture bullet;
	float speed{}, height{}, width{};

public:
	float radius{};
	Vector2 Position{};
	UFOBullet(float x, float y);
	void Update();
	static void load();
	static void Unload();
	void DrawUFOBullet();
	void Movement();
};