default: main.cpp DoublyLinkedList.cpp menu.cpp validate.cpp
	g++ main.cpp DoublyLinkedList.cpp menu.cpp validate.cpp -o lab6

zip:
	zip -D Lab6_Conty_Genevieve.zip *.hpp *.cpp makefile

valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab6

clean: $(CLEAN)
	rm lab6