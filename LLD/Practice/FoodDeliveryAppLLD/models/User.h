#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"

class User {
private:
    int userId;
    std::string name;
    std::string address;
    Cart* cart;

public:
    User(int userId, const std::string& name, const std::string& address) {
        this->userId = userId;
        this->name = name;
        this->address = address;
        cart = new Cart();
    }

    ~User() {
        delete cart;
    }

    //Getters and Setters
    std::string getName() const {
        return name;
    }

    void setName(const string &n) {
        name = n;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string &a) {
        address = a;
    }

    Cart* getCart() const {
        return cart;
    }
};

#endif