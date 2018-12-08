#include "Game.hpp"

Game::Game() : state(START_MENU), quitting(false), menuDeleted(false) {
	menu = new TitleMenu(this);
	renderer = NULL;
	player = NULL;
}

Game::~Game() {
	delete player;
}

void Game::setRenderer(SDL_Renderer*& rend) {
	renderer = rend;
}

void Game::newGame() {
	state = PLAY;
	player = new Player();
}

void Game::update(int delta, InputHandler*& inputHandler) {
	switch(state) {
		case START_MENU: //si on est dans le menu de demarrage
			if(menu != NULL) menu->update(delta, inputHandler);

			if(menuDeleted) {
				menuDeleted = false;
				delete menu;
				menu = NULL;
			}
		break;

		case PLAY: //si on joue
			if(player != NULL) player->update(delta, inputHandler);
		break;

		default:
		break;
	}	
}
	
void Game::render(SDL_Renderer*& renderer, int width, int height) {
	switch(state) {
		case START_MENU: //si on est dans le menu de demarrage
			if(menu != NULL) menu->render(renderer, width, height);
		break;

		case PLAY: //si on joue
			if(player != NULL) player->render(renderer, width, height);
		break;

		default:
		break;
	}
}

void Game::deleteMenu() {
	menuDeleted = true;
}

void Game::setQuitting(bool b) {
	quitting = b;
}

bool Game::isQuitting() const {
	return quitting;
}