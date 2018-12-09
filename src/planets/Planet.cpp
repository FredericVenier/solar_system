#include "Planet.hpp"

Planet::Planet(int resources[EOE], int radius, int temperature, SDL_Renderer*& renderer) : radius(radius), temperature(temperature) {
	for(int i=0; i<EOE; i++) {
		this->resources[i] = resources[i];
	}

	slots = 3;

	img = new Image((char*)"res/images/planets/planet01.png", renderer);
	sprite = new Sprite(img);

	imgBckg = new Image((char*)"res/images/background.png", renderer);
	spriteBckg = new Sprite(imgBckg);
}

Planet::~Planet() {
	delete sprite;
	delete img;

	delete spriteBckg;
	delete imgBckg;
}

void Planet::update(int delta, InputHandler*& inputHandler) {

}

void Planet::render(SDL_Renderer*& renderer, int width, int height) {
	spriteBckg->render(renderer,0,0,width, height);
	sprite->render(renderer, 690, 270, width, height);
}
