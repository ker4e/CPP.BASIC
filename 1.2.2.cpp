#include <iostream>
#include <string>

struct BankAccount {
    int accountNumber {};
    std::string ownerName {};
    double balance {};
};

void changeBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    BankAccount account;
    double newBalance;

    std::cout << "Enter account number: ";
    std::cin >> account.accountNumber;

    std::cout << "Enter owner`s name: ";
    std::cin >> account.ownerName;

    std::cout << "Enter balance: ";
    std::cin >> account.balance;

    std::cout << "Enter new balance: ";
    std::cin >> newBalance;

    changeBalance(account, newBalance);

    std::cout << "Your account: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return EXIT_SUCCESS;
}
