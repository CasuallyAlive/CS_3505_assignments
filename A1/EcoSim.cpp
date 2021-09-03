/*
* CS 3505 Assignment 1: An Ecological Simulation
* Description:
*   A console app that generates plots of rabbit and fox population curves.
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <iostream>
#include <string>
#include <cmath>

/*
* This function should set the parameters needed for the update equation,
* and run the simulation for iterations steps or until the predator or prey population goes below 1.
*/
void runSimulation(int, double, double);
/*
* Updates fox and rabbit populations using the Lotka-Volterra model.
*/
void updatePopulations(double g, double p, double c, double m, double K,
                       double &numRabbits, double &numFoxes);
/*
* Function that takes in an int number and a character and sends to std::cout number spaces followed by the character.
*/
void plotCharacter(int, char);
/*
* Draws a row of fox and rabbit populations.
*/
void plotPopulations(double, double, double);
/*
* Function that adds 1 to the value pointed to by the pointer.
*/
void incrementCounter(int *);

/*
* Prints the row of the chart.
*/
void printRow();

const int iterations = 500;
const double scaleFactor = 0.1;
std::string row = "";

int main()
{
    double foxPopulation, rabbitPopulation;
    std::cout << "This is a fox and rabbit population simulator." << std::endl;
    std::cout << "Please input the initial fox population: ";

    if (!(std::cin >> foxPopulation))
    {
        std::cout << "The input is not a valid, please restart the program." << std::endl;
        return -1;
    }
    std::cout << "and the initial rabbit population: ";
    if (!(std::cin >> rabbitPopulation))
    {
        std::cout << "The input is not a valid, please restart the program." << std::endl;
        return -1;
    }

    runSimulation(iterations, rabbitPopulation, foxPopulation);
    std::cout << "The simulation has terminated, press 'Enter' to exit." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void runSimulation(int iterations, double rabbitPopulation, double foxPopulation)
{
    double g{0.2}, p{0.0022}, c{0.6}, m{0.2}, K{1000.0};
    for (int i = 0; i < iterations && (rabbitPopulation > 1 && foxPopulation > 1); incrementCounter(&i))
    {
        plotPopulations(rabbitPopulation, foxPopulation, scaleFactor);
        updatePopulations(g, p, c, m, K, rabbitPopulation, foxPopulation);
    }
}

void updatePopulations(double g, double p, double c, double m, double K, double &numRabbits, double &numFoxes)
{
    double deltaRabbitPopulation = g * numRabbits * (1 - (numRabbits / K)) - p * numRabbits * numFoxes;
    double deltaFoxPopulation = c * p * numRabbits * numFoxes - m * numFoxes;

    numRabbits += deltaRabbitPopulation;
    numFoxes += deltaFoxPopulation;
}

void plotCharacter(int numberOfSpaces, char letter)
{
    for (int i = 0; i <= numberOfSpaces; i++)
    {
        row = (i == numberOfSpaces) ? row + letter : row + " ";
    }
}

void plotPopulations(double rabbitPopulation, double foxPopulation, double scaleFactor)
{
    int rabbitCharPosition, foxCharPosition;
    if (std::floor(rabbitPopulation) == std::floor(foxPopulation))
    {
        int position = std::floor(scaleFactor * rabbitPopulation);
        plotCharacter(position, '*');
        printRow();
        return;
    }
    if (rabbitPopulation < foxPopulation)
    {
        rabbitCharPosition = std::floor(scaleFactor * rabbitPopulation);
        // plots the char for rabbits at it's corresponding location.
        plotCharacter(rabbitCharPosition, 'r');
        foxCharPosition = std::floor(scaleFactor * foxPopulation) - rabbitCharPosition;
        // plots the char for foxes at it's corresponding location.
        plotCharacter(foxCharPosition, 'F');
        printRow();
        return;
    }

    foxCharPosition = std::floor(scaleFactor * foxPopulation);
    // plots the char for rabbits at it's corresponding location.
    plotCharacter(foxCharPosition, 'F');
    rabbitCharPosition = std::floor(scaleFactor * rabbitPopulation) - foxCharPosition;
    // plots the char for foxes at it's corresponding location.
    plotCharacter(rabbitCharPosition, 'r');
    printRow();
}

void printRow()
{
    std::cout << row << std::endl;
    row = "";
}

void incrementCounter(int *count)
{
    (*count)++;
}