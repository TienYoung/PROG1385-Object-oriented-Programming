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

	Square operator+(const Square& other) const;
    Square operator*(const Square& other) const;
    Square& operator=(const Square& other);
	bool operator==(const Square& other) const;

private:
    float m_sideLength; ///< The side length of the square.
};
