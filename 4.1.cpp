#include <iostream>

class Figure {
protected:
    int sidesCount;

public:
    Figure(int sides) : sidesCount(sides) {}

    int getSidesCount() const {
        return sidesCount;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {}
};

class  Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {}
};

int main() {
    Figure figure{ 0 };
    Triangle triangle;
    Quadrangle quad;

    std::cout << "Figure: " << figure.getSidesCount() << std::endl;
    std::cout << "Triangle: " << triangle.getSidesCount() << std::endl;
    std::cout << "Quadrangle: " << quad.getSidesCount() << std::endl;

    return 0;
}
