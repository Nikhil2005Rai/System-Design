#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update(int value) = 0;
};

class ConcreteObserver : public Observer {
private:
    int id;

public:
    ConcreteObserver(int id) : id(id) {}

    void update(int value) override {
        std::cout << "Observer " << id << " received: " << value << std::endl;
    }
};

class Subject {
public:
    virtual void addObserver(Observer* obs) = 0;
    virtual void removeObserver(Observer* obs) = 0;
    virtual void notifyObservers() = 0;
};

class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int state;

public:
    void addObserver(Observer* obs) override {
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs) override {
        // simple remove logic
        return;
    }

    void setState(int value) {
        state = value;
        notifyObservers();
    }

    void notifyObservers() override {
        for (auto obs : observers) {
            obs->update(state);
        }
    }
};

int main() {
    ConcreteSubject subject;

    ConcreteObserver o1(1), o2(2);

    subject.addObserver(&o1);
    subject.addObserver(&o2);

    subject.setState(10);
}