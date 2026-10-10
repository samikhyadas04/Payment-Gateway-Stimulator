#include "../include/PaymentMethod.h"

PaymentMethod::PaymentMethod(double bal)
{
    balance = bal;
}

PaymentMethod::~PaymentMethod()
{
}

double PaymentMethod::getBalance()
{
    return balance;
}

void PaymentMethod::addMoney(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
}