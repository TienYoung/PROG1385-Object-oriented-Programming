#include "Circle.h"

#define PI 3.1415926f

Circle::Circle(void) :m_radius(0.0f)
{
}

Circle::Circle(const std::string& colour, float radius) :Shape("Circle", colour)
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
    std::cout << "Shape Information" << std::endl;
    std::cout << std::left << std::setw(13) << "Name" << ": " << GetName() << std::endl;
    std::cout << std::left << std::setw(13) << "Colour" << ": " << GetColour() << std::endl;
    std::cout << std::left << std::setw(13) << "Radius" << ": " << std::fixed << std::setprecision(2) << GetRadius() << " cm" << std::endl;
    std::cout << std::left << std::setw(13) << "Circumference" << ": " << std::fixed << std::setprecision(2) << Perimeter() << " cm" << std::endl;
    std::cout << std::left << std::setw(13) << "Area" << ": " << std::fixed << std::setprecision(2) << Area() << " square cm" << std::endl;
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

