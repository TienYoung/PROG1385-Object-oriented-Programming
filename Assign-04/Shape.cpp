#include "Shape.h"

std::string Shape::s_allowedName[ALLOWED_NAME_NUM] = { "Circle", "Square", "Unknown" };
std::string Shape::s_definedColour[DEFINED_COLOUR_NUM] = { "red", "green", "blue", "yellow", "purple", "pink", "orange", "undefined" };

Shape::Shape(void) :m_name("Unknown"), m_colour("undefined")
{
}

Shape::Shape(std::string_view name, std::string_view colour)
{
    if (SetName(name) == false)
        m_name = "Unknown";
    if (SetColour(colour) == false)
        m_colour = "undefined";
}

void Shape::Show() const
{
    std::cout << std::format(
        "Shape Information\n"
        "{:<13} : {}\n"
        "{:<13} : {}\n",
        "Name", GetName(),
        "Colour", GetColour())
        << std::endl;
}

std::string_view Shape::GetName(void) const
{
    return m_name;
}

std::string_view Shape::GetColour(void) const
{
    return m_colour;
}

bool Shape::SetName(std::string_view name)
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

bool Shape::SetColour(std::string_view colour)
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
