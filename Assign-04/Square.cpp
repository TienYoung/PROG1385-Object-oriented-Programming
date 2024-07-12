#include "Square.h"

Square::Square(void) :m_sideLength(0.0f)
{
}

Square::Square(std::string_view colour, float sideLength) :Shape("Square", colour)
{
    if (SetSideLength(sideLength) == false)
        m_sideLength = 0.0f;
}

void Square::Show(void) const
{
    std::cout << std::format(
    "Shape Information\n"
        "{:<13} : {}\n"
        "{:<13} : {}\n"
        "{:<13} : {:.2f} cm\n"
        "{:<13} : {:.2f} cm\n"
        "{:<13} : {:.2f} square cm\n",
        "Name", GetName(),
        "Colour", GetColour(),
        "Side-Length", GetSideLength(),
        "Circumference", Perimeter(),
        "Area", Area())
        << std::endl;
}

float Square::GetSideLength(void) const
{
    return m_sideLength;
}

bool Square::SetSideLength(float sideLength)
{
    if (sideLength >= 0.0f)
    {
        m_sideLength = sideLength;
        return true;
    }

    return false;
}

float Square::Perimeter(void) const
{
    return m_sideLength * 4.0f;
}

float Square::Area(void) const
{
    return m_sideLength * m_sideLength;
}

float Square::OverallDimension(void) const
{
    return m_sideLength;
}
