/*
Copyright (C) 1997-2011 Sam Lantinga <slouken@libsdl.org>

This software is provided 'as-is', without any express or implied
warreaty. In no event will the author be held liable for damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely.
*/
/* Simple program: Move N sprites around on the screen as fast as possible */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "SDL.h"

#ifdef __NDS__
#define WINDOW_WIDTH	256
#define WINDOW_HEIGHT	(2*192)
#else
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#endif
#define NUM_SPRITES	10
#define MAX_SPEED	1

static SDL_Texture *sprite;
static SDL_Rect positions[NUM_SPRITES];
static SDL_Rect velocities[NUM_SPRITES];
static int sprite_w, sprite_h;

/* Call this instead of exit(), so we can clean up SDL: atexit() is evil. */
static void
quit(int rc)
{
	exit(rc);
}

void DisplayModifiers(SDL_KeyboardEvent *key)
{
	Uint16 modifier = key->keysym.mod;
	if ( modifier & KMOD_NUM ) printf( "NUMLOCK " );
	if ( modifier & KMOD_CAPS ) printf( "CAPSLOCK  " );
	if ( modifier & KMOD_MODE ) printf( "MODE " );
	if ( modifier & KMOD_LCTRL ) printf( "LCTRL ");
	if ( modifier & KMOD_RCTRL ) printf( "RCTRL " );
	if ( modifier & KMOD_LSHIFT ) printf( "LSHIFT " );
	if ( modifier & KMOD_RSHIFT ) printf( "RSHIFT ");
	if ( modifier & KMOD_LALT ) printf( "LALT" );
	if ( modifier & KMOD_RALT ) printf( "RALT" );

}

void DisplayKey(SDL_KeyboardEvent *key)
{
	printf( "%s\n,", SDL_GetKeyName(key->keysym.sym));
}
int
LoadSprite(char *file, SDL_Renderer *renderer)
{
	SDL_Surface *temp;

	/* Load the sprites image */
	temp = SDL_LoadBMP(file);
	if (temp == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s", file, SDL_GetError());
		return(-1);
	}
	sprite_w = temp->w;
	sprite_h = temp->h;

	/* Set transparent pixel as the pixel at (0,0) */
	if (temp->format->palette)
	{
		SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *)temp->pixels);
	}
	else
	{
		switch (temp->format->BitsPerPixel)
		{
		case 15:
			SDL_SetColorKey(temp, SDL_TRUE,
				(*(Uint16 *) temp->pixels) & 0x00007fff);

			break;
		case 16:
				SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *)temp->pixels);
		break;
		case 24:
			SDL_SetColorKey(temp, SDL_TRUE,
				(*(Uint32 *)temp->pixels) & 0x00FFFFFF);

			break;
			case 32:
				SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *)temp->pixels);
				break;
		}
	}

	/* Create texture from the image */
	sprite = SDL_CreateTextureFromSurface(renderer, temp);
	if (!sprite)
	{
		fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(temp);
		return(-1);
	}
	SDL_FreeSurface(temp);

	/* We're ready to roll :) */
	return(0);
}

void
MoveSprites(SDL_Window * window, SDL_Renderer * renderer, SDL_Texture * sprite)
{
	int i;
	int window_w = WINDOW_WIDTH;
	int window_h = WINDOW_HEIGHT;
	SDL_Rect *position, *velocity;

	/* */

}