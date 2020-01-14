/*
Ethan Benoit
GAME202: Object Oriented Programming
Majid Moghadam
Pong
January 13th, 2020
*/

//
#include "SDL.h"
#include <cstdlib>

//
SDL_Event event;

// Mouse coordinates
int mouse_x, mouse_y;

int speed_x, speed_y;
int direction[2] = { -1, 1 };

//
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

//
SDL_Renderer *renderer;

//
bool running = true;

//
SDL_Rect PlayerPaddle;
SDL_Rect AIPaddle;
SDL_Rect Ball;
SDL_Rect Net;

/*
Purpose of the LoadGame function:
*/
void LoadGame()
{
	//
	SDL_Window *window;

	//
	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window) {
		return;
	}



	//
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		return;

		speed_x = -1;
		speed_y = -1;
	}

	// sets the location values for where the Player's paddle is located
	PlayerPaddle.x = 20;
	PlayerPaddle.y = 250;
	PlayerPaddle.h = 100;
	PlayerPaddle.w = 20;

	// set the location for where the AI paddle is located
	AIPaddle.x = 760;
	AIPaddle.y = 250;
	AIPaddle.h = 100;
	AIPaddle.w = 20;

	// sets the location values for where the ball's origin point is
	Ball.x = 350;
	Ball.y = 290;
	Ball.w = 20;
	Ball.h = 20;


	// sets the location values for where the net is located
	Net.x = 380;
	Net.y = 0;
	Net.w = 10;
	Net.h = 600;
}

/*
Purpose of the Input function:
*/
void Input() {

	// Queuing events
	while (SDL_PollEvent(&event)) {

		// Track mouse movement
		if (event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&mouse_x, &mouse_y);

		// Clicking 'X' or pressing F4
		if (event.type == SDL_QUIT)
			running = false;

		// Pressing a key
		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym)
			{
				// Pressing ESC exits from the game
			case SDLK_ESCAPE :
				running = false;
				break;

			}
	}
}

/*
Purpose of the Update function:
*/
void Update()
{
	PlayerPaddle.y = mouse_y;

	Ball.x += 1;
	Ball.y += 1;
	Ball.x += speed_x;
	Ball.y += speed_y;
	
	AIPaddle.y = Ball.y - AIPaddle.h / 2 + Ball.h / 2;

	SDL_Delay(10);

	if (Ball.x < 0 || Ball.x > WINDOW_WIDTH)
	{
		Ball.x = WINDOW_WIDTH / 2;
		Ball.y = WINDOW_HEIGHT / 2;
		// this expression produces random numbers -1, -1 and 2
		speed_x = (rand() % 2 + 1) * direction[rand() % 2];
		speed_y = (rand() % 2 + 1) * direction[rand() % 2];

	}

	if (Ball.y < 0 || Ball.y > (WINDOW_HEIGHT - Ball.h))
	{
		speed_y = -speed_y;
	}

	if (check_collision(Ball, AIPaddle) || check_collision(Ball, PlayerPaddle))
	{
		speed_x = -speed_x;
	}
	
}

/*
Purpose of DrawScreen function:
*/
void DrawScreen()
{
	//
	SDL_RenderClear(renderer);

	// Draws and colors the background of the program
	SDL_Rect background = { 0, 0, 800, 600 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);

	// Draws and colors the paddle sticks in the program 
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 200);
	SDL_RenderFillRect(renderer, &PlayerPaddle);
	

	// Draws and colors the AI Paddle stick in  the program
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &AIPaddle);

	// Draws the ball in the program
	SDL_SetRenderDrawColor(renderer, 300, 255, 0, 0);
	SDL_RenderFillRect(renderer, &Ball);

	// Draws the Net in the program
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &Net);

	//
	SDL_RenderPresent(renderer);
}

	/*
	Purpose of the Quit function:
	*/
	void Quit()
	{
		//
		SDL_Quit();
	}

	/*
	Purpose of the Main function
	*/
	int main(int argc, char *argv[])
	{
		//
		LoadGame();

		bool check_collision(SDL_Rect A, SDL_Rect B)
		{
			// The sides of the rectangles
			int leftA, leftB;
			int rightA, leftB;
			int topA, topB;
			int bottomA, bottomB;

			// Calculate the sides of rect A
			leftA = A.x;
			rightA = A.x + A.w;
			topA = A.y;
			bottomA = A.y + A.h;

			// Calculate the sides of rect B
			leftB = B.x;
			rightB = B.y;
			topB. = B.x + B.w;
			bottomB = B.y + B.h;

			// If any of the sides from A are outside of B
			if (bottomA <= bottomB)
			{
				return false;
			}

			if (topA >= topB)
			{
				return false;
			}

			if (rightA <= rightB)
			{
				return false;
			}

			if (leftA >= leftB)
			{
				return false;
			}

			// if none of the sides from A are outside of B

			return true;
		}

		//
		while (running == true)
		{
			Input();		//
			Update();		//
			DrawScreen();	//

		}



		//
		Quit();

		return 0;
	}