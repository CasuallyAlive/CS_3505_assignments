/*
* CS 3505 Assignment 3: An introduction to the Rule Of 3 Design Pattern, Alphabetical Trie.
* Trie.cpp Description:
*   An alphabetical Trie that allows for efficient storage and deployment of words formatted with modern english alphabetical characters.  
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <vector>
#include <string>
#include "Trie.h"

class Node
{
public:
    Node *branches[26];
    bool endOfWord;
    Node()
    {
    }
    ~Node()
    {
    }
};

Trie::Trie()
{
    head = Node();
}