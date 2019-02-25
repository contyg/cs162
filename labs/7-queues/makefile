default: main.cpp queue.cpp menu.cpp validate.cpp
	g++ -std=c++0x main.cpp queue.cpp menu.cpp validate.cpp -o lab7

zip:
	zip -D Lab7_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab7

clean: $(CLEAN)
	rm lab7