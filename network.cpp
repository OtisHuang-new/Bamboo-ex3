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
    
}
void signIn(string name, string pwd);