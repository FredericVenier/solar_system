#ifndef SDLAddon_Circle_hpp
#define SDLAddon_Circle_hpp

#include <iostream>

#include "SDL2/SDL.h"

class SDLAddon_Circle {

public:
	SDLAddon_Circle(int radius, float x, float y);
	~SDLAddon_Circle();

	void renderFillCircle(SDL_Renderer*& renderer);

private:
	int radius;
	float x;
	float y;
};

#endif