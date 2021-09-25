CC = g++
CFLAGS = -Wall

TrieTest: TrieTest.o Trie.o 
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp

clean: 
	Irm -f *.o TrieTest
