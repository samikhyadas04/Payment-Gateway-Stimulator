#include "../include/NetBankingPayment.h"

#include <iostream>
#include <cctype>

// Collects simulated net banking credentials.
void NetBankingPayment::collectDetails() {
    std::cout << "Enter Net Banking Customer ID: ";
    std::getline(std::cin, customerID);

    std::cout << "Enter simulated banking password: ";
    std::getline(std::cin, bankingPassword);
}

// Checks that both fields are non-empty and contain no spaces.
// This does not authenticate with a real bank.
bool NetBankingPayment::validateDetails() const {

    if (customerID.empty() || bankingPassword.empty()) {
        return false;
    }

    for (char ch : customerID) {
        if (std::isspace(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    for (char ch : bankingPassword) {
        if (std::isspace(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    return true;
}

// Identifies this payment implementation as net banking.
std::string NetBankingPayment::getMethodName() const {
    return "Net Banking";
}