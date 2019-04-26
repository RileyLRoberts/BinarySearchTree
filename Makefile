Tree: main.o tree.o treeNode.o
	g++ main.o tree.o treeNode.o -o Tree

main.o: tree.h treeNode.h treeNode.cpp tree.cpp
	g++ -c main.cpp

tree.o: tree.h treeNode.h treeNode.cpp
	g++ -c tree.cpp

treeNode.o: treeNode.h treeNode.cpp
	g++ -c treeNode.cpp
