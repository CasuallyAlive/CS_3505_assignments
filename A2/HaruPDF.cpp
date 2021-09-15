/*
* CS 3505 Assignment 2: An Introduction to the Facade Design Pattern
* HaruPDF.cpp Description:
*   A class that acts as a 'clean' wrapper class for the Haru pdf library. Provides class methods that allow for the creation of pdfs with user defined orientation and position. 
*
* Author: Jordy A. Larrea Rodriguez (U1236145)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
#include "HaruPDF.h"
#include <string>

HaruPDF::HaruPDF(std::string pdfName)
{
    // Replaces:
    //strcpy(fname, argv[0]);
    //strcat(fname, ".pdf");
    this->pdfName = pdfName + ".pdf";

    pdf = HPDF_New(NULL, NULL);
}
HaruPDF::~HaruPDF()
{
    HPDF_Free(pdf);
}
void HaruPDF::addPage()
{
    /* add a new page object. */
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    //    print_grid  (pdf, page);
    HPDF_Page_SetTextLeading(page, 20);
    HPDF_Page_SetGrayStroke(page, 0);
}
void HaruPDF::setFont(std::string font, int fontSize)
{
    this->font = HPDF_GetFont(pdf, font.c_str(), NULL);
    HPDF_Page_SetFontAndSize(page, this->font, fontSize);
}
void HaruPDF::startWritingToPage()
{
    HPDF_Page_BeginText(page);
}

void HaruPDF::addTextToPage(std::string text)
{
    HPDF_Page_ShowText(page, text.c_str());
}

void HaruPDF::setTextOrientationAndPosition(double angle, double x, double y)
{
    double x_orientation1 = cos(angle), x_orientation2 = sin(angle), y_orientation1 = -sin(angle), y_orientation2 = cos(angle);
    HPDF_Page_SetTextMatrix(page,
                            x_orientation1, x_orientation2, y_orientation1, y_orientation2,
                            x, y);
}
void HaruPDF::endWritingToPage()
{
    HPDF_Page_EndText(page);
}
void HaruPDF::generatePDF()
{
    HPDF_SaveToFile(pdf, pdfName.c_str());
}