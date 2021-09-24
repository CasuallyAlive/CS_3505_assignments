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
    /*
    * Nested class that represents a node within the Trie. Each node has a potential 26 branches; furthermore, a node can be the end of a word.
    */
    class Node
    {
    public:
        const unsigned int maxBranches = 26;
        Node *branches[26];
        bool endOfWord;
        // Constructor for the Node class, a node is not the end of a word by default. The elements of the node's embedded branch array are set to nullptr by default.
        Node(bool endOfWord = false) : endOfWord{endOfWord}
        {
            setBranchesToNull();
        }
        // Deep copy overload for the '=' operator.
        Node &operator=(Node other)
        {
            for (unsigned int i = 0; i < maxBranches; i++)
            {
                std::swap(branches[i], other.branches[i]);
            }
            std::swap(branches, other.branches);
            std::swap(endOfWord, other.endOfWord);
            return *this;
        }
        // Deep copy constructor for a node.
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
        // Sets the elements of the array of pointers to null.
        void setBranchesToNull()
        {
            for (unsigned int i = 0; i < maxBranches; i++)
            {
                branches[i] = nullptr;
            }
        }
        // Deconstructor for the Node class. Only need to delete pointers in array of pointers.
        ~Node()
        {
            for (unsigned int i = 0; i < 26; i++)
            {
                delete branches[i];
            }
        }
    };
    Node *head;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    /**
     * Helper for the 'addAWord' method.
     */
    void addAWord(std::string, unsigned int &, Node *);
    /**
     * Helper for the 'isAWord' method.
     */
    bool isAWord(std::string, unsigned int &, Node *);
    /**
     * Helper for the 'allWordsStartingWithPrefix' method.
     */
    std::vector<std::string> allWordsStartingWithPrefix(std::string, unsigned int &, Node *);
    /**
     * Helper for the 'allWordsStartingWithPrefix' method. Finds and returns the node at the specified prefix.
     */
    Node *findNodeAtPrefix(std::string, unsigned int, Node *);
    /**
     * Helper for the 'allWordsStartingWithPrefix' method. Adds all the words that branch out from a node to the parameter vector.
     */
    void addWordsAtNodeToVector(std::string &, Node *, std::vector<std::string> &, std::string);
    /**
     * Returns the character that corresponds to the given index (index = 0-25).
     */
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