#include "Circle.h"
#include "Square.h"

int main(void)
{
    Circle* circle = nullptr;
    Square* square = nullptr;

    std::string colour = "";
    float size = 0.0f;

    std::cout << "Enter the circle's colour: ";
    std::getline(std::cin, colour);

    std::cout << "Enter the circle's radius: ";
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush user input

    circle = new Circle(colour, size);

    std::cout << "Enter the square's colour: ";
    std::getline(std::cin, colour);

    std::cout << "Enter the square's side-length: ";
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush user input

    square = new Square(colour, size);

    circle->Show();
    delete circle;

    square->Show();
    delete square;

    return 0;
}