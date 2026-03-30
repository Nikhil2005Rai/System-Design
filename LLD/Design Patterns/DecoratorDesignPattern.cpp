#include <iostream>
#include <string>

// ================= Component Interface =================
class Pizza {
public:
    virtual std::string getDescription() = 0;
    virtual int cost() = 0;
    virtual ~Pizza() {}
};

// ================= Concrete Component =================
class BasicPizza : public Pizza {
public:
    std::string getDescription() override {
        return "Basic Pizza";
    }

    int cost() override {
        return 100;
    }
};

// ================= Decorator Base Class =================
class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;

public:
    PizzaDecorator(Pizza* p) : pizza(p) {}

    virtual ~PizzaDecorator() {
        delete pizza; // clean up wrapped object
    }
};

// ================= Concrete Decorators =================
class Cheese : public PizzaDecorator {
public:
    Cheese(Pizza* p) : PizzaDecorator(p) {}

    std::string getDescription() override {
        return pizza->getDescription() + ", Cheese";
    }

    int cost() override {
        return pizza->cost() + 20;
    }
};

class Olives : public PizzaDecorator {
public:
    Olives(Pizza* p) : PizzaDecorator(p) {}

    std::string getDescription() override {
        return pizza->getDescription() + ", Olives";
    }

    int cost() override {
        return pizza->cost() + 15;
    }
};

class Mushroom : public PizzaDecorator {
public:
    Mushroom(Pizza* p) : PizzaDecorator(p) {}

    std::string getDescription() override {
        return pizza->getDescription() + ", Mushroom";
    }

    int cost() override {
        return pizza->cost() + 25;
    }
};

// ================= Main =================
int main() {
    Pizza* pizza = new BasicPizza();

    // Add decorators (wrapping)
    pizza = new Cheese(pizza);
    pizza = new Olives(pizza);
    pizza = new Mushroom(pizza);

    std::cout << "Order: " << pizza->getDescription() << std::endl;
    std::cout << "Total Cost: " << pizza->cost() << std::endl;

    delete pizza; // cleanup all layers

    return 0;
}