default: main.cpp menu.cpp validate.cpp
	g++ -std=c++0x main.cpp menu.cpp validate.cpp -o lab

zip:
	zip -D Lab9_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab

clean: $(CLEAN)
	rm lab