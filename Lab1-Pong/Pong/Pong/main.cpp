/*
Ethan Benoit
GAME202: Object Oriented Programming
Majid Moghadam
Pong
January 13th, 2020
*/

//
#include "SDL.h"


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
	Ball.x = 370;
	Ball.y = 290;
	Ball.w = 20;
	Ball.h = 20;
}

/*
Purpose of the Input function:
*/
void Input() {

}

/*
Purpose of the Update function:
*/
void Update()
{
	bool check_collision(SDL_Rect A, SDL_Rect B)
	{

		// The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
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
		topB = B.x + B.w;
		bottomB = B.y + B.h;

		// If any of the sides from A are outside of B
		if (bottomA <= bottomB)
		{
			return false;
		}

		if (topA >= bottomB)
		{
			return false;
		}

		if (rightA <= leftB)
		{
			return false;
		}

		if (leftA >= rightB)
		{
			return false;
		}

		// If none of the sides from A are outside of B
		return true;

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
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &PlayerPaddle);
	SDL_RenderFillRect(renderer, &AIPaddle);

	// Draws the ball in the program
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Ball);


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
		// Initializs the LoadGame portion of the program
		LoadGame();

		//
		while (running == true)
		{
			Input();		// Initializes the Input portion of the program
			Update();		// Initializes the Update portion of the program
			DrawScreen();	// Initializes the DrwaScreen portion of the program

		}

		// Closes the program
		Quit();

		return 0;
	}
