#pragma once

#include "Shape.h"

class Square :public Shape
{
public:
	Square(void);
	Square(std::string_view colour, float sideLength);

	void Show(void) const override;
	// Accessors
	float GetSideLength(void) const;
	// Mutators
	bool SetSideLength(float sideLength);
	// Overridden functions.
	float Perimeter(void) const override;
	float Area(void) const override;
	float OverallDimension(void) const override;
private:
	float m_sideLength;
};

