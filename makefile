all: build run

build:
	g++ -I ./include/ -o ./bin/LinkedList ./src/LinkedList.cpp
	
run:
	./bin/LinkedList