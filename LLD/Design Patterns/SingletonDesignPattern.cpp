#include<bits/stdc++.h>
using namespace std;

class Logger {
private:
    // static Logger* instance;
    Logger() {}

public:
    // static Logger* getInstance() {
    //     if(instance == nullptr) {
    //         instance = new Logger();
    //     }
    //     return instance;
    // }
    static Logger& getInstance() {
        static Logger logger;
        return logger;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

// Logger* Logger::instance = nullptr;

int main() {

    Logger& logger = Logger::getInstance();

    cout << "Code running fine" << endl;

    return 0;
}