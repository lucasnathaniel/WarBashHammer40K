PROG = WarBashHammer40K
CC = g++

CPPFLAGS = -O0 -g -Wall -pedantic -std=c++11

OBJS = main.o Card.o List.o Functions.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : ../src/main.cpp ../src/main.h
	$(CC) $(CPPFLAGS) -c ../src/main.cpp

Card.o : ../src/Card.cpp ../src/Card.h
	$(CC) $(CPPFLAGS) -c ../src/Card.cpp

List.o : ../src/List.cpp ../src/List.h
	$(CC) $(CPPFLAGS) -c ../src/List.cpp

Functions.o : ../src/Functions.cpp ../src/Functions.h
	$(CC) $(CPPFLAGS) -c ../src/Functions.cpp

clean:
	rm -f core $(PROG) $(OBJS)
