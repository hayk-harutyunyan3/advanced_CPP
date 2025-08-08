#include "../include/bankSystem.hpp"
#include <stdexcept>

// BankAccount methods

BankAccount::BankAccount(const std::string &account_holder) : m_account_holder{account_holder}, m_balance{0} { }

BankAccount::BankAccount(const std::string &account_holder, double initial_balance) : m_account_holder{account_holder}, m_balance{initial_balance} { }

double BankAccount::balance() const {
    return m_balance;
}

std::string BankAccount::get_holder_name() const {
    return m_account_holder;
}

// SavingsAccount methods

SavingsAccount::SavingsAccount(const std::string &account_holder) : BankAccount{account_holder}, m_percent{5}, m_update_balance{1000} { }

SavingsAccount::SavingsAccount(const std::string &account_holder, double initial_balance) : BankAccount{account_holder, initial_balance}, m_percent{5}, m_update_balance{1000} { 
    update_percent();
    m_balance += initial_balance * m_percent / 100.0;
}

void SavingsAccount::deposit(double sum) {
    m_balance += sum;
    update_percent();
    m_balance += sum * m_percent / 100.0;
}

void SavingsAccount::withdraw(double sum) {
    if (m_balance < sum) {
        throw std::runtime_error("Saving account cant have negative balance!");
    }
    m_balance -= sum;
}

double SavingsAccount::get_percent() const {
    return m_percent;
}

double SavingsAccount::get_update_balance() const {
    return m_update_balance;
}

void SavingsAccount::update_percent() {
    double tmp_balance = m_balance;
    while (tmp_balance >= m_update_balance) {
        tmp_balance -= m_update_balance;
        m_percent += 1.5;
        m_update_balance *= 2;
    }
}

// CheckingAccount methods

CheckingAccount::CheckingAccount(const std::string &account_holder) : BankAccount{account_holder}, m_debt_sum{-1000} { }

CheckingAccount::CheckingAccount(const std::string &account_holder, double initial_balance) : BankAccount{account_holder, initial_balance}, m_debt_sum{-1000} { }

void CheckingAccount::deposit(double sum) {
    m_balance += sum;
}

void CheckingAccount::withdraw(double sum) {
    if (m_balance - sum < m_debt_sum) {
        throw std::runtime_error("Checking account debt cant be more then 1000$!");
    }
    m_balance -= sum;
}