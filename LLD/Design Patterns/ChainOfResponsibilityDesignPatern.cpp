#include<bits/stdc++.h>
using namespace std;

class Handler {
private:
    Handler* next;

public:
    Handler() : next(nullptr) {}

    void setNext(Handler* n) {
        next = n;
    }

    virtual void handle(int amount) {
        if(next) next->handle(amount);
    }
    virtual ~Handler() {};
};

class AuthHandler : public Handler {
public:
    void handle(int amount) override {
        cout << "Auth check passed..." << endl;
        Handler::handle(amount);
    }
};

class BalanceHandler : public Handler {
public:
    void handle(int amount) override {
        if(amount < 1000) {
            cout << "Insufficient Balance!!!" << endl;
            return;
        }
        cout << "Balance check passed..." <<endl;
        Handler::handle(amount);
    }
};

class PaymentHandler : public Handler {
public:
    void handle(int amount) override {
        cout << "The payment of " << amount << " have been processed...\n\n";
    }
};

int main() {
    Handler* auth = new AuthHandler();
    Handler* balance = new BalanceHandler();
    Handler* payment = new PaymentHandler();

    auth->setNext(balance);
    balance->setNext(payment);

    auth->handle(3000);

    delete auth;
    delete balance; 
    delete payment; 

    return 0;
}