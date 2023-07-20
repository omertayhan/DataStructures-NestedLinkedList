all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o	
	g++ -c -I "./include" ./src/FileHandler.cpp -o ./lib/FileHandler.o	
	g++ -c -I "./include" ./src/nested_linked_list.cpp -o ./lib/nested_linked_list.o	
	
bagla:
	g++ ./lib/BagliListe.o ./lib/nested_linked_list.o ./lib/Dugum.o ./lib/FileHandler.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program