/*
* FILE : myShape.cpp
* PROJECT : PROG1385 - Assignment #7
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-08-10
* DESCRIPTION :
* This file contains the main function and serves as the entry point for the program.
* It demonstrates the usage of the Circle and Square classes, creating instances of
* these shapes, manipulating them using overloaded operators, and displaying their
* properties. The file showcases the functionality implemented in the Shape hierarchy.
*/

#include "Circle.h"
#include "Square.h"

int main(void)
{
    Circle round1("red", 5.5f);
    Circle round2("blue", 10.5f);
    Circle playARound;

    Square square1("orange", 5.0f);
    Square square2("purple", 12.0f);
    Square playASquare;

    round1.Show();
    round2.Show();
    playARound.Show();

    square1.Show();
    square2.Show();
    playASquare.Show();

    playARound = round1 + round2;
    playASquare = square2 + square1;
    playARound.Show();
    playASquare.Show();

    playARound = round1 * round2;
    playASquare = square2 * square1;
    playARound.Show();
    playASquare.Show();

    playARound = round1;
    if (playARound == round1)
    {
        std::cout << "Hurray !!" << std::endl;
    }
    else
    {
        std::cout << "Awww !!" << std::endl;
    }

    return 0;
}