// Ethan Benoit
// GAME202 - Lab4
// Feburary 10, 2020
// Majid Moghadam

//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
	switch (Event->type)
	{

	case SDL_QUIT:
		Running = false;
		break;
	case SDL_KEYDOWN:
		Running = false;
		break;

		// Maps the control scheme for the mouse when controlling the alien
	case SDL_MOUSEMOTION:
		positions[0].y = Event->motion.y;

		// Maps the fire button on the mouse when firing a fireball from the alien
	case SDL_MOUSEBUTTONDOWN:
		if (Event->button.button == 1) {
			positions[3].x = positions[0].x;
			positions[3].y = positions[0].y;
			velocities[3].x = 1;
		}

		break;

	// Maps the control scheme for the joystick when controlling the cannon
	case SDL_JOYAXISMOTION:
		positions[1].y = Event->jaxis.value;

		break;

	// Maps the fire button on the joystick when firing a cannonball from the cannon
	case SDL_JOYBUTTONDOWN:

		if (Event->jbutton.which == 0 && Event->jbutton.button == 0) // Button 1 on 1st Joystick
		{
			// sets the sprites position when pressing fire button
			positions[2].x = positions[1].x;
			positions[2].y = positions[1].y;
			velocities[2].x = -1;
		}
		else if (Event->jbutton.which == 0 && Event->jbutton.button == 1)  // Button 2 on 1st Joystick
		{
			// Immidiently quits the program when pressing button #2
			Running = false;
		}
		break;
	}

	
}

//==============================================================================
