#include<iostream>
using namespace std;

class PaymentProcessor {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentProcessor () {};
};

class OldPaymentSystem {
public:
    void makePayment(int amount) {
        cout << "Paid " << amount << " using OLD system\n";
    }
};

//=====Adapter=====
class PaymentAdapter : public PaymentProcessor {
private:
    OldPaymentSystem* oldSystem;

public:
    PaymentAdapter(OldPaymentSystem* system) {
        oldSystem = system;
    }

    void pay(int amount) {
        oldSystem->makePayment(amount);
    }
};

int main() {
    OldPaymentSystem* oldSystem = new OldPaymentSystem();

    PaymentProcessor* processor = new PaymentAdapter(oldSystem);

    processor->pay(500);

    delete processor;
    delete oldSystem;

    return 0;
}