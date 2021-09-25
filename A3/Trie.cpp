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

Trie::~Trie()
{
    delete head;
}

Trie::Trie(const Trie &other)
{
    head = nullptr;
    head = new Node(*(other.head));
}
Trie::Trie()
{
}
Trie &Trie::operator=(Trie other)
{
    std::swap(head, other.head);
    return *this;
}
void Trie::addAWord(std::string word)
{
    unsigned int currentPosition = 0;
    unsigned int letterPosition = getIndexOfLetter(word[currentPosition]);
    Node *other = head->branches[letterPosition];
    if (other)
    {
        addAWord(word, currentPosition, other);
    }
    else
    {
        head->branches[letterPosition] = new Node();
        addAWord(word, currentPosition, head->branches[letterPosition]);
    }
    other = nullptr;
}
bool Trie::isAWord(std::string word)
{
    if (word.length() == 0)
    {
        return false;
    }
    unsigned int currentPosition = 0;
    unsigned int letterPostion = getIndexOfLetter(word[currentPosition]);
    Node *other = head->branches[letterPostion];
    if (other)
    {
        return isAWord(word, currentPosition, other);
    }
    else
    {
        return false;
    }
    other = nullptr;
}
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    unsigned int position{0};

    std::vector<std::string> words(0);
    Node *nodeAtPrefix = findNodeAtPrefix(prefix, position, head);
    if (!nodeAtPrefix)
    {
        return words;
    }
    if (nodeAtPrefix->endOfWord)
    {
        words.push_back(prefix);
    }
    for (unsigned int i = 0; i < nodeAtPrefix->maxBranches; i++)
    {
        Node *branch = nodeAtPrefix->branches[i];
        if (branch)
        {
            std::string wordFragment{""};
            wordFragment += getLetterAtIndex(i);
            std::string wordFragmentAtNewNode{wordFragment};
            addWordsAtNodeToVector(prefix, branch, words, wordFragment, wordFragmentAtNewNode);
        }
        branch = nullptr;
    }
    return words;
}
void Trie::addWordsAtNodeToVector(std::string &prefix, Node *branch, std::vector<std::string> &words, std::string wordFragment, std::string &initialWordFragment)
{
    if (branch->endOfWord)
    {
        words.push_back(prefix + wordFragment);
    }

    for (unsigned int i = 0; i < branch->maxBranches; i++)
    {
        Node *newBranch = branch->branches[i];
        if (newBranch)
        {
            wordFragment += getLetterAtIndex(i);
            std::string wordFragmentAtNewNode{wordFragment};
            addWordsAtNodeToVector(prefix, newBranch, words, wordFragment, wordFragmentAtNewNode);
            wordFragment = initialWordFragment; // Revert back to previous word Fragment after finding a term down a path
        }
        newBranch = nullptr;
    }
}

bool Trie::isAWord(std::string word, unsigned int &currentPosition, Node *currentNode)
{
    if (currentPosition == word.length() - 1)
    {
        return currentNode->endOfWord;
    }
    currentPosition++;
    unsigned int letterPosition = getIndexOfLetter(word[currentPosition]);
    Node *nextNode = currentNode->branches[letterPosition];
    if (nextNode)
    {
        return isAWord(word, currentPosition, nextNode);
    }
    else
    {
        return false;
    }
    nextNode = nullptr;
}

void Trie::addAWord(std::string word, unsigned int &currentPosition, Node *currentNode)
{
    if (currentPosition == word.length() - 1)
    {
        currentNode->endOfWord = true;
        return;
    }
    currentPosition++;
    unsigned int letterPosition = getIndexOfLetter(word[currentPosition]);
    Node *nextNode = currentNode->branches[letterPosition];
    if (nextNode)
    {
        addAWord(word, currentPosition, nextNode);
    }
    else
    {
        currentNode->branches[letterPosition] = new Node();
        addAWord(word, currentPosition, currentNode->branches[letterPosition]);
    }
    nextNode = nullptr;
}
Trie::Node *Trie::findNodeAtPrefix(std::string prefix, unsigned int position, Node *currentNode)
{
    if (prefix.length() == position)
    {
        return currentNode;
    }
    unsigned int nodeLetterIndex = getIndexOfLetter(prefix[position]);
    Node *nextNode = currentNode->branches[nodeLetterIndex];
    if (nextNode)
    {
        position++;
        return findNodeAtPrefix(prefix, position, nextNode);
    }
    else
    {
        return nullptr;
    }
    nextNode = nullptr;
}
unsigned int Trie::getIndexOfLetter(char letter)
{
    return letter - 'a';
}
char Trie::getLetterAtIndex(unsigned int index)
{
    return alphabet[index];
}