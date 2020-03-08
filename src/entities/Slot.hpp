#ifndef Slot_hpp
#define Slot_hpp

#include "SDL2/SDL.h"

#include "../InputHandler.hpp"
#include "../libAddon/Circle.hpp"

class Slot {

public:
	Slot(int radius, float x, float y);
	~Slot();

	void update(int delta, InputHandler*& inputHandler);
	void render(SDL_Renderer*& renderer);

private:
	int radius;
	float x;
	float y;
};

#endif