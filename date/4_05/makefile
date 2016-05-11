main:main.o Bitree.o 
	g++ main.o Bitree.o -o main -g -std=c++14 -Wall 
main.o:
	g++ -c main.cpp -g -std=c++14 -Wall -Wall
Bitree.o:
	g++ -c Bitree.cpp Bitree.h -g -std=c++14 -Wall 

.PHONY:clean
clean:
	-rm main main.o
