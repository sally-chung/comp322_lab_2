# Name: Sally Chung
# Project: Lab 2: 

EXECUTABLES=time-4-baby-and-me
SRC=time-4-baby-and-me.c
OBJ=time-4-baby-and-me.o

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
