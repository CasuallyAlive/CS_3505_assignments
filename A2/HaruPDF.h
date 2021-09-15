/*
* CS 3505 Assignment 2: An Introduction to the Facade Design Pattern
* HaruPDF.h Description:
*   The interface for the HaruPDF class.  
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/
#include <stdlib.h>
#include <stdio.h>
#include "hpdf.h"
#include <string.h>
#include <string>
#include <math.h>

/**
 * HaruPDF class: wrapper class for the Haru pdf library. 
 */
class HaruPDF
{
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    std::string pdfName;

public:
    /** 
     * Constructor for the HaruPDF class. The passed parameter string contains the name of the pdf file. 
     */
    HaruPDF(std::string pdfName);
    /** 
     * Adds a page to the pdf object. 
     */
    void addPage();
    /** 
     * Sets the font to be used in the page
     */
    void setFont(std::string fontName, int fontSize);
    /** 
     * Initiates the writing process for the page, i.e. allows the user to start writing characters at specific locations on the active page.
     */
    void startWritingToPage();
    /** 
     * Places a character with the given transformation and at the given position. 
     */
    void setTextOrientationAndPosition(double angle, double x, double y);
    /** 
     * Adds the passed in string to the page.
     */
    void addTextToPage(std::string text);
    /** 
     * Ends the writing process for the page, i.e. disallows the user to from writing characters to the now in-active page. 
     */
    void endWritingToPage();
    /** 
     * Creates a pdf from HaruPDF object. 
     */
    void generatePDF();
    /**
     * Destructor for the HaruPDF object.
     */
    ~HaruPDF();
};