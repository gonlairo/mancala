

bin/mancala: obj/main.o obj/MancalaBoard.o
	g++ -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala

obj/main.o: src/main.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/main.cpp -o obj/main.o

obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

clean:
	rm obj/*
	rm bin/*
