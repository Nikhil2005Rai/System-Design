#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    std::string cardNumber;

public:
    CreditCardPaymentStrategy(const std::string& card) {
        cardNumber = card;
    }

    void pay(double amount) override {
        std::cout << "Paid Rs. " << amount << " using Credit Card (" << cardNumber << ")" << std::endl;
    }
};

#endif
