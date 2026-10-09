#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

// Forward declaration: User is defined in User.h.
class User;

// Abstract base class for all payment methods.
class Payment {
public:
    // Virtual destructor allows safe deletion through a base pointer.
    virtual ~Payment() = default;

    // Pure virtual functions make Payment an abstract class.
    virtual void collectDetails() = 0;
    virtual bool validateDetails() const = 0;
    virtual std::string getMethodName() const = 0;

    bool processPayment(User& user, double amount);
};

#endif