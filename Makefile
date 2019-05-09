
# makefile #

all: bin/mancala runtest

runtest: bin/testmancala
	./bin/testmancala

bin/mancala: obj/main.o obj/MancalaBoard.o
	g++ -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala

bin/testmancala: obj/MancalaBoard.o obj/testmancala.o
	g++ -std=c++14 obj/MancalaBoard.o obj/testmancala.o -o bin/testmancala -DDEBUG -lgtest -lgtest_main  -lpthread

obj/main.o: src/main.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/main.cpp -o obj/main.o

obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

obj/testmancala.o: src/testmancala.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/testmancala.cpp -o obj/testmancala.o

clean:
	rm obj/*
	rm bin/*
