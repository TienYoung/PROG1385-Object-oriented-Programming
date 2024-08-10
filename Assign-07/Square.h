/*
* FILE : Square.h
* PROJECT : PROG1385 - Assignment #7
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-08-10
* DESCRIPTION :
* This is the header file for the Square class. It declares the Square class,
* which is derived from the Shape class, and includes declarations for
* square-specific attributes and methods. The file defines the interface for
* creating and manipulating Square objects, including constructors, destructor,
* accessors, mutators, and overloaded operators for arithmetic and comparison.
*/

#pragma once

#include "Shape.h"

/// \class Square
/// \brief A class representing a square.
///
/// The Square class is derived from the Shape class and includes specific properties
/// and methods for a square, such as side length and functions to calculate perimeter,
/// area, and overall dimension.
class Square :public Shape
{
public:
    /// \brief Default constructor.
    Square(void);

    /// \brief Parameterized constructor.
    /// \param colour The colour of the square.
    /// \param sideLength The side length of the square.
    Square(const std::string& colour, float sideLength);

    /// \brief Destructor.
    ~Square(void);

    /// \brief Function to display square information.
    void Show(void) const override;

    /// \brief Accessor for the side length of the square.
    /// \return The side length of the square.
    float GetSideLength(void) const;
    
    /// \brief Non-const accessor for the side length of the square.
    /// \return The side length of the square.
    float GetSideLength(void);

    /// \brief Mutator for the side length of the square.
    /// \param sideLength The new side length of the square.
    /// \return True if the side length is valid, false otherwise.
    bool SetSideLength(float sideLength);

    /// \brief Function to calculate the perimeter of the square.
    /// \return The perimeter of the square.
    virtual float Perimeter(void) const override;

    /// \brief Function to calculate the area of the square.
    /// \return The area of the square.
    virtual float Area(void) const override;

    /// \brief Function to calculate the overall dimension of the square.
    /// \return The overall dimension of the square.
    virtual float OverallDimension(void) const override;

    /// \brief Overloaded addition operator for squares.
    /// \param other The square to add to this one.
    /// \return A new square with the sum of the side lengths and the colour of this square.
	Square operator+(const Square& other) const;

    /// \brief Overloaded multiplication operator for squares.
    /// \param other The square to multiply with this one.
    /// \return A new square with the product of the side lengths and the colour of the other square.
    Square operator*(const Square& other) const;

    /// \brief Overloaded assignment operator for squares.
    /// \param other The square to assign from.
    /// \return A reference to this square after assignment.
    Square& operator=(const Square& other);

    /// \brief Overloaded equality operator for squares.
    /// \param other The square to compare with this one.
    /// \return True if the squares have the same colour and side length, false otherwise.
	bool operator==(const Square& other) const;

private:
    float m_sideLength; ///< The side length of the square.
};
