PROG = WarBashHammer40K
CC = g++
CPPFLAGS = -O0 -g -Wall -pedantic -std=c++11
LIB = ../lib
SRC = ../src
OBJS = main.o Card.o List.o Functions.o

linux: Jokenpo.a WarBashHammer40K

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LIB)/Jokenpo.a -o $@

main.o : $(SRC)/main.cpp $(SRC)/main.h
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp

Card.o : $(SRC)/Card.cpp $(SRC)/Card.h
	$(CC) $(CPPFLAGS) -c $(SRC)/Card.cpp

List.o : $(SRC)/List.cpp $(SRC)/List.h
	$(CC) $(CPPFLAGS) -c $(SRC)/List.cpp

Functions.o : $(SRC)/Functions.cpp $(SRC)/Functions.h
	$(CC) $(CPPFLAGS) -c $(SRC)/Functions.cpp

Jokenpo.a: $(SRC)/Jokenpo.cpp $(SRC)/Jokenpo.h
	$(CC) $(CFLAGS) -c $(SRC)/Jokenpo.cpp -o Jokenpo.o
	$(AR) rcs $(LIB)/$@ Jokenpo.o

clean:
	rm -f core $(PROG) $(OBJS) Jokenpo.o $(LIB)/Jokenpo.a