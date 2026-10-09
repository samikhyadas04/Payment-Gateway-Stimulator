#ifndef UPI_PAYMENT_H
#define UPI_PAYMENT_H

#include "Payment.h"

// UPIPayment inherits the common Payment interface.
class UPIPayment : public Payment {
private:
    std::string upiID;

public:
    // Accepts UPI details from the terminal.
    void collectDetails() override;

    // Checks whether the entered UPI ID has a basic valid format.
    bool validateDetails() const override;

    // Returns the payment method name.
    std::string getMethodName() const override;
};

#endif