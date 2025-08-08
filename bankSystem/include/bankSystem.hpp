#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include "string"

class BankAccount {
public:
    BankAccount(const std::string &account_holder);
    explicit BankAccount(const std::string &account_holder, double initial_balance);
    virtual ~BankAccount() = default;
    
    virtual void deposit(double sum) = 0;
    virtual void withdraw(double sum) = 0;
    double balance() const;
    std::string get_holder_name() const;
protected:
    std::string m_account_holder;
    double m_balance;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const std::string &account_holder);
    explicit SavingsAccount(const std::string &account_holder, double initial_balance);

    void deposit(double sum) override;
    void withdraw(double sum) override;
    double get_percent() const;
    double get_update_balance() const;
private:
    double m_percent;
    double m_update_balance;

    void update_percent();
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const std::string &account_holder);
    explicit CheckingAccount(const std::string &account_holder, double initial_balance);

    void deposit(double sum) override;
    void withdraw(double sum) override;
private:
    double m_debt_sum;
};

#endif /* BANKSYSTEM_HPP */