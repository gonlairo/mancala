
# my own based on the GNU tutorial

bin/mancala: obj/main.o MancalaBoard.o
	g++ -std=c++14 -c src/main.cpp -o obj/main.o

main.o: src/main.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/main.cpp -o obj/main.o

MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
	g++ -std=c++14 -c src/MancalaBoard.cpp -o obj/MancalaBoard.o

clean:
	rm obj/*








	## try to do create two exectuables:one for the test and one fot the game

# 	CXX=g++
#
# 	INCLUDE=-I src/
# 	CXXFLAGS = -std=c++14 $(INCLUDE)
#
# # all: bin/manca
#
# bin/mancala: obj/main.o obj/MancalaBoard.o
# 	$(CXX) -std=c++14 obj/main.o obj/MancalaBoard.o -o bin/mancala
#
# bin/testmancala: obj/testmancala.o
# 	$(CXX) -std=c++14 obj/testmancala.o -o bin/mancala
#
# obj/testmancala.o: src/testmancala.cpp src/testmancala.h
# 	$(CXX) $(CXXFLAGS) -c src/testmancala.cpp -o obj/testmancala.o
#
# obj/main.o: src/main.cpp src/MancalaBoard.h
# 	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o
#
# obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
# 	$(CXX) $(CXXFLAGS) -c src/MancalaBoard.cpp -o obj/MancalaBoard.o
#
# clean:
# 	rm obj/*







# # try to do create only one executable
#
# CXX=g++
#
# INCLUDE=-I src/
# CXXFLAGS = -std=c++14 $(INCLUDE)
#
# all: bin/mancala
#
# bin/mancala: obj/main.o obj/MancalaBoard.o obj/testmancala.o
# 	$(CXX) -std=c++14 obj/main.o obj/MancalaBoard.o obj/testmancala.o -o bin/mancala
#
# obj/testmancala.o: src/testmancala.cpp src/MancalaBoard.h
# 	$(CXX) $(CXXFLAGS) -c src/testmancala.cpp -o obj/testmancala.o
#
# obj/main.o: src/main.cpp src/MancalaBoard.h
# 	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o
#
# obj/MancalaBoard.o: src/MancalaBoard.cpp src/MancalaBoard.h
# 	$(CXX) $(CXXFLAGS) -c src/MancalaBoard.cpp -o obj/MancalaBoard.o
#
# clean:
# 	rm obj/*
