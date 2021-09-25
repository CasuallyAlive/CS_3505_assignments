/*
* CS 3505 Assignment 3: An introduction to the Rule Of 3 Design Pattern, Alphabetical Trie.
* Trie.cpp Description:
*   Program that tests the Trie.cpp by taking two input files, one with words to be added to a Tries and the other with words that will be used to query with the 'isAWord' method.
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include "Trie.h"

// Reads the file at the given string path. Returns true if the file was successfully opened, false otherwise. A reference to a vector is kept as a parameter so that the caller has access to the words embedded within the file.
bool readFile(std::string, std::vector<std::string> &);
// Function that covers cases where a word is not found during the test.
void wordNotFound(Trie *, std::string);
// Function that tests the Trie with Rule of Three specifications.
void testRuleOfThree(Trie *);

std::vector<std::string> wordsForTree(0);
std::vector<std::string> wordsForQuery(0);

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "The input is not a valid, please restart the program." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 0;
    }
    std::string treeWordsFileName = argv[1];
    if (!readFile(treeWordsFileName, wordsForTree))
    {
        std::cout << "Could not find the first file that was inputted, please restart the program." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 0;
    }
    std::string queryWordsFileName = argv[2];
    if (!readFile(queryWordsFileName, wordsForQuery))
    {
        std::cout << "Could not find the second file that was inputted, please restart the program." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 0;
    }
    Trie *testTrie1 = new Trie();
    for (unsigned int i = 0; i < wordsForTree.size(); i++)
    {
        testTrie1->addAWord(wordsForTree[i]);
    }
    for (unsigned int i = 0; i < wordsForQuery.size(); i++)
    {
        if (testTrie1->isAWord(wordsForQuery[i]))
        {
            std::cout << wordsForQuery[i] << " is found!" << std::endl;
        }
        else
        {
            std::cout << wordsForQuery[i] << " is not found, did you mean:" << std::endl;
            wordNotFound(testTrie1, wordsForQuery[i]);
        }
    }

    testRuleOfThree(testTrie1);
    return 0;
}

void testRuleOfThree(Trie *testTrie)
{
    std::cout << "\nRule of three test initiating!" << std::endl;
    std::cout << "\nAddress of parameter Trie (Trie1): " << testTrie << std::endl;
    Trie *testTrie2 = new Trie(*testTrie);
    std::cout << "Address of another pointer to a Trie, Trie2, that used the copy constructor on the initial Trie: " << testTrie2 << std::endl;
    std::cout << "Trie1 == Trie2: " << (testTrie == testTrie2) << std::endl;
    std::cout << "Will now delete Trie1..." << std::endl;
    delete testTrie;

    std::vector<std::string> testTrie2Words = testTrie2->allWordsStartingWithPrefix("");
    std::cout << "\nWords in Trie2 after deleting Trie1:\n";
    for (unsigned int i = 0; i < testTrie2Words.size() - 1; i++)
    {
        std::cout << testTrie2Words[i] << ",";
    }
    std::cout << testTrie2Words[testTrie2Words.size() - 1] << "\n"
              << std::endl;
    std::cout << "Now making another Trie, Trie3, on the stack with words added to it..." << std::endl;

    Trie testTrie3;
    for (unsigned int i = 0; i < wordsForQuery.size(); i++)
    {
        testTrie3.addAWord(wordsForQuery[i]);
    }
    std::cout << "Words on Trie3:\n";
    std::vector<std::string> testTrie3Words = testTrie3.allWordsStartingWithPrefix("");

    for (unsigned int i = 0; i < testTrie3Words.size() - 1; i++)
    {
        std::cout << testTrie3Words[i] << ",";
    }
    std::cout << testTrie3Words[testTrie3Words.size() - 1] << "\n"
              << std::endl;

    std::cout << "Now setting Trie3 to Trie2..." << std::endl;
    testTrie3 = *testTrie2;
    std::cout << "Trie3's resulting dictionary:\n";

    std::vector<std::string> testTrie3Words2 = testTrie3.allWordsStartingWithPrefix("");

    for (unsigned int i = 0; i < testTrie3Words2.size() - 1; i++)
    {
        std::cout << testTrie3Words2[i] << ",";
    }
    std::cout << testTrie3Words2[testTrie3Words2.size() - 1] << "\n"
              << std::endl;
    std::cout << "Trie3's reference: " << &testTrie3 << " and Trie2's reference:" << testTrie2 << std::endl;
    std::cout << "Test has concluded! " << std::endl;
}

void wordNotFound(Trie *testTrie, std::string word)
{
    std::vector<std::string> alternatives = testTrie->allWordsStartingWithPrefix(word);
    if (alternatives.size() == 0)
    {
        std::cout << "   "
                  << "No alternatives found." << std::endl;
        return;
    }
    for (unsigned int i = 0; i < alternatives.size(); i++)
    {
        std::cout << "   " << alternatives[i] << std::endl;
    }
}

bool readFile(std::string fileName, std::vector<std::string> &words)
{
    std::string line;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            words.push_back(line);
        }
        file.close();
    }
    else
        return false;
    return true;
}