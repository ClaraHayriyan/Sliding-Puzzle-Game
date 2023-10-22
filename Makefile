CC = g++

EXEC = slidingpuzzle

all : $(EXEC)

Puzzle.o : Puzzle.cpp Puzzle.hpp
	$(CC) Puzzle.cpp -c -o $@

GameView.o : GameView.cpp GameView.hpp Puzzle.hpp
	$(CC) GameView.cpp -c -o $@

Game.o : Game.cpp Game.hpp Puzzle.hpp GameView.hpp
	$(CC) Game.cpp -c -o $@

Menu.o : Menu.cpp Menu.hpp
	$(CC) Menu.cpp -c -o $@

MenuView.o : MenuView.cpp MenuView.hpp Menu.hpp
	$(CC) MenuView.cpp -c -o $@

MenuController.o : MenuController.cpp MenuController.hpp Menu.hpp MenuView.hpp
	$(CC) MenuController.cpp -c -o $@

Controller.o : Controller.cpp Controller.hpp Game.hpp MenuController.hpp
	$(CC) Controller.cpp -c -o $@

main.o : main.cpp Controller.hpp
	$(CC) main.cpp -c -o $@

$(EXEC) : Puzzle.o GameView.o Game.o Menu.o MenuView.o MenuController.o Controller.o main.o
	$(CC) $? -o $@ -lncurses

clean :
	rm -rf $(EXEC) *.o
