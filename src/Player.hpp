#ifndef Player_hpp
#define Player_hpp

#include "SDL2/SDL.h"

#include "InputHandler.hpp"

class Player {

public:
	Player();
	~Player();

	void update(int delta, InputHandler*& inputHandler);
	void render(SDL_Renderer*& renderer, int width, int height);

};

#endif