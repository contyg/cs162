default: main.cpp menu.cpp recursive.cpp validate.cpp
	g++ main.cpp menu.cpp recursive.cpp validate.cpp -o lab5

zip:
	zip -D Lab5_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./zoo

clean: $(CLEAN)
	rm lab5