#include<bits/stdc++.h>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class Drink {
public:
    virtual void serve() = 0;
    virtual ~Drink() {}
};

// 🍔 Burgers
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Basic Burger\n";
    }
};

class WheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Wheat Burger\n";
    }
};

// 🥤 Drinks
class Coke : public Drink {
public:
    void serve() override {
        cout << "Serving Coke\n";
    }
};

class Juice : public Drink {
public:
    void serve() override {
        cout << "Serving Juice\n";
    }
};

// 🏭 Abstract Factory
class MealFactory {
public:
    virtual unique_ptr<Burger> createBurger() = 0;
    virtual unique_ptr<Drink> createDrink() = 0;
};

// 🍟 Concrete Factories
class RegularMealFactory : public MealFactory {
public:
    unique_ptr<Burger> createBurger() override {
        return make_unique<BasicBurger>();
    }
    unique_ptr<Drink> createDrink() override {
        return make_unique<Coke>();
    }
};

class HealthyMealFactory : public MealFactory {
public:
    unique_ptr<Burger> createBurger() override {
        return make_unique<WheatBurger>();
    }
    unique_ptr<Drink> createDrink() override {
        return make_unique<Juice>();
    }
};