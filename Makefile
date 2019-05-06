# all: bin/mancala

# bin/mancala: obj/main.o obj/MancalaBoard.o
# 	g++ -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala
#
# obj/main.o: src/main.cpp src/MancalaBoard.h
# 	g++ -std=c++14 -c src/main.cpp -o obj/main.o
#
# obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
# 	g++ -std=c++14 src/MancalaBoard.cpp -o obj/MancalaBoard.o
#
# clean:
# 	rm *.o bin/mancala

# test
# Mancala.o test.o








CXX=g++


INCLUDE=-I src/
CXXFLAGS = -std=c++14 $(INCLUDE)

all: bin/mancala

bin/mancala: obj/main.o obj/MancalaBoard.o
	$(CXX) -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala

obj/main.o: src/main.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	$(CXX) $(CXXFLAGS) -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

clean:
	rm obj/*
