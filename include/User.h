#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

// Structure representing a single payment transaction.
struct Transaction {
    std::string transactionID;
    double amount;
    std::string paymentMethod;
    std::string status;
};

// Represents a registered user of the simulator.
class User {
private:
    // Private data demonstrates encapsulation.
    std::string name;
    std::string username;
    std::string password;
    double balance;

    // Stores all successful transactions of this user.
    std::vector<Transaction> transactions;

public:
    // Constructor initializes a new user's details.
    User(std::string name, std::string username,
         std::string password, double balance);

    // Getter functions provide controlled access to private data.
    std::string getName() const;
    std::string getUsername() const;
    double getBalance() const;

    // Checks whether the entered password matches.
    bool checkPassword(const std::string& enteredPassword) const;

    // Deducts money only when the amount is valid
    // and the user has sufficient balance.
    bool deductBalance(double amount);

    // Adds a transaction to the user's transaction list.
    void addTransaction(const Transaction& transaction);

    // Displays all transactions belonging to this user.
    void displayTransactions() const;
};

#endif