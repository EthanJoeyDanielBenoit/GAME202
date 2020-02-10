// Ethan Benoit
// GAME202 - Lab4
// Feburary 10, 2020
// Majid Moghadam

//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{

    int i;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }

	if (SDL_NumJoysticks() > 0)
	{
		joy = SDL_JoystickOpen(0);

	}

    window = SDL_CreateWindow("Basic SDL 2.0 Sprites",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

	// Initializes the alien sprite and sets its fixed position
    if (LoadSprite("alien.bmp", sprite1) < 0)
        return false;

	positions[0].x = 0;
	positions[0].y = WINDOW_HEIGHT / 2 - sprite_h / 2;
	positions[0].w = sprite_w;
	positions[0].h = sprite_h;
	velocities[0].x = 0;
	velocities[0].y = 0;


	// Initializes the cannon sprite and sets its fixed position
	if (LoadSprite("cannon.bmp", sprite2) < 0)
		return false;

	positions[1].x = WINDOW_WIDTH - sprite_w;
	positions[1].y = WINDOW_HEIGHT / 2 - sprite_h / 2;
	positions[1].w = sprite_w;
	positions[1].h = sprite_h;
	velocities[1].x = 0;
	velocities[1].y = 0;


	// Initializes the cannonball sprite and sets its fixed position offscreen
	if (LoadSprite("cannonball.bmp", sprite3) < 0)
		return false;

	positions[2].x = -100;
	positions[2].y = 0;
	positions[2].w = sprite_w;
	positions[2].h = sprite_h;
	velocities[2].x = 0;
	velocities[2].y = 0;



	// initializes the fireball sprite and sets its fixed position offscreen
	if (LoadSprite("fireball.bmp", sprite4) < 0)
		return false;

	positions[3].x = -100;
	positions[3].y = 0;
	positions[3].w = sprite_w;
	positions[3].h = sprite_h;
	velocities[3].x = 0;
	velocities[3].y = 0;


    return true;
}

//==============================================================================
