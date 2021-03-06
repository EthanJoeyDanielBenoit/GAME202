// Ethan Benoit
// GAME202 - Lab4
// Feburary 10, 2020
// Majid Moghadam

//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define NUM_SPRITES     4
#define MAX_SPEED       1

//==============================================================================
class CApp
{
private:
    bool            Running;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *sprite1;		// alien sprite
	SDL_Texture *sprite2;		// cannon sprite
	SDL_Texture *sprite3;		// cannonball sprite
	SDL_Texture *sprite4;		// fireball sprite
    SDL_Rect positions[NUM_SPRITES];
    SDL_Rect velocities[NUM_SPRITES];
    int sprite_w, sprite_h;
	SDL_Joystick *joy = NULL;	// joystick value

public:
    CApp();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Texture* &LoadSprite);
    void MoveSprites();

    void OnCleanup();
};

//==============================================================================

#endif
