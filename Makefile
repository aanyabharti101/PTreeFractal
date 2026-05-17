CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: PTree

PTree: main.o PTree.o
	$(CXX) $(CXXFLAGS) -o PTree main.o PTree.o $(LIBS)

main.o: main.cpp PTree.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

PTree.o: PTree.cpp PTree.hpp
	$(CXX) $(CXXFLAGS) -c PTree.cpp

lint:
	cpplint *.cpp *.hpp

clean:
	rm -f *.o PTree
