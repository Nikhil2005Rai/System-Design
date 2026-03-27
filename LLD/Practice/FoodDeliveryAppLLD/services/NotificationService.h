#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <iostream>
#include "../models/Order.h"

class NotificationService {
public:
    static void notify(Order* order) {
        std::cout << "\nNotification: New " << order->getType() << " order placed!" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Order ID: " << order->getOrderId() << std::endl;
        std::cout << "Customer: " << order->getUser()->getName() << std::endl;
        std::cout << "Restaurant: " << order->getRestaurant()->getName() << std::endl;
        std::cout << "Items Ordered:\n";

        const std::vector<MenuItem>& items = order->getItems();
        for (const auto& item : items) {
            std::cout << "   - " << item.getName() << " (Rs. " << item.getPrice() << ")\n";
        }

        std::cout << "Total: Rs. " << order->getTotal() << std::endl;
        std::cout << "Scheduled For: " << order->getScheduled() << std::endl;
        std::cout << "Payment: Done" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
};

#endif
