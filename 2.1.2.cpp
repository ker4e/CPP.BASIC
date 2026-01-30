#include <iostream>

class Calculator {
private:
    double num1{};
    double num2{};

public:
    Calculator() = default;

    double add() const { return num1 + num2; }
    double multiply() const { return num1 * num2; }
    double subtract() const { return num1 - num2; }
    double divide() const { return num1 / num2; }
   
    void setNum1(double setNum1) { num1 = setNum1; }
    void setNum2(double setNum2) { num2 = setNum2; }
};

void clearInput(); 

int main()
{
    char checkEnd{};
    char op{};
    double numFirst{};
    double numSecond{};
    Calculator calc{};
    
    do {
        std::cout << "\nWhat do you want to do? (Enter symbol)\n"
            << "c - calculator\n"
            << "q - quit\n>";
        std::cin >> checkEnd;

        if (checkEnd == 'c') {
            do {
                std::cout << "\nSelect operation ('+', '-', '*', '/'): ";
                std::cin >> op;

                if (op != '+' && op != '-' && op != '*' && op != '/') {
                    std::cout << "Invalid operation! Try again.\n";
                }
            } while (op != '+' && op != '-' && op != '*' && op != '/');
           

            std::cout << "Enter num1: ";
            
            while (!(std::cin >> numFirst)) {
                std::cout << "Invalid input! Enter num1 again: ";
                clearInput();
            }
            calc.setNum1(numFirst);

            do {
                std::cout << "Enter num2: ";
                while (!(std::cin >> numSecond)) {
                    std::cout << "Invalid input! Enter num2 again: ";
                    clearInput();
                }
                if (op == '/' && numSecond == 0)
                    std::cout << "Error: division by zero!\n";
            } while (op == '/' && numSecond == 0);
            calc.setNum2(numSecond);

            switch (op) {
            case '+':
                std::cout << "num1 + num2 = " << calc.add() << std::endl;
                break;
            case '-':
                std::cout << "num1 - num2 = " << calc.subtract() << std::endl;
                break;
            case '*':
                std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
                break;
            case '/':
                std::cout << "num1 / num2 = " << calc.divide() << std::endl;
                break;
            }
        }
        else if (checkEnd == 'q') {
                std::cout << "\nThank you! Goodbye =( \n";
        }
        else {
            std::cout << "Unknown operation!\n";
        }

    } while (checkEnd != 'q');

    return EXIT_SUCCESS;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
