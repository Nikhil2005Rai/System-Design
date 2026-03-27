#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

class ScheduledOrderFactory : public OrderFactory {
private:
    std::string scheduleTime;
public:
    ScheduledOrderFactory(std::string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const std::vector<MenuItem>& menuItems,
                        PaymentStrategy* paymentStrategy, double totalCost, const std::string& orderType) override {
        Order* order = nullptr;

        if(orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setDeliveryAddress(user->getAddress());
            order = deliveryOrder;
        } 
        else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setSchedule(scheduleTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif 
