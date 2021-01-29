hepsi:derle calistir
derle:
	g++ -I./include -c ./src/BinarySearchTree.cpp -o ./lib/BinarySearchTree.o
	g++ -I./include -c ./src/BSTNode.cpp -o ./lib/BSTNode.o
	g++ -I./include ./src/Odev3_Deneme1.cpp -o ./bin/Odev3_Deneme1 ./lib/BSTNode.o ./lib/BinarySearchTree.o
calistir:
	./bin/Odev3_Deneme1