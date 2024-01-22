# /*******************************************************************************************************************
# Name: Hamza El Sousi
# Student ID: 040-982-818
# Course: CST8234 C Language
# Lab section: 302
# Lab Professor: Natalie Gluzman
# Due date: nOV. 12, 2023
# Submmision date: TBD
# Professor: Surbhi Bahri, Harleen Kaur
# Purpose : Simplifies compilation by automating a part of complilation process, and only compiling changed files.
#******************************************************************************************************************/

GCC_OPTIONS=-g -ansi -pedantic -std=c99 -Wall -w
CC=gcc

all: registration_system

registration_system: main.o students.o courses.o registration.o
	$(CC) $(GCC_OPTIONS) -o registration_system main.o students.o courses.o registration.o

main.o: main.c
	$(CC) $(GCC_OPTIONS) -c main.c

students.o: students.c students.h
	$(CC) $(GCC_OPTIONS) -c students.c

courses.o: courses.c courses.h
	$(CC) $(GCC_OPTIONS) -c courses.c

registration.o: registration.c registration.h
	$(CC) $(GCC_OPTIONS) -c registration.c

clean:
	rm *.o registration_system
