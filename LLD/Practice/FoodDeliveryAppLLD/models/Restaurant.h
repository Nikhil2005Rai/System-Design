#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>
#include <string>
#include "MenuItem.h"

class Restaurant {
private:
    static int nextRestaurantId;
    int restaurantId;
    std::string name;
    std::string location;
    std::vector<MenuItem> menu;

public:
    Restaurant(const std::string& name, const std::string& location) {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }

    //Debug only
    ~Restaurant() {
        std::cout << "Destroying Restaurant: " << name << ", and clearing its menu." << std::endl;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string &s) {
        name = s;
    }

    std::string getLocation() const {
        return location;
    }

    void setLocation(const std::string &loc) {
        location = loc;
    }

    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }

    const std::vector<MenuItem>& getMenu() const {
        return menu;
    }    
};

int Restaurant::nextRestaurantId = 0;

#endif