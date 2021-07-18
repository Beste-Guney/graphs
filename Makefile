hw4: Graph.o Stack.o Queue.o HashTable.o WordNetwork.o main.o
	g++ main.o Stack.o Graph.o Queue.o HashTable.o WordNetwork.o -o hw4
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Graph.o: Graph.cpp 
	g++ -std=c++11 -c Graph.cpp

Stack.o: Stack.cpp
	g++ -std=c++11 -c Stack.cpp

Queue.o: Queue.cpp
	g++ -std=c++11 -c Queue.cpp

HashTable.o: HashTable.cpp
	g++ -std=c++11 -c HashTable.cpp

WordNetwork.o: WordNetwork.cpp
	g++ -std=c++11 -c WordNetwork.cpp

