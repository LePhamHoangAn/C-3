#include "GUI.h"


GUI::GUI()
{
	score = 0;
	life = 3;
}

void GUI::Update()
{
	Score(0);
	Lives(life);
}

void GUI::Score( int scr)
{
	score = score + scr;
	DrawText(TextFormat("Score: %08i", score), 10, 10, 30, GRAY);
}

void GUI::Lives(int l)
{
	life = l;
	DrawTextureEx(spaceship, { 900, 10 }, 1, 1, RAYWHITE);
	DrawText(TextFormat("X %01i", life), 940, 15, 30, GRAY);
}
