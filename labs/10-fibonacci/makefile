default: main.cpp fibonacci.cpp
	g++ -std=c++0x main.cpp fibonacci.cpp -o lab

zip:
	zip -D Lab10_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab

clean: $(CLEAN)
	rm lab