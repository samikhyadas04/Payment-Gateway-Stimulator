#include "../include/UPIPayment.h"

#include <iostream>
#include <cctype>

// Reads the UPI ID entered by the user.
void UPIPayment::collectDetails() {
    std::cout << "Enter UPI ID: ";
    std::getline(std::cin, upiID);
}

// Performs basic UPI ID format validation.
bool UPIPayment::validateDetails() const {

    // A UPI ID must contain '@' with characters on both sides.
    std::size_t atPosition = upiID.find('@');

    if (atPosition == std::string::npos ||
        atPosition == 0 ||
        atPosition == upiID.length() - 1) {
        return false;
    }

    // Reject spaces in the UPI ID.
    for (char ch : upiID) {
        if (std::isspace(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    return true;
}

// Identifies this payment implementation as UPI.
std::string UPIPayment::getMethodName() const {
    return "UPI";
}