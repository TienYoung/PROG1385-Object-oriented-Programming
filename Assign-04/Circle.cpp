#include "Circle.h"

#define PI 3.1415926f

Circle::Circle(void) :m_radius(0.0f)
{
}

Circle::Circle(std::string_view colour, float radius) :Shape("Circle", colour)
{
    if (SetRadius(radius) == false)
        m_radius = 0.0f;
}

Circle::~Circle(void)
{
    std::cout << "The circle is broken ...\n" << std::endl;
}

void Circle::Show(void) const
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
        "Radius", GetRadius(),
        "Circumference", Perimeter(),
        "Area", Area())
        << std::endl;
}

float Circle::GetRadius(void) const
{
    return m_radius;
}

bool Circle::SetRadius(float radius)
{
    if (radius >= 0.0f)
    {
        m_radius = radius;
        return true;
    }

    return false;
}

float Circle::Perimeter(void) const
{
    return m_radius * PI * 2.0f;
}

float Circle::Area(void) const
{
    return m_radius * PI * PI;
}

float Circle::OverallDimension(void) const
{
    return m_radius * 2;
}

