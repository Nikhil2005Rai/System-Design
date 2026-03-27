#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class UpiPaymentStrategy : public PaymentStrategy {
private:
    std::string mobile;

public:
    UpiPaymentStrategy(const std::string& mob) {
        mobile = mob;
    }

    void pay(double amount) override {
        std::cout << "Paid Rs. " << amount << " using UPI (" << mobile << ")" << std::endl;
    }
};

#endif
