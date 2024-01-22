# Student Name: Hamza El Sousi
# Student Number: 040 982 818
# Course: 23F_CST8234 C Language
# Declaration: This is my own original work except where sources have been cited.

CC = gcc
CFLAGS = -g -ansi -pedantic -Wall -w

SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all: assign2

assign2: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c student.h
	$(CC) $(CFLAGS) -c $<

student.o: student.c student.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f assign2 $(OBJS)
