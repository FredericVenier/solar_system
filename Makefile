CC = g++
CFLAGS = -Wall
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

game: obj/GameComponent.o obj/Game.o obj/InputHandler.o obj/Menu.o obj/ButtonsMenu.o obj/TitleMenu.o obj/MenuButton.o obj/Text.o obj/Player.o obj/Image.o obj/Sprite.o obj/Animation.o obj/BlockedAnimation.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

obj/%.o: src/%.cpp src/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/gui/%.cpp src/gui/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/menus/%.cpp src/menus/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/menus/menu_objects/%.cpp src/menus/menu_objects/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@