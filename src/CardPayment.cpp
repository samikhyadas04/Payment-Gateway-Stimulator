#include "../include/CardPayment.h"

#include <iostream>
#include <cctype>

// Collects simulated card details.
void CardPayment::collectDetails() {
    std::cout << "Enter 16-digit card number: ";
    std::getline(std::cin, cardNumber);

    std::cout << "Enter 3 or 4-digit CVV: ";
    std::getline(std::cin, cvv);
}

// Checks card number and CVV format.
// This does not verify whether a real card exists.
bool CardPayment::validateDetails() const {

    // The simulated card number must contain 16 digits.
    if (cardNumber.length() != 16) {
        return false;
    }

    // The CVV must contain either 3 or 4 digits.
    if (cvv.length() != 3 && cvv.length() != 4) {
        return false;
    }

    // Ensure every card number character is numeric.
    for (char ch : cardNumber) {
        if (!std::isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    // Ensure every CVV character is numeric.
    for (char ch : cvv) {
        if (!std::isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    return true;
}

// Identifies this payment implementation as a card payment.
std::string CardPayment::getMethodName() const {
    return "Credit/Debit Card";
}