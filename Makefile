# Makefile for racing simulation program

CC = g++
CFLAGS = -Wall -g
LDFLAGS =

all: race

race: main_race.o Car.o
	$(CC) $(CFLAGS) -o race main_race.o Car.o $(LDFLAGS)

main_race.o: main_race.cpp
	$(CC) $(CFLAGS) -c main_race.cpp

Car.o: Car.cpp
	$(CC) $(CFLAGS) -c Car.cpp

clean:
	rm -f race main_race.o Car.o

