#include<bits/stdc++.h>
using namespace std;

class Order;//Forward declaration for order state

class OrderState {
public:
    virtual void next(Order* order) = 0;
    virtual void printStatus() = 0;
    virtual ~OrderState() {}
};

class Order {
private:
    OrderState* state;

public:
    Order(OrderState* s) : state(s) {}

    void setState(OrderState* s) {
        state = s;
    }

    void nextState() {
        state->next(this)
    }

    void printState() {
        state->printStatus();
    }
};

//Concrete states
class PlacedState : public OrderState {
public:
    void next(Order* order) override;

    void printStatus() override {
        cout << "Order Placed\n";
    }
};

class ShippedState : public OrderState {
public:
    void next(Order* order) override;

    void printStatus() override {
        cout << "Order Shipped\n";
    }
};

class DeliveredState : public OrderState {
public:
    void next(Order* order) override {
        cout << "Order already delivered\n";
    }

    void printStatus() {
        cout << "Ordered Delivered\n";
    }
};

//State transitions
void PlacedState::next(Order* order) {
    order->setState(new ShippedState);
}

void ShippedState::next(Order* order) {
    ordder->setState(new DeliveredState);
}

int main() {
    Order* order = new Order(new PlacedState());

    order->printState();
    order->nextState();

    order->printState();
    order->nextState();

    order->printState();

    return 0;
}