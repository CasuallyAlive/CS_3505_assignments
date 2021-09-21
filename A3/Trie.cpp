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
    const unsigned int maxBranches = 26;

public:
    Node *branches[26];
    bool endOfWord;
    void setBranchesToNull();
    /**
     * Given an english alphabetical character, returns the position as it relates to a node's internal branch storage.
     */
    unsigned int getLetterIndex(char letter);
    Node(bool endoOfWord = false)
    {
        setBranchesToNull();
    }
    Node &operator=(Node other)
    {
        std::swap(branches, other.branches);
        std::swap(endOfWord, other.endOfWord);
        return *this;
    }
    Node(const Node &other)
    {
        *branches = nullptr;
        if (other.branches)
        {
            *branches = new Node[26];
            for (unsigned int i = 0; i < maxBranches; i++)
            {
                branches[i] = new Node(other.branches[i]);
            }
        }
    }
    void setBranchesToNull()
    {
        for (unsigned int i = 0; i < maxBranches; i++)
        {
            branches[i] = nullptr;
        }
    }
    ~Node()
    {
    }
};

Trie::Trie() : head()
{
}
Trie::Trie(const Trie &other)
{
    head = other.head;
}
Trie &Trie::operator=(Trie other)
{
    std::swap(head, other.head);
    return *this;
}
void Trie::addAWord(std::string word)
{
    unsigned int currentPosition = 0;
    unsigned int letterPosition = head.getLetterIndex(word[currentPosition]);
    Node *other = head.branches[letterPosition];
    if (other)
    {
        addAWord(word, currentPosition, *other);
    }
    else
    {
        head.branches[letterPosition] = new Node();
        addAWord(word, currentPosition, *head.branches[letterPosition]);
    }
}
bool Trie::isAWord(std::string word)
{
    unsigned int currentPosition = 0;
    unsigned int letterPostion = head.getLetterIndex(word[currentPosition]);
    Node *other = head.branches[letterPostion];
    if (other)
    {
        isAWord(word, currentPosition, *other);
    }
    else
    {
        return false;
    }
}
std::vector<std::string> allWordsStartingWithPrefix(std::string word)
{
}
bool Trie::isAWord(std::string word, unsigned int &currentPosition, Node &currentNode)
{
    if (currentPosition == word.length() - 1)
    {
        return currentNode.endOfWord;
    }
    currentPosition++;
    unsigned int letterPosition = head.getLetterIndex(word[currentPosition]);
    Node *nextNode = head.branches[letterPosition];
    if (nextNode)
    {
        return isAWord(word, currentPosition, *nextNode);
    }
    else
    {
        return false;
    }
}

void Trie::addAWord(std::string word, unsigned int &currentPosition, Node &currentNode)
{
    if (currentPosition == word.length() - 1)
    {
        unsigned int letterPostion = head.getLetterIndex(word[currentPosition]);
        head.branches[letterPostion]->endOfWord = true;
        return;
    }
    currentPosition++;
    unsigned int letterPosition = head.getLetterIndex(word[currentPosition]);
    Node *nextNode = head.branches[letterPosition];
    if (nextNode)
    {
        addAWord(word, currentPosition, *nextNode);
    }
    else
    {
        head.branches[letterPosition] = new Node();
        nextNode = head.branches[letterPosition];
        addAWord(word, currentPosition, *nextNode);
    }
}