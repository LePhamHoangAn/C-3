#pragma once
//Game.h
#pragma once
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "UFO.h"
#include "GUI.h"

class Game
{
	std::vector<Asteroid>asteroids;
	Spaceship spaceship;
	UFO ufo;
	GUI gui;

	Sound destroy = LoadSound("ass/destroy.ogg");
	

public:
	bool Gameover;
	Game();

	void drawasteroids();
	void Setup();
	void Update();
	void WorldWrap(); 
	void Collision();
	void GameOver();

	void shipbulletscollideasteroidandsplitting();
	void shipcollideasteroid();

	void loading();
	void unloading();

	void playexplosion();

};