#pragma once

#include "Shape.h"

class Circle :public Shape
{
public:
    Circle(void);
    Circle(std::string_view colour, float radius);
    ~Circle(void);

    void Show(void) const override;

    // Accessors
    float GetRadius(void) const;
    // Mutators
    bool SetRadius(float radius);
    // Overridden functions
    float Perimeter(void) const override;
    float Area(void) const override;
    float OverallDimension(void) const override;
private:
    float m_radius;
};

