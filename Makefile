CXX=g++
CXXFLAGS= -Wall -std=c++11 -g -O3
EXEC_FILES= main test

all: main

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

test: test.o coord.o  animal.o population.o grille.o jeu.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main: main.o test.o coord.o animal.o population.o grille.o jeu.o
	$(CXX) -o $@ $^ $(LDFLAGS)


coord.o : coord.hpp
test.o : coord.hpp animal.hpp population.hpp grille.hpp jeu.hpp
animal.o : animal.hpp
population.o : population.hpp
grille.o : grille.hpp
jeu.o : jeu.hpp

clean:
	rm -f *.o $(EXEC_FILES)
