/*
* CS 3505 Assignment 2: An Introduction to the Facade Design Pattern
* Spiral.h Description:
*   The interface for the Spiral class.  
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/

#include <math.h>

class Spiral
{
    double centerX;
    double centerY;
    double currentAngle;
    double currentRadius;
    const double minimumRadius = 50;
    int simulationElapsed = 1;

public:
    /**
     * Constructor for the spriral class,  
     * centerX, centerY: coordinates for center of spiral.
     * startingAngle: the starting angle clockwise from 12 o'clock.
     * startingRadius: starting distance from center of spiral.
     **/
    Spiral(double centerX, double centerY, double startingAngle, double startingRadius);
    /**
     *  Advances the spiral to its next position. Prefix ++.
     **/
    Spiral &operator++();
    /**
     * Advances the spiral to its next position. Postfix ++.
     **/
    Spiral operator++(int);
    /**
     * Getter for the horizontal component of the current position.
     **/
    double getTextX();
    /**
     * Getter for the vertical component of the current position.
     **/
    double getTextY();
    /**
     * Getter for the angle of the current position.
     **/
    double getLetterAngle();
    /**
 * Converts degrees to radians.
 **/
    double toRadians(double);
};