#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <string>
#include <vector>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

class TomatoApp {
public:
    TomatoApp() {
        initializeRestaurants();
    }

    void initializeRestaurants() {
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15));

        Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
        restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
        restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50));

        Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
        restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
        restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);
    }

    std::vector<Restaurant*> searchRestaurants(const std::string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user, const std::string& itemCode) {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            std::cout << "Please select a restaurant first." << std::endl;
            return;
        }

        for (const auto& item : restaurant->getMenu()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, const std::string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, const std::string& orderType, PaymentStrategy* paymentStrategy, const std::string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const std::string& orderType,
                    PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty()) {
            delete orderFactory;
            return nullptr;
        }

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        std::vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(
            user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        delete orderFactory;
        return order;
    }

    void payForOrder(User* user, Order* order) {
        if (!order) {
            std::cout << "Unable to place order because the cart is empty." << std::endl;
            return;
        }

        bool isPaymentSuccess = order->processPayment();
        if (isPaymentSuccess) {
            NotificationService::notify(order);
            user->getCart()->clear();
        }
    }

    void printUserCart(User* user) {
        std::cout << "Items in cart:" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        for (const auto& item : user->getCart()->getItems()) {
            std::cout << item.getCode() << " : " << item.getName() << " : Rs. " << item.getPrice() << std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Grand total : Rs. " << user->getCart()->getTotalCost() << std::endl;
    }
};

#endif
