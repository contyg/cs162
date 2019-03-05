default: main.cpp validate.cpp searchAndSort.cpp
	g++ -std=c++0x main.cpp validate.cpp searchAndSort.cpp -o lab

zip:
	zip -D Project3_Conty_Genevieve.zip *.hpp *.cpp *.txt makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab

clean: $(CLEAN)
	rm lab