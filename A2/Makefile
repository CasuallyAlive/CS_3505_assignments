CC = g++
CFLAGS = -Wall
LIBHARU = ./libharu

spiralPDF: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L$(LIBHARU)/src -lhpdfs

Spiral.o: Spiral.cpp Spiral.h 
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h 
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c HaruPDF.cpp

spiralPDF.o: spiralPDF.cpp
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c spiralPDF.cpp 

test: spiralPDF
	./spiralPDF "No other person is responsible for your success and happiness. Do your sanity a favor and embrace yourself."

clean: 
	Irm -f *.o spiralPDF