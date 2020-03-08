#include "Circle.hpp"

SDLAddon_Circle::SDLAddon_Circle(int radius, float x, float y) : radius(radius), x(x), y(y) {

}

SDLAddon_Circle::~SDLAddon_Circle() {

}

void SDLAddon_Circle::renderFillCircle(SDL_Renderer*& renderer) {
	float radiusDraw = radius;
	float alpha = 0;
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	while(radiusDraw > 0)
	{
		float diameter = (radiusDraw * 2);

		float xDraw = (radiusDraw - 0.5f);
		float yDraw = 0;
		float txDraw = 0.5f;
		float tyDraw = 0.5f;
		float error = (txDraw - diameter);

		while (xDraw >= yDraw)
		{
			SDL_SetRenderDrawColor(renderer, 80, 150, 255, alpha);

			//  Each of the following renders an octant of the circle
			SDL_RenderDrawPoint(renderer, x + xDraw, y - yDraw);
			SDL_RenderDrawPoint(renderer, x + xDraw, y + yDraw);
			SDL_RenderDrawPoint(renderer, x - xDraw, y - yDraw);
			SDL_RenderDrawPoint(renderer, x - xDraw, y + yDraw);
			SDL_RenderDrawPoint(renderer, x + yDraw, y - xDraw);
			SDL_RenderDrawPoint(renderer, x + yDraw, y + xDraw);
			SDL_RenderDrawPoint(renderer, x - yDraw, y - xDraw);
			SDL_RenderDrawPoint(renderer, x - yDraw, y + xDraw);

			if (error <= 0)
			{
				yDraw += 0.5f;
				error += tyDraw;
				tyDraw += 1.0f;
			}

			if (error > 0)
			{
				xDraw -= 0.5f;
				txDraw += 1.0f;
				error += (txDraw - diameter);
			}
		}

		radiusDraw -= 1.0f;
		alpha = (1.0f-radiusDraw/radius)*150.0f;
	}
}
