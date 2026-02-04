#include <iostream>
#include <fstream>
#include <string>

class Address {
private: 
	std::string city{};
	std::string street{};
	int numberHouse{};
	int numberApartment{};
public:
	Address() = default;
	Address(std::string_view city, std::string_view street, int numberH, int numberAp) : 
		city{city}, street{street}, numberHouse{numberH}, numberApartment{numberAp}
	{ }

	std::string outputAddress() const {
		return city + ", " + street + ", " + std::to_string(numberHouse) + ", " + std::to_string(numberApartment);
	}

	std::string& getCity() {
		return city;
	}
};

void swap(Address* addresses, int i, int j);
void sort(Address* addresses, int size);

int main() {
	
	std::ofstream ofile("in.txt");
	if (ofile.is_open()) {
		ofile << "5\n"
			<< "Moscow\n" << "Builders\n" << "34\n" << "12\n"
			<< "Omsk\n" << "Puskin\n" << "2\n" << "13\n"
			<< "Rostov-on-Don\n" << "Voroshilovsky\n" << "43\n" << "56\n"
			<< "Voronezh\n" << "Lenin\n" << "1\n" << "212\n"
			<< "Moscow\n" << "Arbat\n" << "4\n" << "1\n";	
	}
	ofile.close();

	std::ifstream ifile("in.txt");
	if (!ifile.is_open()) {
		std::cout << "Error... in.txt is closed";
		return 1;
		}

	int counter{};
	ifile >> counter;
	Address* addresses = new Address[counter];

	for (int i{ 0 }; i < counter; ++i) {
		std::string city{};
		std::string street{};
		int numberHouse{};
		int numberApartment{};

		std::getline(ifile >> std::ws, city);
		std::getline(ifile >> std::ws, street);
		ifile >> numberHouse;
		ifile >> numberApartment;

		addresses[i] = Address(city, street, numberHouse, numberApartment);
	}

	ifile.close();

	std::ofstream outFile("out.txt");
	sort(addresses, counter);
	if (outFile.is_open()) {
		outFile << counter << '\n';

		for (int i{ 0 }; i < counter; ++i) {
			outFile << addresses[i].outputAddress() << '\n';
		}
	}
	outFile.close();
	delete[] addresses;

	return EXIT_SUCCESS;
}

void swap(Address* addresses, int i, int j) {
	Address temp = addresses[i];
	addresses[i] = addresses[j];
	addresses[j] = temp;
}

void sort(Address* addresses, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (addresses[j].getCity() > addresses[j + 1].getCity()) {
				swap(addresses, j, j + 1);
			}
		}
	}
}
