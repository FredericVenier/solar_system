#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"

#include "InputHandler.hpp"
#include "menus/Menu.hpp"
#include "menus/TitleMenu.hpp"

class Game {

public:
	Game();
	~Game();

	void newGame();
	void update(int delta, InputHandler*& inputHandler);
	void render(SDL_Renderer*& renderer, int width, int height);

	void setQuitting(bool b);
	bool isQuitting() const;

	void deleteMenu();

private:
	bool quitting;

	Menu* menu;
	bool menuDeleted;
};

#endif