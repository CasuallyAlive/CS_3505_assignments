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

const int iterations = 500;
const double scaleFactor = 0.1;

/*
* Function that is called when an invalid input is provided within the main function's prompts.
*/
void invalidInputExit()
{
    std::cout << "The input is not a valid, please restart the program." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

int main()
{
    double foxPopulation, rabbitPopulation;
    std::cout << "This is a fox and rabbit population simulator." << std::endl;
    std::cout << "Please input the initial fox population: \n";

    if (!(std::cin >> foxPopulation))
    {
        invalidInputExit();
        return 0;
    }
    std::cout << "and the initial rabbit population: \n";
    if (!(std::cin >> rabbitPopulation))
    {
        invalidInputExit();
        return 0;
    }

    runSimulation(iterations, rabbitPopulation, foxPopulation);

    std::cout << "\nThe simulation has terminated, press 'Enter' to exit." << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}

void runSimulation(int iterations, double rabbitPopulation, double foxPopulation)
{
    const double g{0.2}, p{0.0022}, c{0.6}, m{0.2}, K{1000.0};
    for (int i = 0; i <= iterations && (rabbitPopulation > 1 && foxPopulation > 1); incrementCounter(&i))
    {
        plotPopulations(rabbitPopulation, foxPopulation, scaleFactor);
        std::cout << std::endl;
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
    if (numberOfSpaces < 1)
    {
        std::cout << letter;
        return;
    }
    std::string row = "";
    for (int i = 0; i <= numberOfSpaces; i++)
    {
        // Ternary that adds spaces to a row until the position of the character is reached.
        row = (i == numberOfSpaces) ? row + letter : row + " ";
    }
    std::cout << row;
}

void plotPopulations(double rabbitPopulation, double foxPopulation, double scaleFactor)
{
    int rabbitCharPosition = std::floor(rabbitPopulation * scaleFactor), foxCharPosition = std::floor(foxPopulation * scaleFactor);
    int rabbitNum = std::floor(rabbitPopulation), foxNum = std::floor(foxPopulation);
    if (rabbitNum == foxNum)
    {
        int position = rabbitCharPosition;
        plotCharacter(position, '*');
        return;
    }
    // Ternaries that set one population as the leftmost character on the chart or the rightmost character. The rightmost character's position is determined by only adding the difference of the total spaces for correct positioning on the console.
    rabbitCharPosition = (rabbitNum < foxNum) ? rabbitCharPosition : rabbitCharPosition - foxCharPosition - 1;
    foxCharPosition = (foxNum < rabbitNum) ? foxCharPosition : foxCharPosition - rabbitCharPosition - 1;
    // The rightmost character is written to the console first.
    if (rabbitNum < foxNum)
    {
        plotCharacter(rabbitCharPosition, 'r');
        plotCharacter(foxCharPosition, 'F');
    }
    else
    {
        plotCharacter(foxCharPosition, 'F');
        plotCharacter(rabbitCharPosition, 'r');
    }
}

void incrementCounter(int *count)
{
    (*count)++;
}