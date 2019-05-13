
CXX=g++
CXXFLAGS= -std=c++14
TESTFLAGS= -lgtest -lgtest_main -lpthread

all: directories bin/mancala runtest

runtest: bin/testmancala
	./bin/testmancala

bin/mancala: obj/main.o obj/MancalaBoard.o
	$(CXX) $(CXXFLAGS) obj/main.o obj/MancalaBoard.o -o bin/mancala

bin/testmancala: obj/MancalaBoard.o obj/testmancala.o
	$(CXX) $(CXXFLAGS) obj/MancalaBoard.o obj/testmancala.o -o bin/testmancala $(TESTFLAGS)

obj/main.o: src/main.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

obj/testmancala.o: src/testmancala.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/testmancala.cpp -o obj/testmancala.o

directories: obj/ bin/

obj/:
	mkdir obj

bin/:
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/
