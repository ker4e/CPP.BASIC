#include <iostream>
#include <string>

class Figure {
protected:
    int sidesCount;
    std::string name;

public:
    Figure(int sides, const std::string& Name) : sidesCount(sides), name(Name) {}

    int getSidesCount() const {
        return sidesCount;
    }

    std::string getName() const {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Triangle") {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Quadrangle") {}
};

int main() {
    Figure figure{ 0, "Figure" };
    Triangle triangle;
    Quadrangle quad;

    std::cout << figure.getName() << ": " << figure.getSidesCount() << std::endl;
    std::cout << triangle.getName() << ": " << triangle.getSidesCount() << std::endl;
    std::cout << quad.getName() << ": " << quad.getSidesCount() << std::endl;

    return EXIT_SUCCESS;
}
