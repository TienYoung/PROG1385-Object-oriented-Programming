#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <format>

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
    Shape(std::string_view name, std::string_view colour);

    /// \brief Virtual function to display shape information.
    virtual void Show() const;

    /// \brief Accessor for the name of the shape.
    /// \return The name of the shape.
    std::string_view GetName(void) const;

    /// \brief Accessor for the colour of the shape.
    /// \return The colour of the shape.
    std::string_view GetColour(void) const;

    /// \brief Mutator for the name of the shape.
    /// \param name The new name of the shape.
    /// \return True if the name is valid, false otherwise.
    bool SetName(std::string_view name);

    /// \brief Mutator for the colour of the shape.
    /// \param colour The new colour of the shape.
    /// \return True if the colour is valid, false otherwise.
    bool SetColour(std::string_view colour);

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