#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"

#include "InputHandler.hpp"
#include "menus/Menu.hpp"
#include "menus/TitleMenu.hpp"
#include "Player.hpp"

class Game {

public:
	Game();
	~Game();
	void setRenderer(SDL_Renderer*& rend);

	void newGame();
	void update(int delta, InputHandler*& inputHandler);
	void render(SDL_Renderer*& renderer, int width, int height);

	void setQuitting(bool b);
	bool isQuitting() const;

	void deleteMenu();

private:
	enum State
	{
		START_MENU,
		PLAY,
		EOE //End Of Enumeration
	};

	State state;

	bool quitting;

	Menu* menu;
	bool menuDeleted;

	Player* player;

	SDL_Renderer* renderer;
};

#endif