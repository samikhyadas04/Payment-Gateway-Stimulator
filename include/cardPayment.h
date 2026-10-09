#ifndef CARD_PAYMENT_H
#define CARD_PAYMENT_H

#include "Payment.h"

// CardPayment implements the abstract Payment class.
class CardPayment : public Payment {
private:
    std::string cardNumber;
    std::string cvv;

public:
    // Accepts card details from the terminal.
    void collectDetails() override;

    // Checks the length and numeric format of card details.
    bool validateDetails() const override;

    // Returns the payment method name.
    std::string getMethodName() const override;
};

#endif