/*
* CS 3505 Assignment 2: An Introduction to the Facade Design Pattern
* Spiral.cpp Description:
*   A class that simulates a spiral, i.e. calculates a position and orientation that if printed as a character at each step would produce a spiral shape.  
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <math.h>
#include "Spiral.h"
#include <iostream>

Spiral::Spiral(double centerX, double centerY, double startingAngle, double startingRadius) : centerX(centerX), centerY(centerY), currentAngle(startingAngle)
{
    this->currentRadius = (startingRadius > minimumRadius) ? startingRadius : minimumRadius;
}
double Spiral::getTextX()
{
    // Converts angle back to standard position, i.e. 0 degrees starts on the positive x-axis. Essential for correct position calculations.
    return currentRadius * cos(toRadians(90 - currentAngle)) + centerX;
}
double Spiral::getTextY()
{
    return currentRadius * sin(toRadians(90 - currentAngle)) + centerY;
}
double Spiral::getLetterAngle()
{
    return currentAngle;
}
Spiral &Spiral::operator++()
{
    // A model that uses the decaying sigmoid function to simulate a larger rate of decrement for the angle at the beginning of the simulation.
    double angleIncrement{10 * (1 + 1 / (1 + exp2(0.5 * simulationElapsed - 20)))};
    this->currentAngle += angleIncrement;
    // logarithmic growth for the radius of the spiral
    this->currentRadius += log10(simulationElapsed + 2);
    this->simulationElapsed++;
    return *this;
}
Spiral Spiral::operator++(int amount)
{
    Spiral result(*this);
    ++(*this);
    return result;
}

double Spiral::toRadians(double degrees)
{
    return (degrees) * ((2.0 * M_PI) / 360.0);
}