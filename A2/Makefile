CC = g++
CFLAGS = -Wall
LIBHARU = ../libharu/src
INCLUDE = ../libharu/include

spiralPDF: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L$(LIBHARU) -lhpdfs

Spiral.o: Spiral.cpp Spiral.h 
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h 
	$(CC) $(CFLAGS) -I$(INCLUDE) -c HaruPDF.cpp

spiralPDF.o: spiralPDF.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c spiralPDF.cpp 

clean: 
	Irm -f *.o spiralPDF