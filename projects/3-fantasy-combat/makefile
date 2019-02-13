default: main.cpp menu.cpp barbarian.cpp vampire.cpp medusa.cpp harryPotter.cpp blueMen.cpp character.cpp validate.cpp
	g++ -std=c++0x main.cpp menu.cpp barbarian.cpp vampire.cpp medusa.cpp harryPotter.cpp blueMen.cpp character.cpp validate.cpp -o game

zip:
	zip -D Project3_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./game

clean: $(CLEAN)
	rm game