#include <iostream>

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() = default;
};

class Figure : public Shape {
private:
	int sidesCount = 0;
public:
	Figure() = default;
	void draw() override { std::cout << "Figure: " << sidesCount << std::endl; }
}; 

class Triangle : public Shape {
private:
	int sidesCount = 3;
public:
	Triangle() = default;
	void draw() override { std::cout << "Triangle: " << sidesCount << std::endl; }
};

class Rectangle : public Shape {
private:
	int sidesCount = 4;
public:
	Rectangle() = default;
	void draw() override { std::cout << "Rectangle: " << sidesCount << std::endl; }
};

void drawShape(Shape* shape) 
{
	shape->draw();
	delete shape;
}

int main() {

	drawShape(new Triangle{});
	drawShape(new Rectangle{});
	drawShape(new Figure{});

	return EXIT_SUCCESS;
}
