#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"

class PickupOrder : public Order {
private:
    std::string restaurantAddress;

public:
    PickupOrder() : restaurantAddress("") {}

    std::string getType() const override {
        return "Pickup";
    }

    //Getter and Setters
    void setRestaurantAddress(const std::string& addr) {
        restaurantAddress = addr;
    }

    std::string getRestaurantAddress() const {
        return restaurantAddress;
    } 
};

#endif 