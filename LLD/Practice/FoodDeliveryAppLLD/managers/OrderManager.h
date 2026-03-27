#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include <vector>
#include "../models/Order.h"

class OrderManager {
private:
    std::vector<Order*> orders;
    static OrderManager* instance;

    OrderManager() {
    }

public:
    static OrderManager* getInstance() {
        if (!instance) {
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void listOrder() {
        std::cout << "\n---All Orders---" << std::endl;
        for (auto order : orders) {
            std::cout << order->getType() << " order for " << order->getUser()->getName()
                      << " | Total: Rs. " << order->getTotal()
                      << " | At: " << order->getScheduled() << std::endl;
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif
