CC = g++
CFLAGS = -std=c++11 -O2 -Wall
SRC = main.cpp atom.cpp atomchain.cpp montecarlo.cpp

EXEC = program

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

