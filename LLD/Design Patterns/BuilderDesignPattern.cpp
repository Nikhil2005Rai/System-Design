#include<bits/stdc++.h>
using namespace std;

class User {
public:
    string name;
    int age;
    string email;

    void show() {
        cout << "Name: " << name << "\nAge: " << age << "\nEmail: " << email << endl;
    }
};

class UserBuilder {
private:
    User user;

public:
    UserBuilder& setName(string name) {
        user.name = name;
        return *this;
    }

    UserBuilder& setAge(int age) {
        user.age = age;
        return *this;
    }

    UserBuilder& setEmail(string email) {
        user.email = email;
        return *this;
    }

    User build() {
        return user;
    }
};

int main() {

    User user = UserBuilder()
                    .setName("ImNik")
                    .setAge(20)
                    .setEmail("nik@gmail.com")
                    .build();


    user.show();

    return 0;
}