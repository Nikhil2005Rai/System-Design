#include<bits/stdc++.h>
using namespace std;

/*
🧠 SIMPLE FACTORY PATTERN

👉 Idea:
Encapsulate object creation logic in one place (Factory),
instead of creating objects directly using "new" in client code.

✔ Benefits:
- Centralized object creation
- Reduces duplication
- Cleaner client code

❌ Limitation:
- Violates Open/Closed Principle (adding new type requires modifying factory)
*/


// ================= PRODUCT INTERFACE =================
class Burger {
public:
    virtual void prepare() = 0;  // Common interface for all burgers
    virtual ~Burger() {}; 
};


// ================= CONCRETE PRODUCTS =================

// Basic implementation
class BasicBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing basic burger." << endl;
    }
};

// Standard implementation
class StandardBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing standard burger." << endl;
    }
};

// Premium implementation
class PremiumBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing premium burger." << endl;
    }
};


// ================= FACTORY =================
class BurgerFactory {
public:

    /*
    🧠 Factory Method

    Based on input type, returns correct object.

    👉 Client does NOT need to know:
    - which class to instantiate
    - how object is created
    */
    Burger* createBurger(string type) {

        // ⚠️ Problem: if-else chain grows with new types
        if(type == "basic") {
            return new BasicBurger();
        }
        else if(type == "standard") {
            return new StandardBurger();
        }
        else if(type == "premium") {
            return new PremiumBurger();
        }
        else {
            cout << "Invalid Burger Type!!!" << endl;
            return nullptr;
        }
    }
};


// ================= CLIENT CODE =================
int main() {

    string type = "standard";

    /*
    🧠 Client only interacts with factory
    It doesn't directly use:
        new BasicBurger()
        new StandardBurger()

    👉 This reduces coupling
    */
    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    if(burger != nullptr) {
        burger->prepare();
    }

    delete burger;
    delete myBurgerFactory;

    return 0;
}


/*
🎯 INTERVIEW SUMMARY

Problem:
Multiple burger types → object creation scattered ❌

Solution:
Simple Factory ✔

Key Benefits:
✔ Encapsulates object creation
✔ Reduces client complexity
✔ Improves maintainability

Limitations:
❌ Adding new burger → modify factory (breaks OCP)

Upgrade Path:
👉 Use Factory Method Pattern (each subclass creates its own object)
👉 Or use map-based factory (remove if-else)

*/