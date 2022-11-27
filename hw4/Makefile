# Efficiently compile your code with Makefile
CC=g++
CFLAGS=-c -Wall

target: first

first: main.o graph.o
	$(CC) main.o graph.o -o hw4

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

graph.o: graph.cpp
	$(CC) $