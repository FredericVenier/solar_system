#include "Game.hpp"

Game::Game() : quitting(false), menuDeleted(false) {
	menu = new TitleMenu(this);
}

Game::~Game() {
	//delete player;
}

void Game::newGame() {
	//player = new Player();
}

void Game::update(int delta, InputHandler*& inputHandler) {
	//menu
	if(menu != NULL) {
		menu->update(delta, inputHandler);
	}

	if(menuDeleted) {
		menuDeleted = false;
		delete menu;
		menu = NULL;
	}


	//player
	//player->update(delta, keys)
}
	
void Game::render(SDL_Renderer*& renderer, int width, int height) {
	if(menu != NULL) {
		menu->render(renderer, width, height);
	}

	//player->render(renderer, width, height);
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