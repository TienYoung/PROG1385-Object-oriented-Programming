#include "Square.h"

Square::Square(void) :Shape("Square", "undefined"), m_sideLength(0.0f)
{
}

Square::Square(const std::string& colour, float sideLength) :Shape("Square", colour), m_sideLength(0.0f)
{
    if (sideLength >= 0.0f)
    {
        m_sideLength = sideLength;
    }
}

Square::~Square(void)
{
    std::cout << "The square is broken ...\n" << std::endl;
}

void Square::Show(void) const
{
    std::cout << "Shape Information" << std::endl;
    std::cout << std::left << std::setw(13) << "Name" << ": " << GetName() << std::endl;
    std::cout << std::left << std::setw(13) << "Colour" << ": " << GetColour() << std::endl;
    std::cout << std::left << std::setw(13) << "Side-Length" << ": " << std::fixed << std::setprecision(2) << GetSideLength() << " cm" << std::endl;
    std::cout << std::left << std::setw(13) << "Circumference" << ": " << std::fixed << std::setprecision(2) << Perimeter() << " cm" << std::endl;
    std::cout << std::left << std::setw(13) << "Area" << ": " << std::fixed << std::setprecision(2) << Area() << " square cm" << std::endl;
    std::cout << std::endl;
}

float Square::GetSideLength(void) const
{
    return m_sideLength;
}

float Square::GetSideLength(void)
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

Square Square::operator+(const Square& other) const
{
    return { this->GetColour(), this->GetSideLength() + other.GetSideLength() };
}

Square Square::operator*(const Square& other) const
{
    return { other.GetColour(), this->GetSideLength() * other.GetSideLength() };
}

bool Square::operator==(const Square& other) const
{
	if (this->GetColour() != other.GetColour())
		return false;

	if (abs(this->GetSideLength() - other.GetSideLength()) >= std::numeric_limits<float>::epsilon())
		return false;

	return true;
}

Square& Square::operator=(const Square& other)
{
    this->SetName(other.GetName());
    this->SetColour(other.GetColour());
    this->SetSideLength(other.GetSideLength());
    return *this;
}
