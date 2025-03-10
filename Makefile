CC = g++
CFLAGS = -std=c++11 -O2 -Wall
SRC = 

EXEC = program

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

