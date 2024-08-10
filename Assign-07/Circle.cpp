/*
* FILE : Circle.cpp
* PROJECT : PROG1385 - Assignment #7
* PROGRAMMER : Tian Yang
* FIRST VERSION : 2024-08-10
* DESCRIPTION :
* This file contains the implementation of the Circle class, which is derived
* from the Shape class. It provides functionality specific to circles, including
* methods for calculating perimeter, area, and overall dimension based on the
* circle's radius. The file also implements operator overloading for
* arithmetic and comparison operations on Circle objects.
*/

#include "Circle.h"

#define PI 3.1415926f

Circle::Circle(void) :Shape("Circle", "undefined"), m_radius(0.0f)
{
}

Circle::Circle(const std::string& colour, float radius) :Shape("Circle", colour), m_radius(0.0f)
{
    if (radius >= 0.0f)
    {
        m_radius = radius;
    }
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
    std::cout << std::endl;
}

float Circle::GetRadius(void) const
{
    return m_radius;
}

float Circle::GetRadius(void)
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

Circle Circle::operator+(const Circle& other) const
{
    return { this->GetColour(), this->GetRadius() + other.GetRadius() };
}

Circle Circle::operator*(const Circle& other) const
{
    return { other.GetColour(), this->GetRadius() * other.GetRadius() };
}

bool Circle::operator==(const Circle& other) const
{
    if (this->GetColour() != other.GetColour())
        return false;

    if (abs(this->GetRadius() - other.GetRadius()) >= std::numeric_limits<float>::epsilon())
        return false;

    return true;
}

Circle& Circle::operator=(const Circle& other)
{
    this->SetName(other.GetName());
    this->SetColour(other.GetColour());
    this->SetRadius(other.GetRadius());
    return *this;
}