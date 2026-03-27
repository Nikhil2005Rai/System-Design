#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
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

    std::vector<Restaurant*> searchByLocation(string loc) {
        vector<Restaurant*> result;
        std::transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for(auto r: restuarants) {
            string rl = r->getLocation();
            if(rl == loc) {
                result.push_back(rl);
            }
        }
        return result;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;
#endif