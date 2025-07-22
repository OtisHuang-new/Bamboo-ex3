#include "social.h"
#include "post.cpp"
#include "date.cpp"
//*************************
// static int userId;     *
// string userName;       *
// string password;       *
// vector<User*> friends; *
// vector<Post*> posts;   *
//*************************

int User::userIdCounter = 0;
User::User() : userName(""), password(""), userId(++userIdCounter){}

User::User(string username, string password) {
    this->userId   = ++userIdCounter;
    this->userName = username;
    this->password = password;
}

User::User(const User& other) {
    userId = ++userIdCounter;
    userName = other.userName;
    password = other.password;
    for(User* mate : other.friends) {
        friends.push_back(mate);
    }
}

User::~User(){}

User* User::searchFriend(User* Friend) {
    for (User* mate : getFriendList()) {
        if(Friend == mate) 
            return mate;
    }
    return nullptr;
}
void User::addFriend(User* newFriend) {
    if(searchFriend(newFriend)) {
        cout << "You and " << newFriend->getUserName() << "are already friends.\n";
        return;
    }
    this->friends.push_back(newFriend);
    cout << "You made a new friend.\n";
}
void User::removeFriend(User* aFriend) {
    for(int i = 0; i < getFriendList().size(); i++) {
        User* mate = this->friends.at(i);
        if(mate == aFriend) {
            this->friends.erase(this->friends.begin());
            return;
        }
        cout << "You and " << aFriend->getUserName() << "are not friends.\n";
    }
}
vector<User*> User::getFriendList() const {
    return this->friends;
}
string User::getUserName() const {
    return this->userName;
}
// void User::addPost(Post* newPost);
// void User::removePost(Post* aPost);
// vector<Post*> User::postList() const;
// void getNewsfeed();
int main() {
    User Bamboo;
    User Doikhan(Bamboo);
    cout<<Doikhan.getUserName();
}