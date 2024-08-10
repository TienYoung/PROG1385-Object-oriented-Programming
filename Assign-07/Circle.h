/*
* FILE : Circle.h
* PROJECT : PROG1385 - Assignment #7
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-08-10
* DESCRIPTION :
* This is the header file for the Circle class. It declares the Circle class,
* which is derived from the Shape class, and includes declarations for
* circle-specific attributes and methods. The file defines the interface for
* creating and manipulating Circle objects, including constructors, destructor,
* accessors, mutators, and overloaded operators for arithmetic and comparison.
*/

#pragma once

#include "Shape.h"

/// \class Circle
/// \brief A class representing a circle.
///
/// The Circle class is derived from the Shape class and includes specific properties
/// and methods for a circle, such as radius and functions to calculate perimeter,
/// area, and overall dimension.
class Circle :public Shape
{
public:
    /// \brief Default constructor.
    Circle(void);

    /// \brief Parameterized constructor.
    /// \param colour The colour of the circle.
    /// \param radius The radius of the circle.
    Circle(const std::string& colour, float radius);

    /// \brief Destructor.
    ~Circle(void);

    /// \brief Function to display circle information.
    void Show(void) const override;

    /// \brief Accessor for the radius of the circle.
    /// \return The radius of the circle.
    float GetRadius(void) const;

    /// \brief Non-const accessor for the radius of the circle.
    /// \return The radius of the circle.
    float GetRadius(void);

    /// \brief Mutator for the radius of the circle.
    /// \param radius The new radius of the circle.
    /// \return True if the radius is valid, false otherwise.
    bool SetRadius(float radius);

    /// \brief Function to calculate the perimeter of the circle.
    /// \return The perimeter of the circle.
    virtual float Perimeter(void) const override;

    /// \brief Function to calculate the area of the circle.
    /// \return The area of the circle.
    virtual float Area(void) const override;

    /// \brief Function to calculate the overall dimension of the circle.
    /// \return The overall dimension of the circle.
    virtual float OverallDimension(void) const override;

    /// \brief Overloaded addition operator for circles.
    /// \param other The circle to add to this one.
    /// \return A new circle with the sum of the radii and the colour of this circle.
    Circle operator+(const Circle& other) const;

    /// \brief Overloaded multiplication operator for circles.
    /// \param other The circle to multiply with this one.
    /// \return A new circle with the product of the radii and the colour of the other circle.
    Circle operator*(const Circle& other) const;

    /// \brief Overloaded assignment operator for circles.
    /// \param other The circle to assign from.
    /// \return A reference to this circle after assignment.
    Circle& operator=(const Circle& other);

    /// \brief Overloaded equality operator for circles.
    /// \param other The circle to compare with this one.
    /// \return True if the circles have the same colour and radius, false otherwise.
    bool operator==(const Circle& other) const;

private:
    float m_radius; ///< The radius of the circle.
};
