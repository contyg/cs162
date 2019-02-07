default: main.cpp animal.cpp penguin.cpp tiger.cpp turtle.cpp zoo.cpp validation.cpp
	g++ main.cpp animal.cpp penguin.cpp tiger.cpp turtle.cpp zoo.cpp validation.cpp -o zoo

zip:
	zip -D Project2_Conty_Genevieve.zip *.hpp *.cpp design-test.pdf makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./zoo

clean: $(CLEAN)
	rm lab4