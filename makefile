all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/FileHandler.cpp -o ./lib/FileHandler.o	
	g++ -c -I "./include" ./src/NestedLinkedList.cpp -o ./lib/NestedLinkedList.o	
	
bagla:
	g++  ./lib/NestedLinkedList.o  ./lib/FileHandler.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program