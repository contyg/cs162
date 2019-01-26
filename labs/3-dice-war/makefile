# TODO: valgrind options, validate.cpp

default: main.cpp game.cpp loadedDie.cpp die.cpp validate.cpp
	g++ -std=c++0x main.cpp game.cpp loadedDie.cpp die.cpp validate.cpp -o ./lab3

zip:
	zip -D Lab3_Conty_Genevieve.zip *.cpp *.hpp makefile design-test.pdf

clean: $(CLEAN)
	rm lab3
