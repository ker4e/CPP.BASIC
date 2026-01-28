#include <iostream>
#include <string>

struct Address {
	std::string city;
	std::string street;
	int houseNumber;
	int apartmentNumber;
	int postalCode;
};

void printAddress(const Address& address) {
	std::cout << "City: " << address.city << std::endl;
	std::cout << "Street: " << address.street << std::endl;
	std::cout << "House number: " << address.houseNumber << std::endl;
	std::cout << "Apartment number: " << address.apartmentNumber << std::endl;
	std::cout << "Postal code: " << address.postalCode << std::endl;
	std::cout << std::endl;
}

int main() {

	Address address1{
	   "Moscow",
	   "Arbat",
	   12,
	   8,
	   123456
	};

	Address address2{
		"Izhevsk",
		"Pushkina",
		59,
		143,
		953769
	};

	printAddress(address1);
	printAddress(address2);
	
	return EXIT_SUCCESS;
}
