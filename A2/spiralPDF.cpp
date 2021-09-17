/*
* CS 3505 Assignment 2: An Introduction to the Facade Design Pattern
* spiralPDF.cpp Description:
*   Console application that writes a spiral out of text inputted to the console onto a pdf. 
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/

#include <iostream>
#include "HaruPDF.h"
#include "hpdf.h"
#include "Spiral.h"

// Draws a spiral out of the parameter string, and outputs the result to a pdf file.
void generateSpiralPDF(std::string &, HaruPDF &, Spiral &);
// Terminates the program when called, lets the user know before-hand that an empty string was entered.
int badInput();

int main(int argc, char **argv)
{
    const double centerX = 210;
    const double centerY = 300;
    const double startingAngleOfSpiral = 0;
    const double startSpiralRadius = 50;

    HaruPDF spiralPDF("spiralPDF");
    std::string inputText;
    if (argv[1] == NULL)
    {
        return badInput();
    }
    inputText = argv[1];
    if (inputText.empty())
    {
        return badInput();
    }
    Spiral spiralSimulator(centerX, centerY, startingAngleOfSpiral, startSpiralRadius);
    generateSpiralPDF(inputText, spiralPDF, spiralSimulator);
    return 0;
}
int badInput()
{
    std::cout << "No text was provided, please restart the program." << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
void generateSpiralPDF(std::string &inputText, HaruPDF &spiralPDF, Spiral &spiralSimulator)
{
    spiralPDF.addPage();
    spiralPDF.startWritingToPage();
    spiralPDF.setFont("Courier-Bold", 30);

    for (unsigned int i = 0; i < inputText.length(); i++)
    {
        spiralPDF.setTextOrientationAndPosition((-spiralSimulator.getLetterAngle()) * ((2.0 * M_PI) / 360.0), spiralSimulator.getTextX(), spiralSimulator.getTextY());

        spiralPDF.addTextToPage(inputText.substr(i, 1));

        spiralSimulator++;
    }
    spiralPDF.endWritingToPage();
    spiralPDF.generatePDF();
}
