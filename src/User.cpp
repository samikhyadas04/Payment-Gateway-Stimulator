#include "../include/User.h"

#include <iostream>
#include <iomanip>
#include <utility>

// Constructor: initializes the user's information.
User::User(std::string name, std::string username,
           std::string password, double balance)
    : name(std::move(name)),
      username(std::move(username)),
      password(std::move(password)),
      balance(balance) {
}
std::string User::getPassword() const {
    return password;
}

// Returns the user's name.
std::string User::getName() const {
    return name;
}

// Returns the registered username.
std::string User::getUsername() const {
    return username;
}

// Returns the user's current balance.
double User::getBalance() const {
    return balance;
}

// Compares the entered password with the stored password.
bool User::checkPassword(
    const std::string& enteredPassword) const {
    return password == enteredPassword;
}

// Deducts money only if the amount is positive
// and does not exceed the available balance.
bool User::deductBalance(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }

    balance -= amount;
    return true;
}

// Adds a transaction to the user's transaction history.
void User::addTransaction(
    const Transaction& transaction) {
    transactions.push_back(transaction);
}

// Displays the logged-in user's transactions.
void User::displayTransactions() const {

    // Handle the case where no payments have been made.
    if (transactions.empty()) {
        std::cout << "\nNo transactions found.\n";
        return;
    }

    std::cout << "\n========== TRANSACTIONS ==========\n";

    // Display each transaction stored in the vector.
    for (const Transaction& transaction : transactions) {
        std::cout << "Transaction ID: "
                  << transaction.transactionID << '\n';

        std::cout << "Amount: Rs. "
                  << std::fixed << std::setprecision(2)
                  << transaction.amount << '\n';

        std::cout << "Payment Method: "
                  << transaction.paymentMethod << '\n';

        std::cout << "Status: "
                  << transaction.status << '\n';

        std::cout << "---------------------------------\n";
    }
}