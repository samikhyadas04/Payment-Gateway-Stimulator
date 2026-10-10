#include "../include/Payment.h"
#include "../include/User.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>

// Processes a payment using the selected payment method.
bool Payment::processPayment(User& user, double amount) {

    // Reject zero or negative payment amounts.
    if (amount <= 0) {
        throw std::invalid_argument(
            "Payment amount must be greater than zero."
        );
    }

    // Check whether the user has enough balance.
    if (amount > user.getBalance()) {
        std::cout << "\nPayment Failed: Insufficient balance.\n";
        return false;
    }

    // Deduct the payment amount from the user's balance.
    if (!user.deductBalance(amount)) {
        std::cout << "\nPayment Failed.\n";
        return false;
    }

    // Generate a simple unique transaction ID during this run.
    static int transactionCounter = 1000;

    std::ostringstream id;
    id << "TXN" << ++transactionCounter;

    // Create a transaction record for the successful payment.
    Transaction transaction;
    transaction.transactionID = id.str();
    transaction.amount = amount;
    transaction.paymentMethod = getMethodName();
    transaction.status = "SUCCESS";

    // Save the transaction in the logged-in user's records.
    user.addTransaction(transaction);

    // Display the payment receipt in the terminal.
    std::cout << "\nPayment Successful!\n";
    std::cout << "Transaction ID: "
              << transaction.transactionID << '\n';

    std::cout << "Amount: Rs. "
              << std::fixed << std::setprecision(2)
              << amount << '\n';

    std::cout << "Payment Method: "
              << transaction.paymentMethod << '\n';

    std::cout << "Status: " << transaction.status << '\n';

    return true;
}