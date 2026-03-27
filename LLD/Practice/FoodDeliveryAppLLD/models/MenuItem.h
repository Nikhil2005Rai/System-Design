#ifndef MENUITEM_H
#define MENUITEM_H

#include<string>

class MenuItem {
private:
    std::string code;
    std::string name;
    int price;

public:
    MenuItem(const std::string& code, const std::string& name, int price) 
        : code(code), name(name), price(price) {}

    //Getters and Setters
    std::string& getCode() const {
        return code;
    }

    void setCode(const std::string &c) {
        code = c;
    }

    std::string& getName() const {
        return name;
    }

    void setName(const std::string &n) {
        name = n;
    }

    int getPrice() const {
        return price;
    }

    void setPrice (int p) {
        price = p;
    }
};

#endif