#include<bits/stdc++.h>
using namespace std;

/*
🧠 STRATEGY PATTERN IMPLEMENTATION

👉 Idea:
Instead of hardcoding behaviors (walk, talk, fly) inside Robot,
we extract them into separate interfaces.

✔ This allows:
- Dynamic behavior change
- Reusability
- Avoiding inheritance explosion

This follows:
👉 "Composition over Inheritance"
*/

// ================= WALK BEHAVIOR =================
class WalkableRobot {
public:
    virtual void walk() = 0;  // Strategy interface
    virtual ~WalkableRobot() {};
};

// Concrete Strategy: Normal walking
class NormalWalk: public WalkableRobot {
public:
    void walk() override {
        cout << "Walking normally...." << endl;
    }
};

// Concrete Strategy: Cannot walk
class NoWalk: public WalkableRobot {
public:
    void walk() override {
        cout << "Cann't walk!" << endl;
    }
};


// ================= TALK BEHAVIOR =================
class TalkableRobot {
public:
    virtual void talk() = 0;  // Strategy interface
    virtual ~TalkableRobot() {};
};

// Concrete Strategy: Normal talking
class NormalTalk: public TalkableRobot {
public:
    void talk() override {
        cout << "Talk normally...." << endl;
    }
};

// Concrete Strategy: Cannot talk
class NoTalk: public TalkableRobot  {
public:
    void talk() override {
        cout << "Cann't talk!" << endl;
    }
};


// ================= FLY BEHAVIOR =================
class FlyableRobot {
public:
    virtual void fly() = 0;  // Strategy interface
    virtual ~FlyableRobot() {};
};

// Concrete Strategy: Normal flying
class NormalFly: public FlyableRobot {
public:
    void fly() override {
        cout << "Fly normally...." << endl;
    }
};

// Concrete Strategy: Cannot fly
class NoFly: public FlyableRobot {
public:
    void fly() override {
        cout << "Cann't fly!" << endl;
    }
};


// ================= CONTEXT CLASS =================
class Robot {
protected:
    /*
    🧠 These are "HAS-A" relationships (composition)

    Robot does NOT implement behavior itself.
    It delegates behavior to strategy objects.

    This makes behavior interchangeable at runtime.
    */
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour;

public:
    /*
    🧠 Constructor Injection

    Behaviors are injected from outside.
    This keeps Robot flexible and loosely coupled.
    */
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehaviour = w;
        this->talkBehaviour = t;
        this->flyBehaviour = f;
    }

    // Delegation: Robot forwards call to strategy
    void walk() {
        walkBehaviour->walk();
    }

    void talk() {
        talkBehaviour->talk();
    }

    void fly() {
        flyBehaviour->fly();
    }

    /*
    ⚠️ IMPROVEMENT NOTE (important for interviews):
    - Add destructor to avoid memory leaks
    - Or use smart pointers (unique_ptr)

    ~Robot() {
        delete walkBehaviour;
        delete talkBehaviour;
        delete flyBehaviour;
    }
    */

    /*
    ⚠️ EXTENSION:
    Add setters to change behavior dynamically

    void setWalkBehavior(WalkableRobot* w) {
        walkBehaviour = w;
    }
    */

    ~Robot() {
        delete walkBehaviour;
        delete talkBehaviour;
        delete flyBehaviour;
    }
};


// ================= CLIENT CODE =================
int main() {

    /*
    🧠 Companion Robot:
    - Can walk
    - Can talk
    - Cannot fly
    */
    Robot* companianRobot = new Robot(
        new NormalWalk(),
        new NormalTalk(),
        new NoFly()
    );

    cout << "Companian Robot Initialized" << endl;
    companianRobot->walk();
    companianRobot->talk();
    companianRobot->fly();
    
    /*
    🧠 Reconnaissance Robot:
    - Can walk
    - Can talk
    - Can fly
    */
    Robot* reconnaissanceRobot = new Robot(
        new NormalWalk(),
        new NormalTalk(),
        new NormalFly()
    ); 

    cout << "Reconnaissance Robot Initialized" << endl;
    reconnaissanceRobot->walk();
    reconnaissanceRobot->talk();
    reconnaissanceRobot->fly();

    return 0;
}


/*
🎯 FINAL SUMMARY (INTERVIEW READY)

Problem:
Different robots have different capabilities.

Naive approach:
Inheritance → leads to class explosion ❌

Solution:
Strategy Pattern ✔

Key Benefits:
✔ Removes if-else conditions
✔ Promotes reusability
✔ Enables runtime flexibility
✔ Follows SOLID principles (Open/Closed)

Extra Upgrade:
👉 Combine with Factory Pattern to hide object creation
*/