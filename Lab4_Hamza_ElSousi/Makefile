CC = gcc
CFLAGS = -g -ansi -pedantic -Wall

# List of source files and object files
SRCS = main.c temp.c wind_speed.c wind_gusts.c
OBJS = main.o temp.o wind_speed.o wind_gusts.o

# The name of the executable
EXE = weather_data_processor

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

main.o: main.c temp.h wind_speed.h wind_gusts.h
	$(CC) $(CFLAGS) -c main.c

temp.o: temp.c temp.h
	$(CC) $(CFLAGS) -c temp.c

wind_speed.o: wind_speed.c wind_speed.h
	$(CC) $(CFLAGS) -c wind_speed.c

wind_gusts.o: wind_gusts.c wind_gusts.h
	$(CC) $(CFLAGS) -c wind_gusts.c

clean:
	rm -f $(OBJS)