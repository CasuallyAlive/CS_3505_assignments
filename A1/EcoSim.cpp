/*
* CS 3505 Assignment 1: An Ecological Simulation
* Description:
*   A console app that generates plots of rabbit and fox population curves.
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <iostream>

/*
* This function should set the parameters needed for the update equation as given above,
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

int main()
{

    return 0;
}
