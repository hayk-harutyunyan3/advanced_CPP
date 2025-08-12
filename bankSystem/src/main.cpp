#include "../include/bankSystem.hpp"
#include <iostream>
#include <memory>

int main() {
std::unique_ptr<SavingsAccount> savings = std::make_unique<SavingsAccount>("Alice", 1000.0);
    std::unique_ptr<CheckingAccount> checking = std::make_unique<CheckingAccount>("Bob", 500.0);

    std::cout << "--- Initial Balances ---\n";
    std::cout << savings->get_holder_name() << ": " << savings->balance() << "\n";
    std::cout << checking->get_holder_name() << ": " << checking->balance() << "\n\n";

    std::cout << "--- Deposits ---\n";
    savings->deposit(200.0);
    checking->deposit(300.0);
    std::cout << savings->get_holder_name() << ": " << savings->balance() << "\n";
    std::cout << checking->get_holder_name() << ": " << checking->balance() << "\n\n";

    std::cout << "--- Withdrawals ---\n";
    savings->withdraw(150.0);
    checking->withdraw(700.0); 
    std::cout << savings->get_holder_name() << ": " << savings->balance() << "\n";
    std::cout << checking->get_holder_name() << ": " << checking->balance() << "\n\n";

    std::cout << "--- Savings Account Details ---\n";
    std::cout << "Interest percent: " << savings->get_percent() << "%\n";
    std::cout << "Updated balance (with interest): " << savings->get_update_balance() << "\n\n";

    std::cout << "--- Further Transactions ---\n";
    savings->deposit(500.0);
    checking->withdraw(50.0);
    std::cout << savings->get_holder_name() << ": " << savings->balance() << "\n";
    std::cout << checking->get_holder_name() << ": " << checking->balance() << "\n";
}
