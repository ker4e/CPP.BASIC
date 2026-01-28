#include <iostream>

enum class Months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main() {
	int monthNumber{};
	
	do {
		std::cout << "Enter the month number (To exit, enter - 0: ";
		std::cin >> monthNumber;
			if (monthNumber >= 1 && monthNumber <= 12) {
				switch (static_cast<Months>(monthNumber)) {
				case Months::January:
					std::cout << "January\n";
					break;
				case Months::February:
					std::cout << "February\n";
					break;
				case Months::March:
					std::cout << "March\n";
					break;
				case Months::April:
					std::cout << "April\n";
					break;
				case Months::May:
					std::cout << "May\n";
					break;
				case Months::June:
					std::cout << "June\n";
					break;
				case Months::July:
					std::cout << "July\n";
					break;
				case Months::August:
					std::cout << "August\n";
					break;
				case Months::September:
					std::cout << "September\n";
					break;
				case Months::October:
					std::cout << "October\n";
					break;
				case Months::November:
					std::cout << "November\n";
					break;
				case Months::December:
					std::cout << "December\n";
					break;
				}
			}
			else if (monthNumber != 0) { std::cout << "Wrong number!!! Try again =)\n"; }
			else { std::cout << "Goodbye =(\n"; }
	} while (monthNumber != 0);

	return EXIT_SUCCESS;
}
