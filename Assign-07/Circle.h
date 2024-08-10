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

private:
    float m_radius; ///< The radius of the circle.
};
