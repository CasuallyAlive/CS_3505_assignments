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
    const unsigned int maxBranches = 26;

    Node *branches[26];
    bool endOfWord;
    void setBranchesToNull();

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
        for (unsigned int i = 0; i < maxBranches; i++)
        {
            delete branches[i];
        }
        delete branches;
    }
};

Trie::~Trie()
{
    for (unsigned int i = 0; i < head.maxBranches; i++)
    {
        delete head.branches[i];
    }
    delete head.branches;
}

Trie::Trie(const Trie &other)
{
    head = other.head;
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
    unsigned int letterPostion = getIndexOfLetter(word[currentPosition]);
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
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    unsigned int position = 0;
    std::vector<std::string> words(0);
    Node *nodeAtPrefix = findNodeAtPrefix(prefix, position, &head);
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
            addWordsAtNodeToVector(prefix, *branch, words, "" + getLetterAtIndex(i));
        }
    }
}
void Trie::addWordsAtNodeToVector(std::string &prefix, Node &branch, std::vector<std::string> &words, std::string wordFragment)
{
    if (branch.endOfWord)
    {
        words.push_back(prefix + wordFragment);
        return;
    }

    for (unsigned int i = 0; i < branch.maxBranches; i++)
    {
        Node *newBranch = branch.branches[i];
        if (newBranch)
        {
            wordFragment += getLetterAtIndex(i);
            addWordsAtNodeToVector(prefix, *newBranch, words, wordFragment);
        }
    }
}

bool Trie::isAWord(std::string word, unsigned int &currentPosition, Node &currentNode)
{
    if (currentPosition == word.length() - 1)
    {
        return currentNode.endOfWord;
    }
    currentPosition++;
    unsigned int letterPosition = getIndexOfLetter(word[currentPosition]);
    Node *nextNode = currentNode.branches[letterPosition];
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
        unsigned int letterPostion = getIndexOfLetter(word[currentPosition]);
        head.branches[letterPostion]->endOfWord = true;
        return;
    }
    currentPosition++;
    unsigned int letterPosition = getIndexOfLetter(word[currentPosition]);
    Node *nextNode = currentNode.branches[letterPosition];
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
Node *Trie::findNodeAtPrefix(std::string prefix, unsigned int position, Node *currentNode)
{
    if (prefix.length() == position)
    {
        return currentNode;
    }
    unsigned int letterPosition = getIndexOfLetter(prefix[position]);
    Node *nextNode = currentNode->branches[letterPosition];
    if (nextNode)
    {
        position++;
        findNodeAtPrefix(prefix, position, nextNode);
    }
    else
    {
        return nullptr;
    }
}
unsigned int Trie::getIndexOfLetter(char letter)
{
}
char Trie::getLetterAtIndex(unsigned int index)
{
    return 'a';
}