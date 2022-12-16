#pragma once
#include "raylib.h"
#include <string>

class GUI
{
	Texture spaceship;

public:
	int life, score;

	GUI();
	void Update();
	void Score(int scr);
	void Lives(int life);
};