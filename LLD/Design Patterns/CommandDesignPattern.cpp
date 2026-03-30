#include<bits/stdc++.h>
using namespace std;

class Command {
public:
    virtual void execute () = 0;
    virtual ~Command() {}
};  

class Light {
public:
    void turnOn() {
        cout << "Light turned ON..." << endl;
    }
    void turnOff() {
        cout << "Light turned OFF..." << endl;
    }
};

class LightOnCommand : public Command{
private:
    Light* light;

public:
    LightOnCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light* light;

public:
    LightOffCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOff();
    }
};

class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    Light* light = new Light();

    Command* onCmd = new LightOnCommand(light);
    Command* offCmd = new LightOffCommand(light);

    RemoteControl remote;
    
    remote.setCommand(onCmd);

    remote.pressButton();

    remote.setCommand(offCmd);

    remote.pressButton();

    return 0;
}