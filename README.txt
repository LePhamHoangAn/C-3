Team members: Elnara Biekirova, An Le Pham Hoang
Repository link: https://github.com/LePhamHoangAn/C-3



------------------------------------GAME DESCRIPTION--------------------------------------
This is a copy of the classic game "Asteroids". Player controlls the movement of the ship 
across the map and destroyls floating objects (asteroids and UFO) by shooting projectiles 
at them to collect points. Spaceship cam move on both x and y axis of the window. Asteroids
float randomly across the screen, while UFO moves along the x axis on the bottom of the 
screen and shoots projectiles upwards. If spaceship collides with an asteroid, UFO or UFO
bullet, it loses 1 health. After the player has lost all of the 3 lives, the game over screen
appears. If spaceships bullet hit UFO, it gets destroyed, spawning no more bullets; player
gets a certain amount of points for destroying it. If spaceships bullet collides with an
asteroid, the asteroid splits in half; player gets a certain amount of points for destroying
an asteroid. Asteroid can be split in two up to 3 times.  
   
The project includes: 
"Game.h" & "Game cpp" - contains all of the game componets, updates them. Handles the 
collision between all objects and handles world wrap. Spawns the asteroids. 
"Spaceship.h " & "Spaceship.cpp" - contains all of the ships components and behaviour 
(draw, movement, shoot, update functions). 
"Bullet.h" & "Bullet.cpp" - contains all of the bullets components and behaviour (update,
movement, draw fucntions.
"Asteroid.h" & "Asteroid.cpp" - contains all of the asteroids components and behaviours
(update, movement, draw).
"UFO.h" & "UFO.cpp" - contains all of the ufos' components and behaviours (update, 
movement, draw)
"UFOBullet.h" & "UFOBllet.cpp" - contains all of the bullets components and behaviour 
(update, movement, draw fucntions.
"GUI.h" & "GUI.cpp" - contains all GUI componets and behaviours (update, score, lives)  

------------------------------------PLAYER CONTROLS--------------------------------------

"UP" key - thrust, moves the spaceship.
"LEFT/RIGHT" keys - rotate the spaceshipship.
"DOWN" key - teleports the spaceship to a random location on the window.
"SPACE" key - shoots a projectile from the top of the ship. 

---------------------------------TEAMMATE TASKS------------------------------------------
An:
- Entirety of "Asteroid.h" and "Asteroid.cpp". Partially "Game.h" and "Game.cpp".
- Wrote collision for spaceship with asteroids and spaceship bullets with asteroids.
- Game::Setup(), drawasteroids(), worldwrap(). 
- Added sounds to the game.

Elnara:
- Entirety of "Spaceship.h", "Spaceship.cpp", "UFO.h", "UFO.cpp", "Bullet.h", "Bullet.cpp",
"UFOBullet.h", "UFOBullet.cpp", "GUI.h", "GUI.cpp".
- Wrote collision for spaceship with UFO, spaceship with UFO bullet and spaceship bullet
 with UFO.
- Game::Gameover().