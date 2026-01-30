#include <iostream>

class Calculator {
private:
    double num1{};
    double num2{};

public:
    double add() { return num1 + num2; }
    double multiply() { return num1 * num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double divide_1_2() { return num1 / num2; }
    double divide_2_1() { return num2 / num1; }
    
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }
    
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
};

int main()
{
    Calculator calc{};
    double input{};

    while (true) {
        std::cout << "Enter num1: ";
        std::cin >> input;

        while (!calc.set_num1(input)) {
            std::cout << "Invalid input!\nEnter num1: ";
            std::cin >> input;
        }

        std::cout << "Enter num2: ";
        std::cin >> input;

        while (!calc.set_num2(input)) {
            std::cout << "Invalid input!\nEnter num2: ";
            std::cin >> input;
        }

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return EXIT_SUCCESS;
}
