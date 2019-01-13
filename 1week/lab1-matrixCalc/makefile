
# VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

default: main.cpp determinant.cpp readMatrix.cpp
	g++ -std=c++0x main.cpp determinant.cpp readMatrix.cpp -o lab1

zip:
	zip -D Lab1_Conty_Genevieve.zip *.cpp *.hpp makefile

clean: $(CLEAN)
	rm lab1