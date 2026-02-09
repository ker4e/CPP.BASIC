#include <iostream>

class Figure {
public:
	virtual void printInfo() = 0;
	virtual ~Figure() = default;
};

class Triangle : public Figure {
protected:
	double a, b, c;
	double A, B, C;
public:
	Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C)
	{}

	void printInfo() override {
		std::cout << "Triangle\n";
		std::cout << "Sides: " << a << " " << b << " " << c << "\n";
		std::cout << "Angles: " << A << " " << B << " " << C << "\n\n";
	}
};

class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90) 
	{}

		void printInfo() override {
			std::cout << "Right triangle\n";
			std::cout << "Sides: " << a << " " << b << " " << c << "\n";
			std::cout << "Angles: " << A << " " << B << " 90\n\n";
		}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) 
	{}

	void printInfo() override {
		std::cout << "Isosceles triangle\n";
		std::cout << "Sides: " << a << " " << b << " " << a << "\n";
		std::cout << "Angles: " << A << " " << B << " " << A << "\n\n";
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {}

	void printInfo() override {
		std::cout << "Equilateral triangle\n";
		std::cout << "Sides: " << a << " " << a << " " << a << "\n";
		std::cout << "Angles: 60 60 60\n\n";
	}
};

class Quadrangle : public Figure {
protected:
	double a, b, c, d;
	double A, B, C, D;

public:
	Quadrangle (double a, double b, double c, double d, double A, double B, double C, double D) : 
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) 
	{}

	void printInfo() override {
		std::cout << "Quadrangle\n";
		std::cout << "Sides: " << a << " " << b << " " << c << " " << d << "\n";
		std::cout << "Angles: " << A << " " << B << " " << C << " " << D << "\n\n";
	}
};

class Rectangle : public Quadrangle {
public:
	Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
	{}

	void printInfo() override {
		std::cout << "Rectangle\n";
		std::cout << "Sides: " << a << " " << b << " " << a << " " << b << "\n";
		std::cout << "Angles: 90 90 90 90\n\n";
	}
};

class Square : public Quadrangle {
public:
	explicit Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) 
	{}

	void printInfo() override {
		std::cout << "Square\n";
		std::cout << "Sides: " << a << " " << a << " " << a << " " << a << "\n";
		std::cout << "Angles: 90 90 90 90\n\n";
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B) 
	{}

	void printInfo() override {
		std::cout << "Parallelogram\n";
		std::cout << "Sides: " << a << " " << b << " " << a << " " << b << "\n";
		std::cout << "Angles: " << A << " " << B << " " << A << " " << B << "\n\n";
	}
};

class Rhombus : public Quadrangle {
public:
	Rhombus(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B) 
	{}

	void printInfo() override {
		std::cout << "Rhombus\n";
		std::cout << "Sides: " << a << " " << a << " " << a << " " << a << "\n";
		std::cout << "Angles: " << A << " " << B << " " << A << " " << B << "\n\n";
	}
};

void print_info(Figure* fig) {
	fig->printInfo();
}

	int main() {
		Triangle triangle(3, 4, 5, 50, 60, 70);
		RightTriangle rightT(3, 4, 5, 30, 60);
		IsoscelesTriangle isoscelesT(5, 6, 50, 80);
		EquilateralTriangle equilateralT(5);

		Rectangle rectangle(4, 6);
		Square square(5);
		Parallelogram parallelogram(4, 6, 60, 120);
		Rhombus rombus(5, 70, 110);

		print_info(&triangle);
		print_info(&rightT);
		print_info(&isoscelesT);
		print_info(&equilateralT);
		print_info(&rectangle);
		print_info(&square);
		print_info(&parallelogram);
		print_info(&rombus);

		return EXIT_SUCCESS;
	}
