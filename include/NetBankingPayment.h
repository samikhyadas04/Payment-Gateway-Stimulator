#ifndef NET_BANKING_PAYMENT_H
#define NET_BANKING_PAYMENT_H

#include "Payment.h"

// NetBankingPayment provides a separate implementation
// of the common Payment interface.
class NetBankingPayment : public Payment {
private:
    std::string customerID;
    std::string bankingPassword;

public:
    // Accepts simulated net banking credentials.
    void collectDetails() override;

    // Performs basic validation of the entered details.
    bool validateDetails() const override;

    // Returns the payment method name.
    std::string getMethodName() const override;
};

#endif