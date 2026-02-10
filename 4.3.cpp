#include <iostream>
#include <string>

class Figure {
protected:
    int sidesCount;
    std::string name;

public:
    Figure(std::string_view name, int sidesCount)
        : name(name), sidesCount(sidesCount)
    {}

    virtual bool check() {
        return sidesCount == 0;
    }

    virtual void printInfo() {
        std::cout << name << "\n";
        std::cout << "Sides count: " << sidesCount << "\n";
        std::cout << "Correct: " << (check() ? "yes" : "no") << "\n";
    }

    virtual ~Figure() = default;
};

//Triangle
class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure("Triangle", 3), a(a), b(b), c(c), A(A), B(B), C(C)
    {}

    bool check() override {
        return A + B + C == 180;
    }

    void printInfo() override {
        Figure::printInfo();
        std::cout << "Sides: " << a << " " << b << " " << c << "\n";
        std::cout << "Angles: " << A << " " << B << " " << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90)
    {
        name = "Right triangle";
    }

    bool check() override {
        return Triangle::check() && C == 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A)
    {
        name = "Isosceles triangle";
    }

    bool check() override {
        return Triangle::check() && a == c && A == C;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60, 60, 60)
    {
        name = "Equilateral triangle";
    }

    bool check() override {
        return Triangle::check() && a == b && b == c && A == 60 && B == 60 && C == 60;
    }
};

//Quadrangle
class Quadrangle : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure("Quadrangle", 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {
    }

    bool check() override {
        return A + B + C + D == 360;
    }

    void printInfo() override {
        Figure::printInfo();
        std::cout << "Sides: " << a << " " << b << " " << c << " " << d << "\n";
        std::cout << "Angles: " << A << " " << B << " " << C << " " << D << "\n\n";
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    {
        name = "Rectangle";
    }

    bool check() override {
        return Quadrangle::check() && a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90;
    }
};

class Square : public Rectangle {
public:
    Square(double a)
        : Rectangle(a, a)
    {
        name = "Square";
    }

    bool check() override {
        return Rectangle::check() && a == b;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Parallelogram";
    }

    bool check() override {
        return Quadrangle::check() && a == c && b == d && A == C && B == D;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B)
    {
        name = "Rhombus";
    }

    bool check() override {
        return Parallelogram::check() && a == b;
    }
};

void printInfo(Figure* f)
{
    f->printInfo();
    delete f;
}

int main() {
    printInfo(new Figure("Figure", 0));
    printInfo(new Triangle(3, 4, 5, 60, 60, 60));
    printInfo(new RightTriangle(3, 4, 5, 70, 60));
    printInfo(new IsoscelesTriangle(5, 6, 50, 80));
    printInfo(new EquilateralTriangle(6));
    printInfo(new Quadrangle(1, 3, 3, 4, 90, 90, 90, 90));
    printInfo(new Rectangle(4, 8));
    printInfo(new Square(7));
    printInfo(new Parallelogram(4, 6, 60, 120));
    printInfo(new Rhombus(5, 60, 120));
}
