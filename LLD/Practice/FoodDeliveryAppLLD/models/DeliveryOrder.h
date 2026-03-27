#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"

class DeliveryOrder : public Order {
private:
    std::string deliveryAddress;

public:
    DeliveryOrder() : deliveryAddress("") {}

    std::string getType() const override {
        return "Delivery";
    }

    //Getter and Setters
    void setDeliveryAddress(const std::string& addr) {
        deliveryAddress = addr;
    }

    std::string getDeliveryAddress() const {
        return deliveryAddress;
    } 
};

#endif 