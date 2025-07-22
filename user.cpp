#include "social.h"
#include <iostream>
#include<vector>
using namespace std;
//*************************
// static int userId;     *
// string userName;       *
// string password;       *
// vector<User*> friends; *
// vector<Post*> posts;   *
//*************************

int User::userId = 0;
User::User() : userName(""), password("") {
    userId++;
}

User::User(string username, string password) {
    userId++;
    this->userName = username;
    this->password = password;

}

User::User(const User& other) {
    userId++;
    userName = other.userName;
    password = other.password;
    for(User* mate : other.friends) {
        friends.push_back(mate);
    }
}

int main() {
    int* a = new int();
    *a = 0;
    vector<int*> vec;
    vec.push_back(a);
    cout << vec.at(0) << endl;
    vec.erase(vec.begin());
    cout << *a;
}