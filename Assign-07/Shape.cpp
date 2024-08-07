#include "Shape.h"

std::string Shape::s_allowedName[ALLOWED_NAME_NUM] = { "Circle", "Square", "Unknown" };
std::string Shape::s_definedColour[DEFINED_COLOUR_NUM] = { "red", "green", "blue", "yellow", "purple", "pink", "orange", "undefined" };

Shape::Shape(void) :m_name("Unknown"), m_colour("undefined")
{
}

Shape::Shape(const std::string& name, const std::string& colour)
{
    if (SetName(name) == false)
        m_name = "Unknown";
    if (SetColour(colour) == false)
        m_colour = "undefined";
}

void Shape::Show() const
{
    std::cout << "Shape Information" << std::endl;
    std::cout << std::left << std::setw(13) << "Name" << ": " << GetName() << std::endl;
    std::cout << std::left << std::setw(13) << "Colour" << ": " << GetColour() << std::endl;
}

std::string Shape::GetName(void) const
{
    return m_name;
}

std::string Shape::GetColour(void) const
{
    return m_colour;
}

bool Shape::SetName(const std::string& name)
{
    if (name.size() > MAX_NAME_LEN)
        return false;

    for (size_t i = 0; i < ALLOWED_NAME_NUM; i++)
    {
        if (name == s_allowedName[i])
        {
            m_name = name;
            return true;
        }
    }

    return false;
}

bool Shape::SetColour(const std::string& colour)
{
    if (colour.size() > MAX_COLOUR_LEN)
        return false;

    for (size_t i = 0; i < DEFINED_COLOUR_NUM; i++)
    {
        if (colour == s_definedColour[i])
        {
            m_colour = colour;
            return true;
        }
    }

    return false;
}
