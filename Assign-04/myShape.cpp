#include "Circle.h"
#include "Square.h"

int main(void)
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle("red", 3.56f));
    shapes.push_back(new Square("blue", 10.5f));

    for (const Shape* shape : shapes)
    {
        shape->Show();
        delete shape;
    }

    shapes.clear();

    return 0;
}