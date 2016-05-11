main:avl.o main.o
	g++ avl.o main.o -o main -g -std=c++14 -Wall
avl.o:
	g++ -c avl.cpp Bitree.cpp -g -std=c++14 -Wall
main.o:
	g++ -c main.cpp -g -std=c++14 -Wall

.PHONY:clean
clean:
	rm avl.o main.o main
