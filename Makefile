# Name: Sally Chung
# Project: Lab 2: 

EXECUTABLES=lab2
SRC=lab2.c
OBJ=lab2.o

CC=gcc
CFLAGS=-g

all: $(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

launch:

tube: 

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~
