//Game.cpp
#include "raylib.h"
#include "Game.h"


Game::Game()
{
	Gameover = false; 
	Setup();
}


void Game::Setup()
{

	int asteroidcount = 2;
	//asteroids	

	//waves
	if (gui.score > 5500)
	{
		asteroidcount++;
	}
	if (gui.score > 10000)
	{
		asteroidcount++;
	}
	if (gui.score > 16000)
	{
		asteroidcount++;
	}
	if (gui.score > 20000)
	{
		asteroidcount++;
	}
	//asteroids	
	for (int i = 0; i < asteroidcount; i++)
	{
		float posX   = (float)(rand() % 1000+500);
		float posY   = (float)(rand() % 1000+500);
		float speedX = (float)(rand() % 3 + 1);
		float speedY = (float)(rand() % 3 + 1);
		float angle  = (float)(rand() % 360);
		float rotate = (float)(rand() % 5 + 2);
		Asteroid asteroid(2, 150, posX, posY, angle, speedX, speedY, rotate);
		asteroids.push_back(asteroid);
	}

}

void Game::drawasteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].drawasteroid();
	}
}



void Game::Update()
{
	if (asteroids.empty())
	{
		Game::Setup();
	}
	if (Gameover != true)
	{

		GameOver();
		spaceship.Update();
		ufo.Update();
		gui.Update();
		Collision();
		shipbulletscollideasteroidandsplitting();
		shipandass();

		for (Asteroid& asteroid : asteroids)  //for each asteroid in the vector 
		{
			asteroid.moving();
		}
		WorldWrap();

		ClearBackground(BLACK);
		Game::drawasteroids();
		
	}

	GameOver();
}

void Game::WorldWrap()
{
	if (spaceship.Position.x <= 0)
	{
		spaceship.Position.x = 1000;
	}
	else if (spaceship.Position.x >= 1000)
	{
		spaceship.Position.x = 0;
	}

	if (spaceship.Position.y <= 0)
	{
		spaceship.Position.y = 1000;
	}
	else if (spaceship.Position.y >= 1000)
	{
		spaceship.Position.y = 0;
	}

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].position.x <= 0)
		{
			asteroids[i].position.x = 1000;
		}
		else if (asteroids[i].position.x >= 1000)
		{
			asteroids[i].position.x = 0;
		}

		if (asteroids[i].position.y <= 0)
		{
			asteroids[i].position.y = 1000;
		}
		else if (asteroids[i].position.y >= 1000)
		{
			asteroids[i].position.y = 0;
		}
	}
}

void Game::shipbulletscollideasteroidandsplitting()
{
	for (int j = (int)asteroids.size() - 1; j >= 0; j--)
	{
		for (int i = (int)spaceship.bullets.size() - 1; i >= 0; i--)
		{
			if (CheckCollisionCircles(asteroids[j].position, asteroids[j].Radius, spaceship.bullets[i].Position, spaceship.bullets[i].radius) == true)
			{
				for (int a = 0; a < 2; a++)
				{
					float angle = asteroids[j].Angle + rand() % 60 - 60;
					float speedX = (float)(rand() % 5 + 1);
					float speedY = (float)(rand() % 5 + 1);

					//Asteroid::Asteroid(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation)
					Asteroid asteroid(asteroids[j].Size * 0.5f, asteroids[j].Radius * 0.5f, asteroids[j].position.x, asteroids[j].position.y, angle, speedX, speedY, 1);

					if (asteroid.Size >= 0.5f)
					{
						asteroids.push_back(asteroid);
					}
				}
				spaceship.bullets.erase(spaceship.bullets.begin() + i);
				asteroids.erase(asteroids.begin() + j);
				gui.Score(1000);
				playexplosion();
			

				break;
			}
		}
	}
}


void Game::shipandass()
{
	for (Asteroid& asteroid : asteroids)  //for each asteroid in the vector 
	{
		if (CheckCollisionCircles(spaceship.Position, spaceship.radius, asteroid.position, asteroid.Radius))
		{
			spaceship.Position.x = 500;
			spaceship.Position.y = 500;
			playexplosion();
			gui.life--;
		}
	}
}


void Game::Collision()
{

// Spaceship UFO collision
	if (CheckCollisionCircles(spaceship.Position, spaceship.radius, ufo.Position, ufo.radius))
	{
		playexplosion();
		spaceship.Position.x = 500;
		spaceship.Position.y = 500;
		gui.life--;
	}

//Spaceship bullet and ufo collision
	for (int b = 0; b < spaceship.bullets.size(); b++)
	{
		if (CheckCollisionCircles(spaceship.bullets[b].Position, spaceship.bullets[b].radius, ufo.Position, ufo.radius) && ufo.alive != false)
		{
			playexplosion();
			ufo.alive = false;
			gui.Score(1000);
		}
	}

	//Spaceship and ufo bullet collision
	for (int b = 0; b < ufo.UFObullets.size(); b++)
	{
		if (CheckCollisionCircles(ufo.UFObullets[b].Position, ufo.UFObullets[b].radius, spaceship.Position, spaceship.radius))
		{
			playexplosion();
			spaceship.Position.x = 500;
			spaceship.Position.y = 500;
			gui.life--;
		}
	}
}

void Game::GameOver()
{
	if (gui.life <= 0)
	{
		gui.life = 0;
		Gameover = true;
		DrawText("Game over", 400 ,500, 50, RAYWHITE);
	}
}

void Game::playexplosion()
{
	PlaySoundMulti(destroy);
}


void Game::loading()
{
	destroy = LoadSound("ass/destroy.ogg"); 
	spaceship.load();
	Asteroid::loadtexture();
	ufo.Load();
	Bullet::Load();
}

void Game::unloading()
{
	UnloadSound(destroy);
	Asteroid::unloadasteroids();
	spaceship.unload();
	Bullet::Unload();
	ufo.Unload();
}