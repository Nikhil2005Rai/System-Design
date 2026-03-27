#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

class Order {
private:
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant; 
    std::vector<MenuItem> items;
    PaymentStrategy* paymentStrategy;
    double total;
    string scheduled;

public:
    Order() {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        scheduled = "";
        orderId = ++nextOrderId;
        total = 0.0;  
    }

    virtual ~Order() {
        delete paymentStrategy;
    }

    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay();
            return true;
        } else {
            std::cout << "Please choose a payment mode first" << std::endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    //Getters and Setters
    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const std::vector<MenuItem>& its) {
        items = its;
        total = 0;
        for (auto &i : items) {
            total += i.getPrice();
        }
    }

    const std::vector<MenuItem>& getItems() const {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        paymentStrategy = p;  
    }

    void setSchedule(const std::string& s) {
        scheduled = s;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }
};

int Order::nextOrderId = 0;

#endif