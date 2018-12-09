#ifndef Planet_hpp
#define Planet_hpp

#include "SDL2/SDL.h"

#include "../InputHandler.hpp"
#include "../gui/Sprite.hpp"
#include "../gui/Image.hpp"

class Planet {

public:
	enum Resources {
		A,
		B,
		C,
		EOE
	};

	Planet(int resources[EOE], int radius, int temperature, SDL_Renderer*& renderer);
	~Planet();

	void update(int delta, InputHandler*& inputHandler);
	void render(SDL_Renderer*& renderer, int width, int height);

private:
	int resources[EOE];
	int radius;
	int slots;
	int temperature;

	Image* img;
	Sprite* sprite;

	Image* imgBckg;
	Sprite* spriteBckg;
};

#endif