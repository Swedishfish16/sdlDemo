/*
*1. Init SDL and create window
*2. Game loop and event handling
*3. 
*/

// third-party libraries
#ifdef _WIN32
#include <SDL.h>
#else
#include<SDL2/SDL.h>
#endif

// C++ libraries
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {


	// Create window
	SDL_Window *window=nullptr;

	// Initialize SDL video system for event handling, file I/O and threading
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized " << SDL_GetError();
	}
	else {
		std::cout << "SDL video system is initialized\n";
	}

	//Create application window with the following settings
	window = SDL_CreateWindow( 
		"Game Demo",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	// Infinite loop for our application
	bool gameIsRunning = true;
	while(gameIsRunning){
		SDL_Event event;
		// Start our event loop
		while(SDL_PollEvent(&event)) {
			//Handle each specific event
			if(event.type == SDL_QUIT){
				gameIsRunning = false;
			}
			//if(event.type == SDL_MOUSEMOTION) {
			//	std::cout << "Mouse has been moved\n";
			//}
			//if(event.type == SDL_KEYDOWN) {
			//	std::cout << "Key has been pressed\n";
			//}

			// Handle arrow up key event
			//	if(event.key.keysym.sym == SDLK_UP ) {
			//		std::cout << "The up key was pressed!\n";
			//	}
			
			// Handle keyboard events with keyboard state
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if(state[SDL_SCANCODE_RIGHT]){
				std::cout << "Right arrow key pressed!\n";
			}
			else if (state[SDL_SCANCODE_LEFT]) {
				std::cout << "Left arrow key pressed!\n";
			}
			else if (state[SDL_SCANCODE_UP]) {
				std::cout << "Up arrow key pressed!\n";
			}
			else if (state[SDL_SCANCODE_DOWN]) {
				std::cout << "Down arrow key pressed!\n";
			}
	
		}
		
	}


	// Frees up the window from memory
	SDL_DestroyWindow(window);

	//uninitialize SDL video systems
	SDL_Quit();



	return 0;
}

/********** Some notes
* There's alot of using raw pointers and having to manually allocate and 
deallocate memory in sdl, this is due to the sdl library being written in C.
**********/