#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <format>

#define MAX_NAME_LEN        50
#define MAX_COLOUR_LEN      10

#define ALLOWED_NAME_NUM     3
#define DEFINED_COLOUR_NUM   8

class Shape
{
public:
    Shape(void);
    Shape(std::string_view name, std::string_view colour);

    virtual void Show() const;

    // Accessors
    std::string_view GetName(void) const;
    std::string_view GetColour(void) const;

    // Mutators
    bool SetName(std::string_view name);
    bool SetColour(std::string_view colour);

    // Pure virtual functions
    virtual float Perimeter(void) const = 0;
    virtual float Area(void) const = 0;
    virtual float OverallDimension(void) const = 0;
protected:
    std::string m_name;
    std::string m_colour;
    static std::string s_allowedName[ALLOWED_NAME_NUM];
    static std::string s_definedColour[DEFINED_COLOUR_NUM];
};

