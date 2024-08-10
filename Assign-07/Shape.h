#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#define MAX_NAME_LEN        50
#define MAX_COLOUR_LEN      10

#define ALLOWED_NAME_NUM     3
#define DEFINED_COLOUR_NUM   8

/// \class Shape
/// \brief Abstract base class representing a generic shape.
///
/// The Shape class is an abstract base class that defines common properties
/// and methods for all shapes. It includes member variables for name and colour,
/// and pure virtual functions for calculating perimeter, area, and overall dimension.
class Shape
{
public:
    /// \brief Default constructor.
    Shape(void);

    /// \brief Parameterized constructor.
    /// \param name The name of the shape.
    /// \param colour The colour of the shape.
    Shape(const std::string& name, const std::string& colour);

    /// \brief Virtual function to display shape information.
    virtual void Show(void) const;

    /// \brief Accessor for the name of the shape.
    /// \return The name of the shape.
    std::string GetName(void) const;

    /// \brief Accessor for the colour of the shape.
    /// \return The colour of the shape.
    std::string GetColour(void) const;

    std::string GetColour(void);

    /// \brief Mutator for the name of the shape.
    /// \param name The new name of the shape.
    /// \return True if the name is valid, false otherwise.
    bool SetName(const std::string& name);

    /// \brief Mutator for the colour of the shape.
    /// \param colour The new colour of the shape.
    /// \return True if the colour is valid, false otherwise.
    bool SetColour(const std::string& colour);

    /// \brief Pure virtual function to calculate the perimeter of the shape.
    /// \return The perimeter of the shape.
    virtual float Perimeter(void) const = 0;

    /// \brief Pure virtual function to calculate the area of the shape.
    /// \return The area of the shape.
    virtual float Area(void) const = 0;

    /// \brief Pure virtual function to calculate the overall dimension of the shape.
    /// \return The overall dimension of the shape.
    virtual float OverallDimension(void) const = 0;

protected:
    std::string m_name; ///< The name of the shape.
    std::string m_colour; ///< The colour of the shape.
    static std::string s_allowedName[ALLOWED_NAME_NUM]; ///< Allowed names for shapes.
    static std::string s_definedColour[DEFINED_COLOUR_NUM]; ///< Defined colours for shapes.
};