default: main.cpp menu.cpp validate.cpp boss.cpp health.cpp riddle.cpp space.cpp standard.cpp backpack.cpp warrior.cpp
	g++ -std=c++0x main.cpp menu.cpp validate.cpp boss.cpp health.cpp riddle.cpp space.cpp standard.cpp backpack.cpp warrior.cpp -o game

zip:
	zip -D FinalProject_Conty_Genevieve.zip *.hpp *.cpp design-reflection.pdf makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./game

clean: $(CLEAN)
	rm game