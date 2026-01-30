#include <iostream>
#include <string>

class Counter {
private:
	int counter{};
public:
	Counter() : counter{ 1 }
	{}
	Counter(int counterAsk) : counter{ counterAsk }
	{}
	void addCounter() { ++counter; }
	void reduseCounter() { --counter; }
	int checkCounter() const { return counter; }
};

int main() {

	Counter counter{};
	std::string answer{};
	char operationCheck{};
	int initialValue{};

	do {
		std::cout << "\nDo you want to specify the initial value of the counter? Enter yes or no: ";
		std::cin >> answer;

		if (answer == "yes")
		{
			std::cout << "Enter the initial value of the counter: ";
			while (!(std::cin >> initialValue)) {
				std::cout << "Invalid input! Enter a number: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			counter = Counter{ initialValue };
			break;
		}
		else if (answer == "no") { break; }
		else { std::cout << "Invalid answer. Try again!\n"; }

	} while (answer != "yes" && answer != "no");

	do {
		std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
		std::cin >> operationCheck;
		switch (operationCheck) {
		case '+':
			counter.addCounter();
			break;
		case '-':
			counter.reduseCounter();
			break;
		case '=':
			std::cout << "Current value: " << counter.checkCounter() << std::endl;
			break;
		case 'x':
			std::cout << "Exiting program!\n\n";
			break;
		default:
			std::cout << "Invalid command!\n\n";
		}
	} while (operationCheck != 'x');

	return EXIT_SUCCESS;
}
