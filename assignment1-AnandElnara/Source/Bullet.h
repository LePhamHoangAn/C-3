#pragma once
//Bullet.h
#include "raylib.h"
#include <math.h>

class Bullet
{
	static Texture bullet;
	Vector2 Velocity;
	float speed, angle;
	bool alive;
	
public:
	float radius;
	Vector2 Position;

	Bullet(float posX, float posY, float ang);

	void Update();
	void DrawBullet();
	void Movement();
	static void Load();
	static void Unload();


};