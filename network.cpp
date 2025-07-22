#include "social.h"

User* Network::searchUserByUserName(string username) {
    for(int i = 0; i < users.size(); i++) {
        if(username == users.at(i)->getUserName())
            return users.at(i);
    }
    return nullptr;
}
void Network::signUp(string name, string pwd) {
    User* check = searchUserByUserName(name);
    if(check)  {
        cout << "Username chosen. Please choose another username.\n";
        return;
    }
    User* newUser = new User(name,pwd);
    users.push_back(newUser);
    cout<<"Sign up successfully!\n";
}
void Network::signIn(string name, string pwd){
    User* check = searchUserByUserName(name);
    if(!check)  {
        cout << "Sign in unsuccessfully. User not exist!\n";
        return;
    }
    if(check->authorize(name,pwd)){
        currentAccount = check;
        cout<<"Sign in successfully!\n";
    } else {
        cout<<"Sign in successfully. Incorrect!\n";
    }
}

void Network::addFriend(string username) {
    User* friendAccount = searchUserByUserName(username);
    if(!friendAccount) {
        cout<<"Friend not found!"; 
        return;
    }
    currentAccount->addFriend(friendAccount);
}

void Network::removeFriend(string username) {
    User* friendAccount = searchUserByUserName(username);
    if(!friendAccount) {
        cout<<"Friend not found!"; 
        return;
    }
    currentAccount->removeFriend(friendAccount);
}