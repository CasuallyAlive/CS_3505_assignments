/*
* CS 3505 Assignment 3: An introduction to the Rule Of 3 Design Pattern, Alphabetical Trie.
* Trie.h Description:
*   The interface for the Trie class.  
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <string>
#include <vector>

class Trie
{
    Node head;
    /**
     * Helper for the 'addAWord' method.
     */
    void addAWord(std::string, unsigned int &, Node &);
    /**
     * Helper for the 'isAWord' method.
     */
    bool isAWord(std::string, unsigned int &, Node &);
    /**
     * Helper for the 'allWordsStartingWithPrefix' method.
     */
    std::vector<std::string> allWordsStartingWithPrefix(std::string, unsigned int &, Node &);
    Node *findNodeAtPrefix(std::string, unsigned int, Node *);
    void addWordsAtNodeToVector(std::string &, Node &, std::vector<std::string> &, std::string);
    char getLetterAtIndex(unsigned int index);
    /**
     * Given an english alphabetical character, returns the position as it relates to a node's internal branch storage.
     */
    unsigned int getIndexOfLetter(char letter);

public:
    Trie();
    Trie(const Trie &);
    ~Trie();
    Trie &operator=(Trie);
    /**
     * A method that accepts an std::string and returns void. The word passed into the method should be added to the Trie object. 
     * Duplicate adds should not change the Trie. You may assume that the word is only made up of lower-case characters from a-z.
     */
    void addAWord(std::string);

    /**
     * A method that accepts a std::string and returns bool. The argument is a string assumed to be made up of characters 'a'-'z'.
     * If the word is found in the Trie, the method should return true, otherwise return false.  A Trie should report that an empty string is not in the Trie.
     */
    bool isAWord(std::string);
    /**
     * A method allWordsStartingWithPrefix that accepts a std::string and returns a vector<std::string> that contains all the words in the Trie that start with the passed in argument prefix string.
     * If the prefix is a word, that should be included. An empty prefix should return all words in the Trie.
     */
    std::vector<std::string> allWordsStartingWithPrefix(std::string);
};