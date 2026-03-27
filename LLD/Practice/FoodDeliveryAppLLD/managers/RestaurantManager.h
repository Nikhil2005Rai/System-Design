#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "../models/Restaurant.h"

class RestaurantManager {
private:
    std::vector<Restaurant*> restuarants;
    static RestaurantManager* instance;

    RestaurantManager() {
        //Private Constructor
    }

public:
    static RestaurantManager* getInstance() {
        if(!instance) {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r) {
        restuarants.push_back(r);
    }

    std::vector<Restaurant*> searchByLocation(std::string loc) {
        std::vector<Restaurant*> result;
        std::transform(loc.begin(), loc.end(), loc.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
        for (auto r : restuarants) {
            std::string rl = r->getLocation();
            std::transform(rl.begin(), rl.end(), rl.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
            if(rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;
#endif
