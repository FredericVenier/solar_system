#include "Slot.hpp"

Slot::Slot(int radius, float x, float y) : radius(radius), x(x), y(y) {

}

Slot::~Slot() {

}

void Slot::update(int delta, InputHandler*& inputHandler) {

}

void Slot::render(SDL_Renderer*& renderer) {
	SDLAddon_Circle* circle = new SDLAddon_Circle(radius, x, y);
	circle->renderFillCircle(renderer);
}
