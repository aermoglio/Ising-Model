CC = g++
CFLAGS = -std=c++11 -O2 -Wall
SRC = main.cpp atom.cpp atomgrid.cpp

EXEC = program

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

