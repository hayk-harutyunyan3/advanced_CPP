#include "../include/bankSystem.hpp"
#include <gtest/gtest.h>

TEST(savingsAccountTest, Test1) {
    SavingsAccount acc1("Account1");
    EXPECT_EQ(acc1.balance(), 0);
    EXPECT_EQ(acc1.get_holder_name(), "Account1");

    // deposite test
    acc1.deposit(1000);
    EXPECT_EQ(acc1.balance(), 1065);

    // valid withdraw test
    acc1.withdraw(500);
    EXPECT_EQ(acc1.balance(), 565);

    // invalid withdaq test
    EXPECT_THROW(acc1.withdraw(1000), std::runtime_error);
} 

TEST(savingsAccountTest, Test2) {
    // Percent and update_balance test
    SavingsAccount acc2("Account2");
    acc2.deposit(10000);  
    EXPECT_EQ(acc2.get_percent(), 9.5);
    EXPECT_EQ(acc2.get_update_balance(), 8000);
}

TEST(checkingAccountTest, Test1) {
    CheckingAccount acc1("Account1", 1000);
    EXPECT_EQ(acc1.balance(), 1000);

    // valid negative balance test
    acc1.withdraw(1500);
    EXPECT_EQ(acc1.balance(), -500);

    // invalid negative balance test
    EXPECT_THROW(acc1.withdraw(600), std::runtime_error);
}